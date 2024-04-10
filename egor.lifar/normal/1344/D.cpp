#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 100228;


int n;
ll k;
ll a[MAXN];
ll ans[MAXN];
ll pref[MAXN];


ll get(ll a, ll cnt) {
	if (cnt == 0) {
		return a;
	}
	return a - (3 * cnt * cnt - 3 * cnt + 1);
}



const ll INF = 3LL * 1e9 * 1e9; 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> k;
    vector<pair<ll, int> > st;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	st.pb(mp(a[i], i));
    }
   	sort(all(st));
   	for (int i = 0; i < n; i++) {
   		a[i] = st[i].first;
   	}
   	ll l = 0;
   	ll r = 1e9 + 1 + INF;
   	while (l < r) {
   		ll dmid = (l + r + 1) >> 1;
   		ll rmid = dmid - INF;
   		ll sum = 0;
   		for (int i = 0; i < n; i++) {
   			ll l = 0;
   			ll r = a[i];
   			while (l < r) {
   				ll mid = (l + r + 1) >> 1;
   				if (get(a[i], mid) >= rmid) {
   					l = mid;
   				} else {
   					r = mid - 1;
   				}
   			}
   			sum += l;
   		}
   		if (sum >= k) {
   			l = dmid;
   		} else {
   			r = dmid - 1;
   		}
   	}
   	r -= INF;
   	ll R = r;
   	for (int i = 0; i < n; i++) {
   		ll l = 0;
		ll r = a[i];
		while (l < r) {
			ll mid = (l + r + 1) >> 1;
			if (get(a[i], mid) >= R + 1) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		ans[st[i].second] = l;
		k -= l;
   	}
   	for (int i = 0; i < n; i++) {
   		ll l = ans[st[i].second];
		ll r = min(a[i], l + k);
		while (l < r) {
			ll mid = (l + r + 1) >> 1;
			if (get(a[i], mid) >= R) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		k -= l - ans[st[i].second];
		ans[st[i].second] = l;
   	}
   	for (int i = 0; i < n; i++) {
   		cout << ans[i] << ' ';
   	}
   	cout << '\n';
}