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

struct query {
	int l, r; ll d;
};
void solve() {
	int n; cin >> n;
	vector<ll> s(n), t(n);
	rep(i, n) {
		cin >> s[i];
	}
	rep(i, n)cin >> t[i];
	{
		ll sum = 0;
		rep(i, n)sum += s[i] - t[i];
		if (sum != 0) {
			cout << "NO" << endl; return;
		}
	}
	vector<LP> a;
	rep(i, n)a.push_back({ s[i],i });
	sort(a.begin(), a.end());
	sort(t.begin(), t.end());
	vector<query> ans;
	stack<LP> st;
	per(i, n) {
		ll dif = a[i].first - t[i];
		if (dif < 0) {
			while (!st.empty()) {
				LP p = st.top(); st.pop();
				ll dm = min(-dif, p.first);
				ans.push_back({ (int)a[i].second + 1,(int)p.second + 1,dm });
				dif += dm; p.first -= dm;
				if (p.first > 0)st.push(p);
				if (dif == 0)break;
			}
			if (dif < 0) {
				cout << "NO" << endl; return;
			}
		}
		else if (dif > 0) {
			st.push({ dif,a[i].second });
		}
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].l << " " << ans[i].r << " " << ans[i].d << endl;
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