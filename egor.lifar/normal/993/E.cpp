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
	 
	  
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const string FILENAME = "input";
const int MAXN = 600228;
typedef complex<long double> base;
const long double Pi = 3.1415926535897932384626433832795028841971;

int n, x;
long long a[MAXN];
long long ans[MAXN];
int invs[20][1 << 20];
base wt[2][(1 << 20) + 228];


int inversed(int i, int logs) {
    int res = 0;
    for (int j = 0; j < logs; j++) {
        if (i & (1 << j)) {
            res |= 1 << (logs - j - 1);
        }
    }
    return res;
}


void fft(vector<base> &a, bool inverse = false) {
    int n = 1;
    int logs = 0;
    while (n < sz(a)) {
        n <<= 1;
        logs++;
    }
    for (int i = 0; i < n; i++) {
        if (i < invs[logs][i]) {
            swap(a[i], a[invs[logs][i]]);
        }
    }
    for (int len = 2; len <= n; len<<= 1) {
        base w = wt[inverse][len];
        for (int i = 0; i < n; i += len) {
            base ws(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j], v = a[i + j + len / 2] * ws;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                ws *= w;
            }
        }
    }
    if (inverse) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}



int cnt[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> t;
	t.resize(n + 1);
	int pref = 0;
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] < x) {
			pref++;
			last = i;
		}
		t[pref]++;
		if (pref) {
		ans[pref]++;
		}
		if (i - last > 0) {
		ans[0] += i - last;
	} 
		cnt[pref]++;
	}
	vector<int> t1 = t;
	reverse(all(t1));
	 for (int len = 2; len <= (1 << 20); len<<= 1) {
        double ang = 2.0 * Pi / len * (true ? -1: 1);
        base w(cos(ang), sin(ang));
        wt[1][len] = w;
    }
    for (int len = 2; len <= (1 << 20); len<<= 1) {
        double ang = 2.0 * Pi / len * (false ? -1: 1);
        base w(cos(ang), sin(ang));
        wt[0][len] = w;
    }
	for (int logs = 0; logs < 20; logs++) {
	    for (int i = 0; i < (1 << logs); i++) {
	        invs[logs][i] = inversed(i, logs);
	    }
	}
	int len = 1;
    while (len < sz(t) + sz(t1) + 10) {
        len <<= 1;
    } 
	vector<base> as, bs;
    as.resize(len);
    bs.resize(len);
    for (int i = 0; i < sz(t); i++) {
        as[i] = base(t[i]);
    }
    for (int i = 0; i < sz(t1); i++) {
        bs[i] = base(t1[i]);
    }
    fft(as);
    fft(bs);
    for (int i = 0; i < len; i++) {
        as[i] *= bs[i];
    }
    fft(as, true);
    for (int i = 1; i < len; i++) {
    	//a + n - b
    	//a - b + n;
    	if (i > n) {
    		ans[i - n] += (long long)round(as[i].real());
    	}
    }
	for (int i = 0; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}