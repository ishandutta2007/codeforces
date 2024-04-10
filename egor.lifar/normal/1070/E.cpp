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
const int MAXN = 200228;    



int n, m;
long long t;
int p[MAXN];
int cnt[MAXN * 4];
long long sum[MAXN * 4];
int ss = 1;


void change(int i, int cnts, int x) {
    while (i) {
        cnt[i]+= cnts;
       //cout << i << ' ' << cnts << endl;
        sum[i]+= x;
        i >>= 1;        
    }
}



int getcnt(int l, int r) {
    if (l > r) {
        return 0;
    }
    l += ss;
    r += ss;
    int ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans += cnt[l];
            l++;
        }
        if (!(r & 1)) {
            ans += cnt[r];
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
} 



long long getsum(int l, int r) {
    if (l > r) {
        return 0;
    }
    l += ss;
    r += ss;
    long long ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans += sum[l];
            l++;
        }
        if (!(r & 1)) {
            ans += sum[r];
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
} 

vector<int> who[MAXN];


int spusk(int v, int vl, int vr, int x) {
    if (vl == vr) {
        //cout << vl << ' ' << vr << ' ' << x << ' ' << cnt[v] << endl;
        return vl - 1;
    }
    if (cnt[v * 2] >= x) {
        return spusk(v * 2, vl, (vl + vr) / 2, x);
    }
    return spusk(v * 2 + 1, (vl + vr) / 2 + 1, vr, x - cnt[v * 2]);
}


int get() {
    int l = 0;
    int r = n - 1;
    //cout << "opa" << endl;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int ts = getcnt(0, mid);
        long long cost = 0;
        if (ts <= m) {
            cost = getsum(0, mid);
        } else {
           // cout << ts << endl;
            int pos = spusk(1, 1, ss, ts - (ts % m == 0 ? m: ts % m));
          //  cout << pos << endl;
            cost = getsum(0, pos) * 2 + getsum(pos + 1, mid);
        }
      //  cout << mid << ' ' << cost << endl;
        if (cost <= t) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
     int ts = getcnt(0, l);
        long long cost = 0;
        if (ts <= m) {
            cost = getsum(0, l);
        } else {
           // cout << ts << endl;
            int pos = spusk(1, 1, ss, ts - (ts % m == 0 ? m: ts % m));
          //  cout << pos << endl;
            cost = getsum(0, pos) * 2 + getsum(pos + 1, l);
        }
        if (cost > t) {
            return 0;
        }
    //cout << l << endl;
    return getcnt(0, l);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    int tt;
    cin >> tt;
    for (int it = 0; it < tt; it++) {
        cin >> n >> m >> t;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        vector<int> st;
        for (int i = 0; i < n; i++) {
            if (p[i] > t) {
                continue;
            }
            st.pb(p[i]);
        }
        sort(all(st));
        st.resize(distance(st.begin(), unique(all(st))));
        reverse(all(st));
        ss = 1;
        while (ss < n) {
            ss <<= 1;
        }
        for (int i = 0; i < 2 * ss; i++) {
            cnt[i] = 0;
            sum[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (p[i] > t) {
                continue;
            }
            change(ss + i, 1, p[i]);
            who[p[i]].clear();
        }
        for (int i = 0; i < n; i++) {
            who[p[i]].pb(i);
        }
        int curopt = get();
        long long curd = t;
        for (auto x: st) {
            if (x == 1) {
                break;
            }
            for (auto y: who[x]) {
                change(ss + y, -1, -p[y]);
               // cout << y << ' ' << x << endl;
            }
            int nopt = get();
           // cout << nopt << endl;
            if (nopt > curopt) {
                curopt = nopt;
                curd = x - 1;
            }
        }
        cout << curopt << ' ' << curd << '\n';
      //  return 0;
    }
    return 0;
}