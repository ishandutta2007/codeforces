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
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 100228;


long long gettr(long long A, long long B, long long C) {
    if (C < 0) {
        return 0;
    }
    if (A > B) {
        swap(A, B);
    }
    long long p = C / B;
    long long k = B / A;
    long long d = (C - p * B) / A;
    return gettr(B - k * A, A, C - A * (k * p + d + 1)) + (p + 1) * (d + 1) + k * p * (p + 1) / 2;
}


long long get(long long A, long long cnta, long long B, long long cntb, long long C) {
    if (C >= A * cnta + B * cntb) {
        return cnta * cntb;
    }
    if (C < 0) {
        return 0;
    }
    return gettr(A, B, C) - gettr(A, B, C - A * cnta) - gettr(A, B, C - B * cntb) + gettr(A, B, C - A * cnta - B * cntb);
}



int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int n;
int a[MAXN];
int d[MAXN * 4];
long long cnt[MAXN];


int spusk(int v, int vl, int vr, int l, int x) {
    if (d[v] % x == 0) {
        return -1;
    }
    if (vr < l) {
        return -1;  
    }
    if (vl == vr) {
        return vl;
    }
    int t = spusk(v * 2, vl, (vl + vr) / 2, l, x);
    if (t != -1) {
        return t;
    }
    return spusk(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, x);
}

long long pref[MAXN];
long long prefs[MAXN];



long long check(long long mid) {
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (cnt[i] > 0) {
            long long s = min(cnt[i], mid / i);
            ans += s * (cnt[i] + 1) - s * (s + 1) / 2;
        }
    }
    int uk = 1;
    for (int i = 1; i < n; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        if (i < uk) {
            ans += cnt[i] * (pref[uk - 1] - pref[i]);
        }
        while (uk < n && prefs[uk] - prefs[i] <= mid) {
            if (i < uk && cnt[uk] > 0) {
                ans += get(i, cnt[i], uk, cnt[uk], mid - (prefs[uk - 1] - prefs[i]) - i - uk);
            }
            uk++;
        }
        if (uk == n) {
            continue;
        }
        ans += get(i, cnt[i], uk, cnt[uk], mid - (prefs[uk - 1] - prefs[i]) - i - uk);
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    int ss = 1;
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[ss + i] = a[i];
    }
    for (int i = ss - 1; i >= 1; i--) {
        d[i] = gcd(d[i * 2], d[i * 2 + 1]);
    }
    for (int i = 0; i < n; i++) {
        int cur = i;
        int need = 0;
        while (cur < n) {
            need = gcd(need, a[cur]);
            int pos = spusk(1, 1, ss, cur + 1, need) - 1;
            if (pos == -2) {
                pos = n;
            }
            cnt[need] += pos - cur;
            cur = pos;
        }
    }
    long long m = 1LL * n * (n + 1) / 2;
    m = m * (m + 1) / 2;
    m = (m + 1) / 2;
    n = 100001;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + cnt[i];
        prefs[i] = prefs[i - 1] + cnt[i] * i;
    }
    long long l = 1, r = prefs[n - 1];
    while (l != r) {
        long long mid = (l + r) / 2;
        if (check(mid) >= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << '\n';
    return 0; 
}