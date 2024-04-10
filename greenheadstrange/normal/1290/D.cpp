#include <bits/stdc++.h>
#define ll long long
#define maxn 3005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
bool fl[maxn];
const int test = 0;
int cnt = 0;
void ask (vi g) {
	sort(g.begin(), g.end());
	if (test) {
		cnt += g.size();
		return;
	}
	cout << "R" << endl;
	fflush(stdout);
	for (auto v : g) {
		cout << "? " << v << endl;
		fflush(stdout);
		char inp[10];
		scanf("%s", inp);
		if (inp[0] == 'Y') fl[v] = 0;
		else if (inp[0] == 'E') exit(1);
	}
/*	cout << "R" << endl;
	fflush(stdout);
*/
} 
bool ch[maxn][maxn];
vector<vi> rs;
int cn[maxn];
vi r;	
int n, k;
int ds;
void dfs(int a) {
	r.pb(a);
	if (cn[a]) return ;
	for (int j = a + 1; j < ds; j++)
		if (!ch[a][j]) {
			dfs(j);
			ch[a][j] = 1;
			return ;
		}
	cn[a] = 1;
}
int main() {

	cin >> n >> k;
	assert(k <= n);
	assert((n & (-n)) == n);
	assert((k & (-k)) == k);
	if (test) cout << "MAX" << (3 * n * n / k) / 2 << endl;
	vi rs;
	for (int i = 1; i <= n; i++)
		fl[i] = 1, rs.pb(i);
/*	if (k == n) 
		ask(rs);
	else*/
	 if (k == 1) {
		for (int j = 1; j <= n; j++)
			for (int r = j + 1; r <= n; r++) {
				vi us;
				us.pb(j), us.pb(r);
				ask(us);
			}
	}
	else {
		int l = k / 2;
		ds = n / l;
		vector<vi> gg(ds);
		for (int i = 0; i < ds; i++)
			for (int j = 1; j <= l; j++)
				gg[i].pb(i * l + j);
		for (int i = 0; i < ds; i++) {
			while (!cn[i]) {
				r.clear(), 
				dfs(i);
			//	if (r.size() == 1) break;
				vi cur;
				for (int i = 0; i < r.size(); i++)
					for (auto v : gg[r[i]])
						cur.pb(v);
				ask(cur);
			}
		}
	}
	if (test) {
		cout << cnt << endl;
		return 0;
	}
	cout << "! ";
	int tot = 0;
	for (int i = 1; i <= n; i++)
		if (fl[i]) tot++;
	cout << tot << endl;
	fflush(stdout);
	return 0;
}