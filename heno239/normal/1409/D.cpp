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
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);


void solve() {
	string n; int s; cin >> n >> s;
	while (n.size() < 20)n.insert(n.begin(), '0');
	int sum = 0;
	rep(i, 20)sum += n[i] - '0';
	if (sum <= s) {
		cout << 0 << "\n"; return;
	}
	per(i,20) {
		int rest = 19 - i;
		int c = n[i] - '0';
		sum = 0;
		rep(j, i)sum += n[j] - '0';
		for (int t = c + 1; t < 10; t++) {
			int le = sum + t;
			int ri = sum + t + 9 * rest;
			if (le <= s) {
				sum += t;
				string ans = n;
				ans[i] = '0' + t;
				ans.resize(i + 1);
				rep(j, rest) {
					int r = rest - 1 - j;
					rep(x, 10) {
						le = sum + x;
						ri = sum + x + 9 * r;
						if (le <= s) {
							ans.push_back('0' + x);
							sum += x;
							break;
						}
					}
				}
				while (ans[0] == '0')ans.erase(ans.begin());
				ll dif = stoll(ans) - stoll(n);
				cout << dif << "\n";
				return;
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}