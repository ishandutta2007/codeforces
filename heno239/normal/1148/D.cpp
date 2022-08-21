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

typedef long long  ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000003;
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

typedef pair<P, int> speP;
bool comp(speP a, speP b) {
	P la = a.first, lb = b.first;
	if (la.second != lb.second)return la.second < lb.second;
	if (la.first != lb.first)return la.first < lb.first;
	return a.second < b.second;
}
void solve() {
	int n; cin >> n;
	vector<P> v(n);
	rep(i, n)cin >> v[i].first >> v[i].second;
	vector<speP> le,ri;
	rep(i, n) {
		if (v[i].first > v[i].second) {
			le.push_back({ v[i],i });
		}
		else {
			ri.push_back({ v[i],i });
		}
	}
	if (le.size() >= ri.size()) {
		sort(le.begin(), le.end());
		cout << le.size() << endl;
		rep(i, le.size()) {
			if (i > 0)cout << " ";
			cout << le[i].second+1;
		}
		cout << endl;
	}
	else {
		sort(ri.begin(), ri.end(), comp);
		cout << ri.size() << endl;
		per(i, (int)ri.size()) {
			if (i < (int)ri.size()-1)cout << " ";
			cout << ri[i].second + 1;
		}
		cout << endl;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n)solve();
	solve();
	//stop
	return 0;
}