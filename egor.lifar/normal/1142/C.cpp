 /*
 



















 
 */
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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
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
const string FILENAME = "input";
const int MAXN = 200228;


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
};





int n;
long long x[MAXN], y[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		y[i] -= x[i] * x[i];
	}
	vector<pair<long long, long long> > st;
	for (int i = 0; i < n; i++) {
		st.pb(mp(x[i], y[i]));
	}
	sort(all(st));
	ConvexHull kek;
	for (int i = 0; i < n; i++) {
		if (i != n - 1 && st[i].first == st[i + 1].first && st[i].second <= st[i + 1].second) {
			continue;
		}
		kek.addLine(Line(st[i].first, st[i].second));
	}
	cout << sz(kek.st) - 1 << endl;
	return 0; 	
}