/*
 












 
 */
#pragma GCC target("sse4,tune=native")
#pragma GCC optimize("O3","unroll-loops")
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
const string FILENAME = "input";
//WULD! NAH! KEST!
const int MAXN = 300001;
const int Mod = 1000000007;

int n;
int v[MAXN];
vector<int> g[MAXN];
int sum = 0;
int cnt[MAXN][2];
int up[MAXN][2];


void dfs(int u, int pr = -1) {
    cnt[u][0] = 1;
    for (auto h: g[u]) {
        if (h != pr) {
            dfs(h, u);
            cnt[u][0] += cnt[h][1];
            cnt[u][1] += cnt[h][0];
        }
    }
}


void dfs1(int u, int pr = -1) {
    //cout << u + 1 << endl;
    up[u][0]++;
    int sums[2] = {0, 0};
    for (auto h: g[u]) {
        if (h != pr) {
            sums[0] += cnt[h][0];
            sums[1] += cnt[h][1];
        }
    }
    for (auto h: g[u]) {
        if (h != pr) {
            sums[0] -= cnt[h][0];
            sums[1] -= cnt[h][1];
            up[h][0] = up[u][1] + sums[0];
            up[h][1] = up[u][0] + sums[1];
            dfs1(h, u);
            sums[0] += cnt[h][0];
            sums[1] += cnt[h][1];
        }
    }
    for (auto h: g[u]) {
        if (h != pr) {
            sums[0] -= cnt[h][0];
            sums[1] -= cnt[h][1];
            for (int f = 0; f < 2; f++) {
                for (int f1 = 0; f1 < 2; f1++) {
                    long long t = 1LL * cnt[h][f ^ 1] * sums[f1];
                    t %= Mod;
                    t = (t * v[u]) % Mod;
                    if (f) {
                        t *= -1;
                    }
                    sum += t;
                    if (sum >= Mod) {
                        sum -= Mod;
                    }
                    if (sum < 0) {
                        sum += Mod;
                    }
                }
            }
            sums[0] += cnt[h][0];
            sums[1] += cnt[h][1];
        }
    }
  //  cout << sum << endl;
    up[u][0]--;
        cnt[u][0]--;
        long long t = cnt[u][0] + cnt[u][1];
        t %= Mod;
        t = (t * v[u]) % Mod;
        sum += t;
        if (sum >= Mod) {
            sum -= Mod;
        }
        if (sum < 0) {
            sum += Mod;
        }
        for (int f = 0; f < 2; f++) {
            long long t = cnt[u][f];
            t %= Mod;
            t = (t * v[u]) % Mod;
            if (f) {
                t *= -1;
            }
            sum += t;
            if (sum >= Mod) {
                sum -= Mod;
            }
            if (sum < 0) {
                sum += Mod;
            }
        }
        for (int f = 0; f < 2; f++) {
            long long t = up[u][f];
            t %= Mod;
            t = (t * v[u]) % Mod;
            if (f) {
                t *= -1;
            }
            sum += t;
            if (sum >= Mod) {
                sum -= Mod;
            }
            if (sum < 0) {
                sum += Mod;
            }
        }
        for (int f = 0; f < 2; f++) {
            long long t = up[u][f];
            t %= Mod;
            t = (t * v[u]) % Mod;
            sum += t;
            if (sum >= Mod) {
                sum -= Mod;
            }
            if (sum < 0) {
                sum += Mod;
            }
        }
    if (u != 0) {
      //  cout << up[u][0] << ' ' << up[u][1] << endl;
        
        for (int f = 0; f < 2; f++) {
            for (int f1 = 0; f1 < 2; f1++) {
                long long t = 1LL * up[u][f] * cnt[u][f1];
                t %= Mod;
              // cout << t << endl;
                t = (t * v[u]) % Mod;
                if (f) {
                    t *= -1;
                    t += Mod;
                    if (t >= Mod) {
                        t -= Mod;
                    }
                }
                sum += t;
                if (sum >= Mod) {
                    sum -= Mod;
                }
                if (sum < 0) {
                    sum += Mod;
                }
            }
        }
        for (int f = 0; f < 2; f++) {
            for (int f1 = 0; f1 < 2; f1++) {
                long long t = 1LL * cnt[u][f] * up[u][f1];
                t %= Mod;
              //  cout << t << endl;
                t = (t * v[u]) % Mod;
                if (f) {
                    t *= -1;
                    t += Mod;
                    if (t >= Mod) {
                        t -= Mod;
                    }
                }
                sum += t;
                if (sum >= Mod) {
                    sum -= Mod;
                }
                if (sum < 0) {
                    sum += Mod;
                }
            }
        }

    }
            cnt[u][0]++;
        up[u][0]++;
    //cout << sum << ' ' << u + 1 << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
       // cout << v[i] << endl;
        sum += v[i];
        sum %= Mod;
        if (sum < 0) {
            sum += Mod;
        }
    }
   //cout << sum << endl;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);  
    dfs1(0); 
    cout << sum << endl; 
    return 0;     
}