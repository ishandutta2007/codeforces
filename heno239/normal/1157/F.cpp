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
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

const int sz = 200001;
int c[sz];

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		c[a[i]]++;
	}
	int ans = 1;
	rep(i, sz) {
		if (c[i] < 2)continue;
		int sum = c[i];
		int le = i;
		while (i + 1 < sz&&c[i + 1] >= 2) {
			i++;
			sum += c[i];
		}
		if (le > 0 && c[le - 1] > 0)sum++;
		if (i + 1 < sz&&c[i + 1] > 0)sum++;
		ans = max(ans, sum);
	}
	rep(i, sz - 1) {
		if (c[i] > 0 && c[i + 1] > 0) {
			if (ans < 2) {
				cout << 2 << endl;
				cout << i << " " << i+1 << endl;
				return;
			}
		}
	}
	cout << ans << endl;
	if (ans == 1) {
		cout << a[0] << endl; return;
	}
	rep(i, sz) {
		if (c[i] < 2)continue;
		int sum = c[i];
		int le = i;
		while (i + 1 < sz&&c[i + 1] >= 2) {
			i++;
			sum += c[i];
		}
		if (le > 0 && c[le - 1] > 0)sum++;
		if (i + 1 < sz&&c[i + 1] > 0)sum++;
		if (ans == sum) {
			vector<int> v;
			if (le > 0 && c[le - 1] > 0)v.push_back(le-1);
			for (int j = le; j <= i; j++) {
				rep(k, c[j]-1) {
					v.push_back(j);
				}
			}
			if (i + 1 < sz&&c[i + 1] > 0)v.push_back(i+1);
			for (int j = i; j >= le; j--)v.push_back(j);
			rep(j, ans) {
				if (j > 0)cout << " ";
				cout << v[j];
			}
			cout << endl;
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	string l = to_string(2), r = to_string(1);
	//cout << dec(l,r) << endl;
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}