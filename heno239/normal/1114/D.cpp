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
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int num[5001];
int n, c[5000];
vector<int> v;

bool used[5000][5000];
int ans[5000][5000];
int dfs(int le, int ri) {
	if (le > ri)return 0;
	if (used[le][ri])return ans[le][ri];
	used[le][ri] = true;
	int res = mod;
	if (v[le] == v[ri]) {
		res = min(res, dfs(le + 1, ri - 1) + 1);
	}
	res = min(res, dfs(le + 1, ri) + 1);
	res = min(res, dfs(le, ri - 1) + 1);
	return ans[le][ri]=res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> c[i]; 
	}
	int k = 0;
	rep(i, n) {
		while (i + 1 < n&&c[i] == c[i + 1]) {
			i++;
		}
		v.push_back(c[i]);
	}
	cout << dfs(0, v.size() - 1)-1 << endl;
	//stop
	return 0;
}