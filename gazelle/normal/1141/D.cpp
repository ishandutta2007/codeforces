#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<pint> process(vector<pint>& v) {
	vector<pint> ret;
	REP(i, v.size()) swap(v[i].first, v[i].second);
	sort(ALL(v));
	REP(i, v.size()) swap(v[i].first, v[i].second);
	int idx = -1;
	REP(i, v.size()) {
		if(idx < v[i].first) {
			ret.pb(v[i]);
			idx = v[i].second;
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	string l, r;
	cin >> l >> r;
	vector<queue<int>> v1(27), v2(27);
	REP(i, n) {
		if(l[i] == '?') v1[26].push(i);
		else v1[l[i] - 'a'].push(i);
		if(r[i] == '?') v2[26].push(i);
		else v2[r[i] - 'a'].push(i);
	}
	vector<bool> usd1(n, false), usd2(n, false);
	vector<pint> ans;
	REP(i, n) {
		if(l[i] == '?') continue;
		if(!v2[l[i] - 'a'].empty()) {
			ans.pb({i, v2[l[i] - 'a'].front()});
			usd1[i] = true;
			usd2[v2[l[i] - 'a'].front()] = true;
			v2[l[i] - 'a'].pop();
		} else if(!v2[26].empty()) {
			ans.pb({i, v2[26].front()});
			usd1[i] = true;
			usd2[v2[26].front()] = true;
			v2[26].pop();
		}
	}
	REP(i, n) {
		if(usd2[i] || r[i] == '?') continue;
		while(!v1[r[i] - 'a'].empty() && usd1[v1[r[i] - 'a'].front()]) {
			v1[r[i] - 'a'].pop();
		}
		while(!v1[26].empty() && usd1[v1[26].front()]) {
			v1[26].pop();
		}
		if(!v1[r[i] - 'a'].empty()) {
			ans.pb({v1[r[i] - 'a'].front(), i});
			usd2[i] = true;
			usd1[v1[r[i] - 'a'].front()] = true;
			v1[r[i] - 'a'].pop();
		} else if(!v1[26].empty()) {
			ans.pb({v1[26].front(), i});
			usd2[i] = true;
			usd1[v1[26].front()] = true;
			v1[26].pop();
		}
	}
	REP(i, n) {
		while(!v2[26].empty() && usd2[v2[26].front()]) {
			v2[26].pop();
		}
		if(!usd1[i] && l[i] == '?') {
			if(!v2[26].empty()) {
				ans.pb({i, v2[26].front()});
				v2[26].pop();
			}
		}
	}
	cout << (int)ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
	return 0;
}

/* --------------------------------------- */