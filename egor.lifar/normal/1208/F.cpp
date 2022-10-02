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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 2397152;
 
 
 
int n;
int a[MAXN];
int g[MAXN][2];
 
 
void add(int i, int j) {
	if (j == -1) {
		return;
	}
	if (g[i][0] == j || g[i][1] == j) {
		return;
	}
	if (g[i][0] == -1) {
		g[i][0] = j;
		if (g[i][0] > g[i][1]) {
			swap(g[i][0], g[i][1]);
		}
		return;
	}
	if (g[i][1] == -1) {
		g[i][1] = j;
		if (g[i][0] > g[i][1]) {
			swap(g[i][0], g[i][1]);
		}
		return;
	}
	vector<int> st;
	st.pb(g[i][0]);
	st.pb(g[i][1]);
	st.pb(j);
	sort(all(st));
	g[i][0] = st[1];
	g[i][1] = st[2];
} 


char readchar() {
    char c = _getchar_nolock();
    while (c <= 32) {
        c = _getchar_nolock();
    }
    return c;
}


long long readint() 
{
    char c = readchar();
    int mag = 0;
    if (c == '-') {
        mag = 1;
        c = readchar();
    }
    long long t = 0;
    while (c >= '0' && c <= '9') {
        t = ((t << 3) + (t << 1)) + c - '0';
        c = _getchar_nolock();
    }
    return (mag ? -t: t);
}

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    n = readint();
    for (int i = 2097151; i >= 0; i--) {
    	g[i][0] = -1;
    	g[i][1] = -1;
    }
    for (int i = 0; i < n; i++) {
    	a[i] = readint();
    	add(a[i], i);
    }
    for (int i = 2097151; i >= 0; i--) {
    	vector<int> st;
    	for (int j = 0; j <= 20; j++) {
    		if (i & (1 << j)) {
    			continue;
    		}
            if (g[i ^ (1 << j)][0] != -1) {
    		  st.pb(g[i ^ (1 << j)][0]);
            }
            if (g[i ^ (1 << j)][1] != -1) {
    		  st.pb(g[i ^ (1 << j)][1]);
            }
    	}
    	sort(all(st));
    	st.resize(distance(st.begin(), unique(all(st))));
    	for (int j = sz(st) - 1; j >= max(0, sz(st) - 2); j--) {
    		add(i, st[j]);
    	}	
    }
    int curs = 0;
    for (int t = 20; t >= 0; t--) {
    	curs |= (1 << t);
    	bool ok = false;
    	for (int i = 0; i < n - 2; i++) {
    		int t = a[i] & curs;
    		int f1 = curs ^ t;
			if (g[f1][0] > i) {
    			ok = true;
    			break;
    		}
    	}
    	if (!ok) {
    		curs ^= (1 << t);
    	}
    }
    cout << curs << '\n';
    return 0;  
}