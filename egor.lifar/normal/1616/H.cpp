#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x), sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool chkmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool chkmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}


const int MAXN = 150228;
const int MAXM = 5000229;
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}

int n, k;
int nxt[MAXM][2];
int cnt[MAXM];
int a[MAXM];
int uk = 0;


void add(int val) {
	int cur = 0;
	for (int i = 29; i >= 0; i--) {
		int c = 0;
		if (val & (1 << i)) {
			c = 1;
		}
		if (nxt[cur][c]) {
			cur = nxt[cur][c];
		} else {
			uk++;
			nxt[cur][c] = uk;
			cur = uk;
		}
	}
	cnt[cur]++;
}



bool special[3001];
int step[MAXM];



int calc(int u, int u1, int deep = 29) {
	if (deep == -1) {
		if (u == u1) {
			return sum((u != 0 ? step[cnt[u]]: 1), Mod - 1);
		}
		return mul((u != 0 ? step[cnt[u]]: 1) + Mod - 1, (u1 != 0 ? step[cnt[u1]]: 1) + Mod - 1);
	}
	if (!special[deep]) {
		int f = (nxt[u][0] && nxt[u1][0] ? calc(nxt[u][0], nxt[u1][0], deep - 1): 0);
		int f1 = (nxt[u][1] && nxt[u1][1] ? calc(nxt[u][1], nxt[u1][1], deep - 1): 0);
		return sum(f, f1);
	}
	int fku0 = (nxt[u][0] ? step[cnt[nxt[u][0]]]: 1);
	int fku10 = (nxt[u1][0] ? step[cnt[nxt[u1][0]]]: 1);
	int fku1 = (nxt[u][1] ? step[cnt[nxt[u][1]]]: 1);
	int fku11 = (nxt[u1][1] ? step[cnt[nxt[u1][1]]]: 1);
	int rd = (nxt[u][0] && nxt[u1][1] ? calc(nxt[u][0], nxt[u1][1], deep - 1): 0);
	int rd1 = (nxt[u][1] && nxt[u1][0] && u != u1 ? calc(nxt[u][1], nxt[u1][0], deep - 1): 0);
	int ans = 0;
	if (u == u1) {
		//cout << deep << ' ' << fku0 << ' ' << fku1 << endl;
		ans = sum(ans, sum(rd, sum(fku0 - 1, fku1 - 1)));
	} else {
		ans = sum(ans, mul(sum(rd, sum(fku0 - 1, fku11 - 1)), sum(rd1, sum(fku1 - 1, fku10 - 1))));
		ans = sum(ans, sum(rd, rd1));
		ans = sum(ans, Mod - mul(fku0 - 1, fku1 - 1));
		ans = sum(ans, Mod - mul(fku10 - 1, fku11 - 1));
	}
	ans %= Mod;

	if (ans < 0) {
		ans += Mod;
	}
	return ans;
}

// max(calc(nxt[u][0], nxt[u1][1], deep - 1), 
// 	max((nxt[u][0] ? cnt[nxt[u][0]]: 0), (nxt[u1][1] ? cnt[nxt[u1][1]]: 0)))  
		
// 	max(calc(nxt[u][1], nxt[u1][0], deep - 1), 
// 		max((nxt[u][1] ? cnt[nxt[u][1]]: 0), (nxt[u1][0] ? cnt[nxt[u1][0]]: 0))): 0 );

 
void solve() {
	uk = 0;
	memset(special, 0, sizeof(special));
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		add(a[i]);
	}
	step[0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		step[i] = sum(step[i - 1], step[i - 1]);
	}
	for (int i = 29; i >= 0; i--) {
		if (k & (1 << i)) {
			special[i] = true;
		}
	}
	for (int i = uk; i >= 0; i--) {
		cnt[i] += (nxt[i][0] ? cnt[nxt[i][0]]: 0) + (nxt[i][1] ? cnt[nxt[i][1]]: 0);
	}
	int ans = calc(0, 0);
	if (ans < 0) {
		ans += Mod;
	}
	cout << ans << '\n';
	for (int i = 0; i <= uk; i++) {
		nxt[i][0] = nxt[i][1] = 0;
		cnt[i] = 0;
	}
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}