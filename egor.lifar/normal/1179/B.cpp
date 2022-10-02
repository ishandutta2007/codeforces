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
 
template<class T1, class T2> inline int chkmin(T1 &x, const T2 &y) {
    if (x > y) {
        x = y;
        return 1;
    }
    else {
        return 0;
    }
}
 
template<class T1, class T2> inline int chkmax(T1 &x, const T2 &y) {
    if (x < y) {
        x = y;
        return 1;
    }
    else {
        return 0;
    }
}
 
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
 
template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}
 
 
template<class T> void output(const T &x, ostream &out = cerr) {
    output(x.begin(), x.end(), out);
}
 
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
}




 
int main() {
    fast_io();
   // read("input");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n - i + 1; i++) {
        for (int j = 1; j <= m; j++) {
            cout << i << ' ' << j << '\n';
            cout << n - i + 1 << ' ' << m - j + 1 << '\n';
        }
    }
    if (n & 1) {
        for (int j = 1; j <= m - j + 1; j++) {
            cout << (n + 1) / 2 << ' ' << j << '\n';
            if (j != m - j + 1) {
                cout << (n + 1) / 2 << ' ' << m - j + 1 << '\n';
            }
        }
    }
    return 0; 
}