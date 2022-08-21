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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;


void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << "YES" << endl;
		cout << "1 2" << endl;
	}
	else if (n == 2) {
		cout << "NO" << endl;
	}
	else if (n == 3) {
		cout << "YES" << endl;
		cout << "1 4 5 2 3 6" << endl;
	}
	else {
		if (n % 2 == 0) {
			cout << "NO" << endl;
		}
		else {
			vector<int> ans;
			cout << "YES" << endl;
			rep1(i, n) {
				int id = 2 * i;
				if (i % 2)id--;
				ans.push_back(id);
			}
			rep1(i, n) {
				int id = 2 * i;
				if (i % 2 == 0)id--;
				ans.push_back(id);
			}
			rep(i, 2*n) {
				if (i > 0)cout << " ";
				cout << ans[i];
			}
			cout << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}