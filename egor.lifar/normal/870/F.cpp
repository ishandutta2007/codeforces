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
const int MAXN = 10000001;


int n;
int prime[MAXN];
char bad[MAXN];
int phi[MAXN];
int cntprimedivs[MAXN];
int minprime[MAXN];
int cntbad = 0;


long long getone() {
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        if (!bad[i]) {
            ans += i - 1 - phi[i];
        }
    }
    return ans;
}


long long gettwo() {
    long long ans = 0;
    int cntprime = 1;
    for (int i = 2; i <= n; i++) {
        if (prime[i] != i) {
            ans += phi[i];
            ans -= cntprime;
            ans += cntprimedivs[i];
        } else {
            cntprime++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            minprime[prime[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        minprime[i] += minprime[i - 1];
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] != i || bad[i]) {
            continue;
        }
        ans += minprime[n / i];
        for (int j = i; j <= n; j += i) {
            if (prime[j] <= n / i) {
                ans--;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        int a = prime[i];
        int b = i / a;
        if (b != 1 && prime[b] == b && a != b) {
            ans--;
        }
    }
    return ans;
}



int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    read(FILENAME);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            continue;
        }
        for (int j = i; j <= n; j += i) {
            if (!prime[j]) {
                prime[j] = i;
            }
            phi[j] /= i;
            phi[j] *= i - 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1 || (prime[i] == i && i * 2 > n)) {
            bad[i] = true;
            cntbad++;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] == i) {
            cntprimedivs[i] = 1;
        } else if (prime[i / prime[i]] == prime[i]) {
            cntprimedivs[i] = cntprimedivs[i / prime[i]];
        } else {
            cntprimedivs[i] = cntprimedivs[i / prime[i]] + 1;
        }
    }
    long long cnt1 = getone();
    long long cnt2 = gettwo();
    long long cnt3 = 1LL * (n - cntbad) * (n - cntbad - 1) / 2 - cnt1 - cnt2;
    cout << cnt1 * 1 + cnt2 * 2 + cnt3 * 3 << '\n';
    return 0;       
}