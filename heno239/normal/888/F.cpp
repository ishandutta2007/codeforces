#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
bool used[2][500][500];
ll ans[2][500][500];
int exi[500][500];
ll dfs(int id, int l, int r) {
	if (used[id][l][r])return ans[id][l][r];
	used[id][l][r] = true;
	if (id==1&&l == r)return ans[id][l][r] = 1;
	ll res=0;
	if (id==0) {
		if (!exi[l][r])res = 0;
		else {
			Rep1(i, l, r-1) {
				res += dfs(1, l, i)*dfs(1, i+1, r); res %= mod;
			}
		}
	}
	else {
		Rep1(i, l+1, r) {
			res += dfs(0, l, i)*dfs(1, i, r); res %= mod;
		}
	}
	return ans[id][l][r] = res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> exi[i][j];
		}
	}
	cout << dfs(1, 0, n - 1) << endl;
	return 0;
}