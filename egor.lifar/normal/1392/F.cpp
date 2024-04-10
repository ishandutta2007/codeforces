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
#include <complex>


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
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";


inline char readChar() {
    char c = _getchar_nolock();
    while (c <= 32) {
        c = _getchar_nolock();
    }
    return c;
}

int readInt() {
    int v = 0;
    bool sign = true;
    char c = readChar();
    if (c == '-') {
        sign = false;
        c = _getchar_nolock();
    }
    while ('0' <= c && c <= '9') {
        v = (v << 3) + (v << 1) + c - '0';
        c = _getchar_nolock();
    }
    return (sign ? v: -v);
}


long long readLong() {
    long long v = 0;
    bool sign = true;
    char c = readChar();
    if (c == '-') {
        sign = false;
        c = _getchar_nolock();
    }
    while ('0' <= c && c <= '9') {
        v = (v << 3) + (v << 1) + c - '0';
        c = _getchar_nolock();
    }
    return (sign ? v: -v);
}

const int MAXN = 1000228;


int n;
ll h[MAXN];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	n = readInt();
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		h[i] = readLong();
		sum += h[i];
	}
	ll ls = 0;
	ll rs = 1e12 + 2;
	while (ls < rs) {
		ll ms = (ls + rs) >> 1;
		ll sums = ms * n + (ll)n * (n - 1) / 2;
		if (sums >= sum) {
			rs = ms;
		} else {
			ls = ms + 1;
		}
	}
	ll diff = ls * n + (ll)n * (n - 1) / 2 - sum;
	for (int i = 0; i < n; i++) {
		ll kek = ls + i;
		if (n - i <= diff) {
			kek--;
		}
		cout << kek << ' ';
	}
	cout << '\n';
}