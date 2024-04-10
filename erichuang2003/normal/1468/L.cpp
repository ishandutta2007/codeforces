//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll mul(ll a, ll b, ll c) {
	ll ans = a * b - c * (ll)(((long double)a) * b / c);
	if (ans < 0) ans += c;
	return ans;
}
#define L __int128
L ksm(ll a, ll b) {
   if (!b) return 1;
   L ns = ksm(a, b >> 1);
   ns = ns * ns;
   if (b & 1) ns = ns * a;
   return ns;
}
const int S = 5e4 + 5;
bool bpr[S];
int prs[S], prcnt = 0;
bool chk(int a) {
	if (a == 1) return 0;
	for (int i = 0; i < prcnt; i++) {
		if (a == prs[i]) return 1;
		if (a % prs[i] == 0) return 0;
	}
	return 1;
}
vi dr[maxn];
vi pure[maxn];
bool fl[maxn];
ll x[maxn];
int main() {
	for (int i = 0; i < S; i++)
		bpr[i] = 1;
	for (int i = 2; i < S; i++)
		if (bpr[i]) {
			prs[prcnt++] = i;
			for (int j = i; j < S; j += i)
				bpr[j] = 0;
		}
	int n, k;
	cin >> n >> k;
	vi d;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= n; i++) {
		// 
		for (int j = 1; j <= 60; j++) {
			int cr = pow(x[i], 1.0 / j);
			if (j == 1 && x[i] > 1e9) continue;
			while (ksm(cr + 1, j) <= x[i]) cr++;
			while (ksm(cr - 1, j) >= x[i]) cr--;
			int cu = -1;
			if (ksm(cr, j) == x[i]) cu = cr;
			if (cu < 0) continue;
			if (!chk(cu)) continue;
			else 
				d.pb(cu);
		} 
	}	
	sort(d.begin(), d.end());
	vi nd;
	for (int i = 0; i < d.size(); ) {
		int j = i;
		while (j < d.size() && d[j] == d[i]) j++;
		if (j >= i + 2) nd.pb(d[i]);
		i = j;
	}
	d = nd;	
	for (int i = 1; i <= n; i++) {
		ll cur = x[i];
		for (int j = 0; j < d.size(); j++) {
			ll v = d[j];
			bool flag = 0;
			while (cur % v == 0) 
				cur /= v, flag = 1;
			if (flag) dr[i].pb(j);
		}
		if (cur != 1) dr[i].clear();
		if (dr[i].size() == 1) pure[dr[i][0]].pb(i);
	}
	for (int i = 0; i < d.size(); i++)
		assert(pure[i].size() >= 2);
	int ans = 1;
	if (k >= 2 * d.size()) {
		for (int i = 0; i < d.size(); i++)
			for (int j = 0; j < 2; j++)
				fl[pure[i][j]] = 1;
		int nd = k - 2 * d.size();
		for (int i = 1; i <= n; i++)
			if (fl[i]) continue;
			else if (dr[i].size() && nd)
				fl[i] = 1, nd--;
		if (nd) ans = 0; 
	}
	else {
		if (k % 2 == 0) 
			for (int i = 0; i < k / 2; i++)
				for (int j = 0; j < 2; j++)
					fl[pure[i][j]] = 1; 
		else {
			int pl = 0, mn = 1e9;
			for (int i = 1; i <= n; i++) {
				if (dr[i].size() == 0) continue;
				else if (dr[i].size() == 1) {
					int v = dr[i][0];
					if (i == pure[v][0] || i == pure[v][1]) continue;
				}
				if (chkmin(mn, (int)dr[i].size())) 
					pl = i;
			}
			if (k < 2 * mn + 1) ans = 0;
			else {
				for (auto v : dr[pl])
					fl[pure[v][0]] = fl[pure[v][1]] = 1;
				fl[pl] = 1; 
				int nd = k - (2 * mn + 1);
				for (int i = 0; i < d.size(); i++)
					if (fl[pure[i][0]]) continue;
					else if (nd) {
						nd -= 2;
						fl[pure[i][0]] = fl[pure[i][1]] = 1;
					}
			}
		}
	}
	if (!ans) cout << 0 << endl;
	else {
		for (int i = 1; i <= n; i++)
			if (fl[i]) cout << x[i] << ' ';
		cout << endl;
	}
		
	
	return 0;
}