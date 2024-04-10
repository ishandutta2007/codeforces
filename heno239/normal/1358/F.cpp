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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
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
const ld pi = acos(-1.0);

void solve() {
	int n; cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];


	if (n == 1) {
		if (a[0] == b[0]) {
			cout << "SMALL\n";
			cout << 0 << "\n";
			cout << "\n";
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
		return;
	}
	else if (n == 2) {
		vector<pair<char, ll>> vc;
		while (true) {
			if (a == b)break;
			if (a[0] == b[1] && a[1] == b[0]) {
				vc.push_back({ 'R',1 });
				reverse(all(b));
				break;
			}
			if (min(b[0], b[1]) < min(a[0], a[1])) {
				cout << "IMPOSSIBLE\n"; return;
			}
			if (b[0] == b[1]) {
				cout << "IMPOSSIBLE\n"; return;
			}
			if (b[0] > b[1]) {
				vc.push_back({ 'R', 1 });
				reverse(all(b));
			}
			if (min(a[0], a[1]) == b[0]) {
				ll dif = b[1] - max(a[0], a[1]);
				if (dif%b[0] == 0) {
					vc.push_back({ 'P',dif / b[0] });
					b[1] = max(a[0], a[1]);
					if (a[0] != b[0]) {
						vc.push_back({ 'R',1 });
						reverse(all(b));
					}
					break;
				}
				else {
					cout << "IMPOSSIBLE\n";
					return;
				}
			}
			else {
				vc.push_back({ 'P',b[1] / b[0] });
				b[1] %= b[0];
			}
		}
		if (a == b) {
			reverse(all(vc));
			ll num = 0;
			rep(i, vc.size())if(vc[i].first=='P')num += vc[i].second;
			if (num <= 200000) {
				string ans;
				rep(i, vc.size())rep(j, vc[i].second)ans.push_back(vc[i].first);
				cout << "SMALL\n";
				cout << ans.size() << "\n";
				cout << ans << "\n";
			}
			else {
				cout << "BIG\n";
				cout << num << "\n";
			}
		}
		else {
			cout << "IMPOSSIBLE\n";
		}


		return;
	}
	string ans;
	while (true) {
		bool valid = true;
		bool rvalid = true;
		bool fin = false;
		rep(i, n){
			if (a[i] != b[i]) {
				valid = false;
			}
			if (a[i] != b[n - 1 - i]) {
				rvalid = false;
			}
			if (min(b[i], b[n - 1 - i]) < min(a[i], a[n - 1 - i])) {
				fin = true;
			}
		}
		if (valid) {
			break;
		}
		else if (rvalid) {
			ans.push_back('R');
			reverse(all(b));
			break;
		}
		else if(fin){
			break;
		}
		bool isinc = true;
		bool isdec = true;
		rep(i, n - 1) {
			if (b[i] >= b[i + 1])isinc = false;
			if (b[i] <= b[i + 1])isdec = false;
		}
		if (!isinc && !isdec) {
			cout << "IMPOSSIBLE\n"; return;
		}
		if (isinc) {
			ans.push_back('P');
			per(i, n) {
				if (i > 0)b[i] -= b[i - 1];
			}
		}
		else if (isdec) {
			ans.push_back('R');
			ans.push_back('P');
			reverse(all(b));
			per(i, n) {
				if (i > 0)b[i] -= b[i - 1];
			}
		}
	}
	reverse(all(ans));
	if (a == b) {
		int cp = 0;
		rep(i, ans.size())if (ans[i] == 'P')cp++;
		if (cp > 200000) {
			cout << "BIG\n";
			cout << cp << "\n";
			return;
		}
		cout << "SMALL\n";
		cout << ans.size() << "\n";
		cout << ans << "\n";
	}
	else {
		cout << "IMPOSSIBLE\n"; return;
	}
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	solve();
	stop
		return 0;
}