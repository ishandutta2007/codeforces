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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 20009;



struct Line{
    long long k, b;
    Line(){}
    Line(long long _k, long long _b) {
        k = _k;
        b = _b;
    }
    long long value(long long x) {
        return 1LL * k * x + b;
    }
};


bool operator <(const Line &b, const Line &a) {
    return b.k < a.k || (b.k == a.k && b.b < a.b);
}


bool better(Line a, Line b, Line c) {
    return 1LL * (c.b - a.b) * (a.k - b.k) <= 1LL * (b.b - a.b) * (a.k - c.k);
}



struct ConvexHull
{
    vector<Line> st;
 
    void addLine(Line x) {
        while (sz(st) >= 2 && better(st[sz(st) - 2], st.back(), x)) {
            st.pop_back();
        }
        st.pb(x);
    }
    long long getmax(int x) {
        if (st.empty()) {
            return -1e12;
        }
        int l = 0;
        int r = sz(st) - 1;
        while (l + 3 < r) {
            int mid = (l + r) >> 1;
            if ((st[mid + 1].b - st[mid].b) >= 1LL * x * (st[mid].k - st[mid + 1].k)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        long long kek = -1e12;
        //cout << st[0].value(x) << endl;
        for (int i = l; i <= r; i++) {
            chkmax(kek, st[i].value(x));
        }
        return kek;
    }
};


int n, k;
int a[MAXN];
ConvexHull st[MAXN * 4];
ConvexHull st1[MAXN * 4];
int ss = 1;
long long dp[MAXN][102];
int ls[MAXN], rs[MAXN];


void add(int i, Line l) {
	while (i) {
		st[i].addLine(l);
		i >>= 1;
	}
}


long long getmax(int v, int vl, int vr, int l, int r, int x) {
	if (vl > r || vr < l) {
		return -1e12;
	}
	if (l <= vl && vr <= r) {
		return st[v].getmax(x);
	}
	return max(getmax(v * 2, vl, (vl + vr) / 2, l, r, x), getmax(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x));
}



void add(int v, int vl, int vr, int l, int r, Line x) {
	if (vl > r || vr < l) {
		return;
	}
	if (l <= vl && vr <= r) {
	//	cout << x.k << ' ' << x.b << endl;
		st1[v].addLine(x);
		return;
	}
	add(v * 2, vl, (vl + vr) / 2, l, r, x);
	add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
}


void reset() {
	for (int i = 0; i < 2 * ss; i++) {
		st[i].st.clear();
		st1[i].st.clear();
	}
}


long long get(int i, int x) {
	long long ans = -1e12;
	while (i) {
		chkmax(ans, st1[i].getmax(x));
		i >>= 1;
	}
	return ans;
}

long long f[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while (ss < n) {
		ss <<= 1;
	}
	vector<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.back()] <= a[i]) {
			st.pop_back();
		}
		ls[i] = (st.empty() ? 0: st.back() + 1);
			st.pb(i);
	}
	st.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && a[st.back()] <= a[i]) {
			st.pop_back();
		}
		rs[i] = (st.empty() ? n - 1: st.back() - 1);
		//cout << i << ' ' << rs[i] << endl;
		st.pb(i);
	}
	int maxs = 0;
	for (int i = 0; i < n; i++) {
		chkmax(maxs, a[i]);
		dp[i][0] = 1LL * maxs * (i + 1);
	}
	for (int j = 1; j < k; j++) {
		reset();
		for (int i = 0; i < n; i++) {
			//a[j] * (i - 1) - dp[i - 1][j]
			f[i] = -getmax(1, 1, ss, max(1, ls[i]), i, a[i]);
			//cout << dp[i][j - 1] << endl;
 			add(ss + i, Line(i, -dp[i][j - 1]));
		}
		vector<pair<Line, int> > sts;
		for (int i = 0; i < n; i++) {
		//	cout << a[i] * (n - 1) + f[i] << endl;
			sts.pb({Line(-a[i], -f[i]), i});
		}
		sort(all(sts));
		for (auto x: sts) {
			add(1, 1, ss, x.second + 1, rs[x.second] + 1, x.first);
		}
		for (int i = 0; i < n; i++) {
			dp[i][j] = -get(ss + i, i);
		//	cout << dp[i][j] << ' ';
		}
		//cout << endl;
	}
	cout << dp[n - 1][k - 1] << endl;
}