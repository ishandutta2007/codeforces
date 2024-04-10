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
#include <iomanip>
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
const int Mod = 998244353;
const int MAXN = 4005;
const long long BMod = 1LL * Mod * Mod * 6;


int n,m,k,a[2][MAXN],c[100][100];
long long s[75], t[75];
long long p, q;
int px[MAXN],qx[MAXN],py[MAXN],qy[MAXN];
bool f, g;

void add1(int &x, int y) {
    x += y; 
    if (x >= Mod)  {
        x -= Mod;
    }
}


void add2(long long &x, long long y) {
    x += y; 
    if (x >= BMod)  {
        x -= BMod;
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
    cin >> n >> m >> k;
    for (int i = 1; i <= n - 1; i++) {
        cin >> px[i] >> py[i];
    }
    for (int i = 1; i <= m - 1; i++) {
        cin >> qx[i] >> qy[i];
    }
    if (k & 1) {
        cout << 0 << endl;
        return 0;
    }
    c[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % Mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(a, 0, sizeof(a));
        a[0][i] = 1; 
        s[0]++;
        for (int j = 1; j <= k / 2; j++) {
            g = j & 1; 
            f = !g;
            for (int u = 1; u < n; u++) {
                add1(a[g][py[u]], a[f][px[u]]);
                add1(a[g][px[u]], a[f][py[u]]);
            }
            for (int u = 1; u <= n; u++) {
                add2(s[j * 2], 1LL * a[g][u] * a[g][u]);
                a[f][u] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++){
        memset(a, 0, sizeof(a));
        a[0][i] = 1; 
        t[0]++;
        for (int j = 1; j <= k / 2; j++){
            g = j & 1; 
            f = !g;
            for (int u = 1; u < m; u++) {
                add1(a[g][qy[u]], a[f][qx[u]]);
                add1(a[g][qx[u]], a[f][qy[u]]);
            }
            for (int u = 1; u <= m; u++) {
                add2(t[j * 2], 1LL * a[g][u] * a[g][u]);
                a[f][u] = 0;
            }
        }
    }
    for (int i = 0; i <= k; i += 2) {
        s[i] %= Mod;
        t[i] %= Mod;
    }
    long long ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += ((c[k][i] * s[i]) % Mod * t[k - i]) % Mod;
        ans %= Mod;
    }
    cout << ans << '\n';
}