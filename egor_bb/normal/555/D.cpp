#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;

using namespace std;




ll n, m, ans[200005];
vector <pll> d;
set <pll> s;
vector <ll> dd;

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	cin >> n >> m;
	d.resize(n);
	for (int i = 0; i < n; i++){
		cin >> d[i].first;
		d[i].second = i;
	}
	for (int i = 0; i < m; i++){
		ll t1, t2;	cin >> t1 >> t2;
		s.insert(mp(-(d[t1 - 1].first + t2), i));
	}
	sort (d.begin(), d.end());
	for (int i = 0; i < d.size(); i++) dd.push_back(d[i].first);
	for (int i = n - 1; i >= 0; i--){
		if (s.empty()) break;
		while (!s.empty() && -s.begin()->first >= dd[i]){
			pll p = *s.begin();
			s.erase(s.begin());
			ll r = -p.first, pos = lower_bound(dd.begin(), dd.end(), dd[i] - (r - dd[i])) - dd.begin();
			if (pos == i){
				ans[p.second] = d[i].second;
			} else {
				p.first = 2 * (dd[i] - dd[pos]) - r;
				if (-p.first >= dd[i]){
					p.first = -(-p.first - (-p.first - dd[i]) / (2 * (dd[i] - dd[pos])) * (2 * (dd[i] - dd[pos])));
				}
				s.insert(p);
			}
		}
	}
	for (int i = 0; i < m; i++) cout << ans[i] + 1<< "\n";
}