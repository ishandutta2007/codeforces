#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct th {
	int r[5], fl;
	th() {memset(r, 0, sizeof(r)); fl = 1;}
	bool operator < (const th &u)const {
		for (int j = 0; j < 5; j++)
			if (r[j] != u.r[j]) return r[j] < u.r[j];
		return 0;
	}
	void ins(int a) {
		for (int i = 4; i >= 0; i--) {
			if (a & (1 << i)) 
				if (r[i]) a ^= r[i];
		}
		if (!a) fl = 0;
		for (int i = 4; i >= 0; i--) {
			if (a & (1 << i)) {
				r[i] = a;
				for (int j = i + 1; j <= 4; j++)
					if (r[j] & (1 << i))
						r[j] ^= a;
				return ;
			}
		}
	}
	void ins(th &a) {
		for (int i = 4; i >= 0; i--)
			if (a.r[i]) ins(a.r[i]);
		if (!a.fl) fl = 0;
	}
	void otp() {
		for (int i = 0; i < 5; i++)
			cout << r[i] << ' ';
		cout << fl << endl;
	}
};
th cur[maxn];
int us[maxn];
int vis[maxn];

vector<pi> eg[maxn];
int fl[maxn];
int dep[maxn], dd[maxn], b[maxn], fr[maxn];

void dfs(int a, int fa, int bl) {
	fr[a] = fa, b[a] = bl;
//	cout << "DFS" << a << ' ' << fa << endl;
	for (auto v : eg[a]) {
		if (fl[v.fi] && fl[a]) continue;
		if (v.fi == fa) continue;
		if (dd[v.fi]) 
			continue; 
		dd[v.fi] = dd[a] + 1;
		dep[v.fi] = dep[a] ^ v.se;
		dfs(v.fi, a, bl);
	}
}
int bg[17][9][5][3][2];
th tr[maxn];
int cal(th r) {
	int s[5] = {0, 0, 0, 0, 0};
	for (int i = 4; i >= 0; i--)
		if (r.r[i]) s[i] = r.r[i] - (1 << i) + 1;
		else s[i] = 0;
	return bg[s[4]][s[3]][s[2]][s[1]][s[0]];
}
map<th, int> id;
int idcnt = 0;
void init() {
	for (int i = 16; i >= 0; i--)
		for (int j = 8; j >= 0; j--)
			for (int k = 4; k >= 0; k--)
				for (int m = 2; m >= 0; m--)
					for (int l = 1; l >= 0; l--) {
						th cur;
						if (i) cur.ins(i + 16 - 1);
						if (j) cur.ins(j + 8 - 1);
						if (k) cur.ins(k + 4 - 1);
						if (m) cur.ins(m + 2 - 1);
						if (l) cur.ins(l + 1 - 1);
						if (!id[cur]) {
							id[cur] = ++idcnt;
							tr[idcnt] = cur;
						}
						bg[i][j][k][m][l] = id[cur];
					}
}
th uu[maxn];
int nlp[maxn];
int dp[maxn][405];
int cnt = 0;

int u[maxn], v[maxn], w[maxn];
int main() {
//	freopen("1.in", "r", stdin);
	init();
	int test = 0;
	
	int n, m;
	if (test) n = 100000, m = 99999;
	else scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		eg[u[i]].pb(mp(v[i], w[i]));
		eg[v[i]].pb(mp(u[i], w[i]));
	} 
	for (auto v : eg[1])
		fl[v.fi] = 1;
	for (auto v : eg[1]) 
		dep[v.fi] = v.se, 
		dd[v.fi] = 1,  
		dfs(v.fi, 1, v.fi);
	//	cur[v.fi].otp();
	for (int i = 0; i < m; i++)
		if (b[u[i]] == b[v[i]] && u[i] != fr[v[i]] && v[i] != fr[u[i]])
			cur[b[u[i]]].ins(dep[u[i]] ^ dep[v[i]] ^ w[i]);
	memset(vis, 0, sizeof(vis));

	for (auto v : eg[1]) {
		if (vis[v.fi]) continue;
		vis[v.fi] = 1;
		nlp[cnt] = -1;
		uu[cnt] = cur[v.fi];
		
		for (auto g : eg[v.fi]) 
			if (fl[g.fi]) {
				vis[g.fi] = 1;
				nlp[cnt] = dep[v.fi] ^ dep[g.fi] ^ g.se;
				uu[cnt].ins(cur[g.fi]);
			}
		cnt++;
	}
	for (int a = cnt; a >= 0; a--)
		for (int r = 1; r <= idcnt; r++) {
			if (a == cnt) {
				dp[a][r] = 1;
				continue;
			}
			ll cans = dp[a + 1][r];
			if (nlp[a] == -1) {
				th ur = tr[r];
				ur.ins(uu[a]);
				if (ur.fl)
					cans += dp[a + 1][cal(ur)], cans %= mod;
			}
			else {
				th ur = tr[r];
				ur.ins(uu[a]);
				if (ur.fl)
					cans += 2 * dp[a + 1][cal(ur)], cans %= mod;
				ur.ins(nlp[a]);
				if (ur.fl)
					cans += dp[a + 1][cal(ur)], cans %= mod;
			}
			dp[a][r] = cans % mod;
		}
	if (test) cout << ksm(2, 99999) << endl;
	cout << dp[0][idcnt] << endl;
//	cout << work(0, th()) << endl;
	return 0;
}