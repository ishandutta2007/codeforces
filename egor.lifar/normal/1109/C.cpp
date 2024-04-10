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
#include <array>
       
        
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
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 300228;
#define int long long



int q;
int type[MAXN];
int t[MAXN], s[MAXN];
int ll[MAXN], rr[MAXN], vv[MAXN];
vector<int> vt;
int m;
long long sum[MAXN];
int ss[MAXN];
set<int> cur;
map<int, int> whox;


struct rmq
{
    int ss;
    vector<long long> val;
    vector<long long> mod;
    void init(int n) {
        ss = 1;
        while (ss < n) {
            ss <<= 1;
        }
        val.resize(2 * ss, 0);
        mod.resize(2 * ss, 0);
    }
    void push(int v) {
        if (mod[v] != 0) {
            val[v] += mod[v];
            if (v < ss) {
                mod[v * 2] += mod[v];
                mod[v * 2 + 1] += mod[v];
            }
            mod[v] = 0;
        }
    }
    void add(int v, int vl, int vr, int l, int r, long long x) {
        if (l > r) {
            return;
        }
        if (vl > r || vr < l) {
            push(v);
            return;
        }
        if (l <= vl && vr <= r) {
            mod[v] += x;
            push(v);
            return;
        } 
        push(v);
        add(v * 2, vl, (vl + vr) / 2, l, r, x);
        add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
        val[v] = max(val[v * 2], val[v * 2 + 1]);
    }
    long long get(int v, int vl, int vr, int l, int r) {
        if (vl > r || vr < l) {
            return -1e18;
        }
        if (l <= vl && vr <= r) {
            return val[v] + mod[v];
        } 
        push(v);
        return max(get(v * 2, vl, (vl + vr) / 2, l, r), get(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
    }
};


rmq tr;

void inc(int i, long long val) {
    tr.add(1, 1, tr.ss, i + 1, tr.ss, val);
    for (int j = i; j < m; j |= (j + 1)) {
        sum[j] += val;
    }
}


long long get(int i) {
    long long res = 0;
    for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
        res += sum[j];
    }
    return res;
}


long long get(int l, int r) {
    if (l > r) {
        return 0;
    }
    return get(r) - (l == 0 ? 0: get(l - 1));
}



long long getboundry(int curt) {
    auto it = cur.upper_bound(curt);
    if (it == cur.end()) {
        return 2000000000;
    }
    return *it;
}


void del(long long curt) {
    int id = whox[curt];
    //cout << ss[id] << endl;
    inc(id, -1LL * ss[id] * (getboundry(curt) - curt));
}


void add(long long curt) {
    int id = whox[curt];
    //cout << ss[id] << endl;
    inc(id, 1LL * ss[id] * (getboundry(curt) - curt));
}


void add(int curt, int kek) {
    ss[whox[curt]] = kek;
    auto it = cur.lower_bound(curt);
    int f = -1;
    if (it != cur.begin()) {
        it--;
        f = *it;
        del(f);
    }
    cur.insert(curt);
    if (f != -1) {
        add(f);
    }
    add(curt);
}



void dels(int curt) {
    del(curt);
    auto it = cur.lower_bound(curt);
    int f = -1;
    if (it != cur.begin()) {
        it--;
        f = *it;
        del(f);
    }
    cur.erase(curt);
    if (f != -1) {
        add(f);
    }

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> type[i];
        if (type[i] == 1) {
            cin >> t[i] >> s[i];
            s[i] *= -1;
            vt.pb(t[i]);
        } else if (type[i] == 2) { 
            cin >> t[i];
        } else {
            cin >> ll[i] >> rr[i] >> vv[i];
            vt.pb(ll[i]);
            vt.pb(rr[i]);
        }
    }
    sort(all(vt));
    vt.resize(distance(vt.begin(), unique(all(vt))));
    m = sz(vt);
    tr.init(m);
    for (int i = 0; i < m; i++) {
        whox[vt[i]] = i;
    } 
    cout.precision(10);
    for (int i = 0; i < q; i++) {
        if (type[i] == 1) {
            add(t[i], s[i]);
        } else if (type[i] == 2) {
            dels(t[i]);
        } else {
            //cout << get(whox[ll[i]], whox[rr[i]]) << endl;
            if (vv[i] == 0) {
                cout << ll[i] << '\n';
                continue;
            }
            long long f = get(0, whox[ll[i]] - 1);
            //cout << f << endl;
            if (tr.get(1, 1, tr.ss, whox[ll[i]] + 1, whox[rr[i]] + 1) - f < vv[i]) {
                cout << -1 << '\n';
            } else {
                int l = whox[ll[i]];
                int r = whox[rr[i]];
                int curl = whox[ll[i]];
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (tr.get(1, 1, tr.ss, curl + 1, mid + 1) - f >= vv[i]) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
              //  cout << vv[i] << endl;
                vv[i] -= get(curl, l - 1);
                // cout << tr.get(1, 1, tr.ss, curl + 1, l) << endl;
                // cout << vt[l] << endl;
                int f = ss[l];
               // cout << f << ' ' << vv[i] << endl;
                double kek = vt[l] + double(vv[i]) / double(f);
                if (kek > rr[i] + 1e-9) {
                    cout << -1 << '\n';
                } else {
                    cout << kek << '\n';
                }
            }
        }
    }
    return 0;       
}