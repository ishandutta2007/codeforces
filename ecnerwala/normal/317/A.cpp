/*
LANG: C++
ID: he.andr1
PROG: A
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#include<string>
#include<cstring>
#include<cassert>
#include<numeric>
#include<complex>
#include<cmath>
#include<ctime>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(i, v) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()
#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<int> pt;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }
template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

ll go() {
    ll x, y, m;
    cin >> x >> y >> m;
    if(x <= 0 && y <= 0 && max(x, y) < m) return -1;
    ll out = 0;
    if(x > y) swap(x, y);
    while(y < m) {
        ll num = y - x;
        num /= y;
        x += num * y;
        if(x <= y) x += y, num++;
        out += num;
        swap(x, y);
        //cerr << x << ' ' << y << ' ' << num << '\n';
    }
    return out;
}


int main() {
    cout << go() << '\n';
	return 0;
}