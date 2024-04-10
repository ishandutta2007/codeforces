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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

ll query1(int i, int j, int k) {
	cout << "1 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	ll res; cin >> res; return res;
}
bool query2(int i, int j, int k) {
	cout << "2 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	int res; cin >> res;
	return (res == 1);
}
ll pot[1000];
void solve() {
	int n; cin >> n;
	vector<int> le, ri;
	Rep(i, 2, n) {
		if (query2(0, 1, i))le.push_back(i);
		else ri.push_back(i);
	}
	vector<int> ansle, ansri;
	if (ri.size()) {
		vector<LP> zri;
		rep(i, ri.size()) {
			int id = ri[i];
			ll u = query1(0, 1, id);
			zri.push_back({ u,id });
			pot[id] = u;
		}
		sort(zri.begin(), zri.end());
		int len = zri.size();
		int m1, m2;
		if (zri.size() >= 2 && zri.back().first == zri[zri.size() - 2].first) {
			int id = zri[len - 2].second;
			int id2 = zri[len - 1].second;
			if (query2(0, id, id2)) {
				m1 = id, m2 = id2;
			}
			else {
				m1 = id2, m2 = id;
			}
			
		}
		else {
			m1 = m2=zri.back().second;
		}
		vector<LP> l, r;
		rep(j, ri.size()) {
			int id = ri[j];
			if (id == m1 || id == m2)continue;
			if (query2(0, m1, id)) {
				l.push_back({ pot[id],id });
			}
			else {
				r.push_back({ pot[id],id });
			}
		}
		sort(r.begin(), r.end());
		rep(j, r.size()) {
			ansri.push_back(r[j].second);
		}
		ansri.push_back(m1);
		if (m1 != m2)ansri.push_back(m2);
		sort(l.begin(), l.end(), greater<LP>());
		rep(j, (int)l.size()) {
			ansri.push_back(l[j].second);
		}
	}
	if (le.size()) {
		vector<LP> zle;
		rep(i, le.size()) {
			int id = le[i];
			ll u = query1(1, 0, id);
			zle.push_back({ u,id });
			pot[id] = u;
		}
		sort(zle.begin(), zle.end());
		int len = zle.size();
		int m1, m2;
		if (zle.size() >= 2 && zle.back().first == zle[zle.size() - 2].first) {
			int id = zle[len - 2].second;
			int id2 = zle[len - 1].second;
			if (query2(1, id, id2)) {
				m1 = id, m2 = id2;
			}
			else {
				m1 = id2, m2 = id;
			}

		}
		else {
			m1 = m2 = zle.back().second;
		}
		vector<LP> l, r;
		rep(j, le.size()) {
			int id = le[j];
			if (id == m1 || id == m2)continue;
			if (query2(1, m1, id)) {
				l.push_back({ pot[id],id });
			}
			else {
				r.push_back({ pot[id],id });
			}
		}
		sort(r.begin(), r.end());
		rep(j, r.size()) {
			ansle.push_back(r[j].second);
		}
		ansle.push_back(m1);
		if (m1 != m2)ansle.push_back(m2);
		sort(l.begin(), l.end(), greater<LP>());
		rep(j, (int)l.size()) {
			ansle.push_back(l[j].second);
		}
	}
	vector<int> ans;
	ans.push_back(0);
	rep(j, ansri.size()) {
		ans.push_back(ansri[j]);
	}
	ans.push_back(1);
	rep(j, ansle.size()) {
		ans.push_back(ansle[j]);
	}
	cout << 0;
	rep(i, n) {
		cout <<" "<< ans[i] + 1;
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	//init();
	solve();
	//stop
		return 0;
}