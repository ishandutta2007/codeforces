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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const int MAXN = 200228;


int n, q;
int a[MAXN];
vector<int> who[MAXN];
int where[MAXN];
int lx[MAXN], rx[MAXN];
int used[MAXN];
int uk = 0;
vector<pair<int, int> > p[MAXN];
vector<pair<int, pair<int, int> > > d[MAXN];
vector<pair<pair<int, int>, int> > z[MAXN];


void add(int lx, int rx, int ly, int ry) {
	p[lx].pb(mp(ly, ry));
	d[rx + 1].pb(mp(ly, mp(ry, lx)));
}


struct fenw
{
    vector<ll> dataMul, dataAdd;
    void init(int n) {
        dataMul.resize(n + 1);
        dataAdd.resize(n + 1);
    }
    void internalUpdate(int at, ll mul, ll add) {
        while (at < sz(dataMul)) {
            dataMul[at] += mul;
            dataAdd[at] += add;
            at |= (at + 1);
        }
    }
    void update(int left, int right, ll by) {
        internalUpdate(left, by, -by * (left - 1));
        internalUpdate(right, -by, by * right);
    }

    ll query(int at) {
        ll mul = 0;
        ll add = 0;
        ll start = at;
        while (at >= 0) {
            mul += dataMul[at];
            add += dataAdd[at];
            at = (at & (at + 1)) - 1;
        }
        return mul * start + add;
    }
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
} kek, kek1;



ll ans[MAXN * 10];


void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		where[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j+= i) {
			who[j].pb(i);
		}
	}
	vector<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.back()] <= a[i]) {
			st.pop_back();
		}
		lx[i] = (st.empty() ? 0: st.back() + 1);
		st.pb(i);
	}
	st.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && a[st.back()] <= a[i]) {
			st.pop_back();
		}
		rx[i] = (st.empty() ? n - 1: st.back() - 1);
		st.pb(i);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			continue;
		}
		//cout << a[i] << endl;
		vector<int> ls, rs;
		for (auto x: who[a[i]]) {
			if (a[i] / x == x) {
				continue;
			}
			int p = where[x];
			if (lx[i] <= p && p <= rx[i]) {
				if (p <= i) {
					ls.pb(p);
				} 
				if (p >= i) {
					rs.pb(p);
				}
			}
		}
		sort(all(rs));
		sort(all(ls));
		reverse(all(ls));
		uk++;
		used[a[i]] = uk;
		int pos = 0;
		int cnt = 0;
		for (int j = 1; j < sz(rs); j++) {
			used[a[rs[j]]] = uk;
			if (used[a[i] / a[rs[j]]] == uk) {
				pos = j;
				cnt++;
				break;
			}
		}
		if (!cnt) {
			pos = sz(rs) - 1;
		}
		for (int j = 0; j < sz(ls); j++) {
			if (cnt) {
				add((j == sz(ls) - 1 ? lx[i]: ls[j + 1] + 1), ls[j], rs[pos], rx[i]);
			}
			if (j + 1 < sz(ls)) {
				used[a[ls[j + 1]]] = uk;
				if (used[a[i] / a[ls[j + 1]]] == uk) {
					cnt++;
				}
				while (pos > 0 && cnt) {
					if (used[a[i] / a[rs[pos]]] != uk) {
						used[a[rs[pos]]] = 0;
						pos--;
					} else {
						if (cnt >= 2) {
							
							used[a[rs[pos]]] = 0;
							pos--;
							cnt--;
						} else {
							break;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l) {
			z[l - 1].pb(mp(mp(l, r), -i));
		}
		z[r].pb(mp(mp(l, r), i));
	}
	kek.init(n);
	kek1.init(n);
	for (int i = 0; i < n; i++) {
		for (auto x: p[i]) {
			kek.update(x.first, x.second, -i);
			kek1.update(x.first, x.second, 1);
		}
		for (auto x: d[i]) {
			kek.update(x.first, x.second.first, i);
			kek1.update(x.first, x.second.first, -1);
		}
		for (auto x: z[i]) {
			ans[abs(x.second)] += (x.second > 0 ? 1: -1) * (kek.query(x.first.first, x.first.second) + (ll)(i + 1) * kek1.query(x.first.first, x.first.second));
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}