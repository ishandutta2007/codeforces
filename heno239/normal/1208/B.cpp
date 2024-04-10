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
const ll mod = 1000000007;
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;

bool used[2000];
void solve(){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	{
		bool f = true;
		rep(i, n) {
			Rep(j, i + 1, n) {
				if (a[i] == a[j]) {
					f = false;
				}
			}
		}
		if (f) {
			cout << 0 << endl; return;
		}
	}
	vector<int> x;
	rep(i, n) {
		x.push_back(a[i]);
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	map<int, int> mp;
	rep(i, x.size())mp[x[i]] = i;
	rep(i, n) {
		a[i] = mp[a[i]];
	}
	int ans = n;
	rep(i, n) {
		fill(used, used + x.size(), false);
		bool valid = true;
		rep(j, i) {
			if (used[a[j]]) {
				valid = false; break;
			}
			else {
				used[a[j]] = true;
			}
		}
		if (!valid)break;
		int cur = n - 1;
		while (!used[a[cur]]) {
			used[a[cur]] = true; cur--;
		}
		ans = min(ans, cur - i + 1);
	}
	cout << ans << endl;
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