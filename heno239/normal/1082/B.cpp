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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
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
typedef pair<ld, ld> LDP;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; string s; cin >> n >> s;
	vector<P> v;
	int cg = 0;
	rep(i,n){
		int c = 1;
		while (i + 1 < n&&s[i + 1] == s[i]) {
			i++; c++;
		}
		int t = (s[i] == 'G');
		v.push_back({ c,t });
		if (t)cg += c;
	}
	int ans = 0;
	rep(i, v.size()) {
		if (v[i].second == 0&&v[i].first==1&&i>0&&i<v.size()-1) {
			ans = max(ans, v[i - 1].first + v[i + 1].first);
			if (v[i - 1].first + v[i + 1].first != cg) {
				ans = max(ans, v[i - 1].first + 1 + v[i + 1].first);
			}
		}
		else if(v[i].second==1){
			ans = max(ans, v[i].first);
			if (v[i].first != cg) {
				ans = max(ans, v[i].first + 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}