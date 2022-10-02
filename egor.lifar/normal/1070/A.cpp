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
    
int d, s;
int dist[501][5001];
pair<int, int> pr[501][5001];
int pc[501][5001];
int step[500 * 5000 + 228];
int old[501][5001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    cin >> d >> s;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j <= s; j++) {
            dist[i][j] = 1e9;
        }
    }
    dist[0][0] = 0;
    set<pair<pair<int, int> , pair<int, int> > > st;
    st.insert({{0, 0}, make_pair(0, 0)});
    step[0] = 1;
    for (int i = 1; i <= 500 * 5000; i++) {
        step[i] = (step[i - 1] * 10) % d;
    }
    int uk = 1;
    while (!st.empty()) {
        pair<pair<int, int>, pair<int, int> > k = *st.begin();
        st.erase(k);
        int i = k.second.first;
        int j = k.second.second;
        int f = dist[i][j];
        for (int c = 0; c <= 9; c++) {
           // int k = (c * step[f]) % d;
            int ni = (i * 10  + c) % d;
            int nj = j + c;
            if (dist[ni][nj] > dist[i][j] + 1) {
                st.erase({{dist[ni][nj], old[ni][nj]}, {ni, nj}});
                dist[ni][nj] = dist[i][j] + 1;
                pr[ni][nj] = make_pair(i, j);
                pc[ni][nj] = c;
                old[ni][nj] = uk;
                uk++;
                st.insert({{dist[ni][nj], old[ni][nj]}, {ni, nj}});
            }
            // } else if (dist[ni][nj] == dist[i][j] + 1) {
            //     if (pc[ni][nj] > c) {
            //         st.erase({dist[ni][nj], {ni, nj}});
            //         dist[ni][nj] = dist[i][j] + 1;
            //         pr[ni][nj] = make_pair(i, j);
            //         pc[ni][nj] = c;
            //         st.insert({dist[ni][nj], {ni, nj}});
            //     }
            // }
        }
    }
    //cout << dist[60][1] << '\n';
    if (dist[0][s] > 1e8) {
        cout << -1 << '\n';
        return 0;
    }

    int curi = 0, curj = s;
    vector<int> sts;
    while (!(curi == 0 && curj == 0)) {
        sts.pb(pc[curi][curj]);
        pair<int, int> p = pr[curi][curj];
        curi = p.first;
        curj = p.second;
    }
    reverse(all(sts));
    for (auto x: sts) {
        cout << x;
    }
    cout << '\n';
    return 0;
}