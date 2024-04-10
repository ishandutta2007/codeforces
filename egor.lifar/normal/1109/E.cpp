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
const int MAXN = 200228;


int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n > 1) {
        res -= res / n;
    }
    return res;
}


int mod;


int sum(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        b >>= 1;    
        a = mul(a, a);
    }
    return res;
}



vector<int> st;


struct node
{
    int sum;
    int muls;
    vector<int> g;
};


node d[MAXN * 4];
vector<int> pw[10];
int id[MAXN];
int goods[MAXN];
int inv[MAXN];


void calc(int i) {
    d[i].sum = sum(d[i * 2].sum, d[i * 2 + 1].sum);
}


int getsum(int i) {
    int res = d[i].muls;
    for (int j = 0; j < sz(d[i].g); j++) {
        res = mul(res, pw[j][d[i].g[j]]);
    }
    return res;
}


void push(int i) {
    for (int j = 0; j < sz(d[i].g); j++) {
        d[i * 2].g[j] += d[i].g[j];
        d[i * 2 + 1].g[j] += d[i].g[j];
        d[i * 2].sum = mul(d[i * 2].sum, pw[j][d[i].g[j]]);
        d[i * 2 + 1].sum = mul(d[i * 2 + 1].sum, pw[j][d[i].g[j]]);
        d[i].g[j] = 0;
    }
    d[i * 2].muls = mul(d[i * 2].muls, d[i].muls);
    d[i * 2 + 1].muls = mul(d[i * 2 + 1].muls, d[i].muls);
    d[i * 2].sum = mul(d[i * 2].sum, d[i].muls);
    d[i * 2 + 1].sum = mul(d[i * 2 + 1].sum, d[i].muls);
    d[i].muls = 1;
}


vector<pair<int, int> > f[MAXN];


void mul(int v, int vl, int vr, int l, int r, int x) {
    if (vl > r || vr < l) {
        return;
    }
    if (l <= vl && vr <= r) {
        for (auto p: f[x]) {
            d[v].g[id[p.first]] += p.second;
        }
        d[v].muls = mul(d[v].muls, goods[x]);
        d[v].sum = mul(d[v].sum, x);
        return;
    }
    push(v);
    mul(v * 2, vl, (vl + vr) / 2, l, r, x);
    mul(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
    calc(v);
}



void divide(int v, int vl, int vr, int pos, int x) {
    if (vl == vr) {
        for (auto p: f[x]) {
            d[v].g[id[p.first]] -= p.second;
        }
        d[v].muls = mul(d[v].muls, inv[goods[x]]);
        d[v].sum = getsum(v);
        return;
    }
    push(v);
    if (pos <= (vl + vr) / 2) {
        divide(v * 2, vl, (vl + vr) / 2, pos, x);
    } else {
        divide(v * 2 + 1, (vl + vr) / 2 + 1, vr, pos, x);
    }
    calc(v);
}



int get(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 0;
    } 
    if (l <= vl && vr <= r) {
        return d[v].sum;
    }
    push(v);
    return sum(get(v * 2, vl, (vl + vr) / 2, l, r), get(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}



int deg[MAXN];

void precalc() {
    if (st.back() >= 200000) {
        st.pop_back();
    }
    for (int i = 0; i < sz(st); ++i) {
        id[st[i]] = i;
        for (int j = st[i]; j < MAXN; j += st[i]) {
            if ((j / st[i]) % st[i]) {
                deg[j] = 1;
            } else {
                deg[j] = deg[j / st[i]] + 1;
            }
            f[j].emplace_back(st[i], deg[j]);
        }
    }
 
    for (int i = 1; i < MAXN; i++) {
        goods[i] = i;
        goods[i] = goods[i / __gcd(i, mod)];
    }
}


void precalc_inverse() {
    vector <int> mn(MAXN);
    for (int i = 2; i < MAXN; i++) {
        if (mn[i]) {
            continue;
        }
        for (int j = i + i; j < MAXN; j += i) {
            if (!mn[j]) {
                mn[j] = i;
            }
        }
    }
    int mod_phi = phi(mod);
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!mn[i]) {
            inv[i] = powm(i, mod_phi - 1);
        } else {
            inv[i] = mul(inv[i / mn[i]], inv[mn[i]]);
        }
    }
}



void precalc_powers() {
    for (int i = 0; i < sz(st); i++) {
        pw[i].resize(18 * MAXN + 1);
        pw[i][0] = 1;
        for (int j = 1; j < sz(pw[i]); j++) {
            pw[i][j] = mul(pw[i][j - 1], st[i]);
        }
    }
}




int n;
int a[MAXN];
int q;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> mod;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 2;
    int kek = mod;
    while (cur * cur <= kek) {
        if (kek % cur == 0) {
            while (kek % cur == 0) {
                kek /= cur;
            }
            st.pb(cur);
        }
        cur++;
    }
    if (kek != 1) {
        st.pb(kek);
    }
    sort(all(st));
    precalc();
    precalc_powers();
    precalc_inverse();
    cin >> q;
    int ss = 1;
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 0; i < 2 * ss; i++) {
        d[i].muls = 1;
        d[i].sum = 1;
        d[i].g.resize(sz(st));
    }
    for (int i = ss - 1; i >= 1; i--) {
        calc(i);
    }
    for (int i = 0; i < n; i++) {
        mul(1, 1, ss, i + 1, i + 1, a[i]);
    }
   // cout << d[1].sum << endl;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            mul(1, 1, ss, l, r, x);
        } else if (t == 2) {
            int p, x;
            cin >> p >> x;
            divide(1, 1, ss, p, x);
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, ss, l, r) << '\n';
        }
    }
    return 0;       
}