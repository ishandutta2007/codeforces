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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

int exi[10000001];
int rexi[10000001];
void solve() {
	int n; cin >> n;
	rep(i, n) {
		ll a; cin >> a;
		if (exi[a])rexi[a] = i+1;
		else exi[a] = i + 1;
	}
	ll ans = INF; P out;
	rep1(i, 10000000) {
		vector<LP> memo;
		for (int j = i; j <= 10000000; j += i) {
			if (exi[j]) {
				memo.push_back({ j,exi[j] });
			}
			if (memo.size() == 2)break;
			if (rexi[j]) {
				memo.push_back({ j,rexi[j] });
			}
			if (memo.size() == 2)break;
		}
		if (memo.size() < 2)continue;
		ll pro = memo[0].first*memo[1].first / i;
		if (pro < ans) {
			ans = pro; out = { memo[0].second,memo[1].second };
		}
	}
	if (out.first > out.second)swap(out.first, out.second);
	cout << out.first << " " << out.second << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}