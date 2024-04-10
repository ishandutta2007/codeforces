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
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
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
typedef vector<int> vec;
typedef vector<string> svec;

void solve() {
	int n; cin >> n;
	ll sup = (ll)1 << 32;
	stack<ll> st;
	stack<ll> mu;
	ll cur = 0;
	bool out = false;
	rep(i, n) {
		string s; cin >> s;
		if (s == "add") {
			cur++;
			if (cur >= sup) {
				out = true;
			}
		}
		else if (s == "for") {
			ll c; cin >> c;
			st.push(cur);
			mu.push(c);
			cur = 0;
		}
		else {
			cur = st.top() + cur * mu.top(); st.pop(); mu.pop();
			if (cur >= sup) {
				out = true;
				//cout << "OVERFLOW!!!" << endl; return;
			}
		}
	}
	if (out)cout << "OVERFLOW!!!" << endl;
	else cout << cur << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n>>h>>m>>s,n)solve();
	solve();
	//stop
	return 0;
}