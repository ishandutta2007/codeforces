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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void solve() {
	int n; ll p; cin >> n >> p;
	vector<int> t(n);
	rep(i, n) {
		cin >> t[i];
	}
	vector<P> v;
	rep(i, n)v.push_back({ t[i],i });
	sort(v.begin(), v.end());
	set<int> st;
	set<int> bl;
	ll cur = 0;
	vector<ll> ans(n);
	queue<int> q;
	int loc = 0;
	while (true) {
		while (loc < n&&v[loc].first == cur) {
			st.insert(v[loc].second);
			loc++;
			/*if (bl.empty() || *bl.begin() > v[loc].second) {
				bl.insert(v[loc].second);
				q.push(v[loc].second);
			}
			else {
				st.insert(v[loc].second);
			}
			loc++;*/
		}
		if (st.size()) {
			int fr = *st.begin();
			if (bl.empty() || *bl.begin() > fr) {
				bl.insert(fr);
				q.push(fr);
				st.erase(st.begin());
			}
		}
		int id;
		if (q.size()) {
			id = q.front(); q.pop();
			//cout << "!! " << id << endl;
		}
		else {
			if (st.empty()) {
				if (loc == n)break;
				cur = v[loc].first;
				st.insert(v[loc].second);
				loc++;
				while (loc < n&&v[loc].first == v[loc - 1].first) {
					st.insert(v[loc].second);
					loc++;
				}
			}
			id = *st.begin();
			st.erase(st.begin());
			//cout << "?? " << id << endl;
		}
		//cout << "hello "<<id << endl;
		cur += p;
		ans[id] = cur;
		bl.insert(id);
		while (loc < n&&v[loc].first < cur) {
			if (bl.empty() || *bl.begin() > v[loc].second) {
				bl.insert(v[loc].second);
				q.push(v[loc].second);
			}
			else {
				st.insert(v[loc].second);
			}
			loc++;
		}
		bl.erase(id);
		/*if (st.size()) {
			int fr = *st.begin();
			if (bl.empty() || *bl.begin() > fr) {
				bl.insert(fr);
				q.push(fr);
				st.erase(st.begin());
			}
		}*/
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}