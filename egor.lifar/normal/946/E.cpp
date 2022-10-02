
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


int t;


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  // read(FILENAME);
    cin >> t;
    for (int it = 0; it < t; it++) {
        string s;
        cin >> s;
        string ans;
        if (sz(s) > 2) {
            int f = sz(s) - 1;
            if (f & 1) {
                f--;
            }
            for (int i = 0; i < f; i++) {
                ans += '9';
            }
        }
        int last = -1;
        for (int i = 0; i < sz(s) / 2; i++) {
            if (s[i] > '1' || (i != 0 && s[i] == '1')) {
                last = i;
                // string kek;
                // for (int j = 0; j < i; j++) {
                //     kek += s[j];
                // }
                // kek += s[i] - 1;
                // for (int j = i + 1; j < sz(s) / 2; j++) {
                //     kek += '9';
                // }
                // string kek1 = kek;
                // sort(all(kek1));
                // reverse(all(kek1));
                // kek += kek1;
                // if (sz(ans) < sz(kek)) {
                //     ans = kek;
                // } else {
                //     chkmax(ans, kek);
                // }
            }
        }
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < sz(s) / 2; i++) {
            cnt[s[i] - '0']++;
        }
        for (int i = sz(s) / 2; i < sz(s); i++) {
            if (s[i] >= '1') {
                for (char c = s[i] - 1; c >= '0'; c--) {
                    cnt[c - '0']++;
                    vector<int> need;
                    for (int j = 0; j <= 9; j++) {
                        if (cnt[j] & 1) {
                            need.push_back(j);
                        }
                    }
                    int have = sz(s) - i - 1;
                    if (have >= sz(need)) {
                        if ((have - sz(need)) % 2 == 0) {
                            last = i;
                            // string lol;
                            // for (auto x: need) {
                            //     lol += char('0' + x);
                            // }
                            // for (int i = 0; i < have - sz(need); i++) {
                            //     lol += '9';
                            // }
                            // sort(all(lol));
                            // reverse(all(lol));
                            // string kek;
                            // for (int j = 0; j < i; j++) {
                            //     kek += s[j];
                            // }
                            // kek += c;
                            // kek += lol;
                            // if (sz(ans) < sz(kek)) {
                            //     ans = kek;
                            // } else {
                            //     chkmax(ans, kek);
                            // }
                        }
                    }
                    cnt[c - '0']--;
                }
            } 
            cnt[s[i] - '0']++;
        }
        if (last == -1) {
            cout << ans << '\n';
            continue;
        }
        if (last < sz(s) / 2) {
             string kek;
                 memset(cnt, 0, sizeof(cnt));
                for (int j = 0; j < last; j++) {
                    kek += s[j];
                    cnt[s[j] - '0']++;
                }
                kek += s[last] - 1;
                cnt[s[last] - 1 - '0']++;
                vector<int> need;
                for (int j = 0; j <= 9; j++) {
                    if (cnt[j] & 1) {
                        need.push_back(j);
                    }
                }
                string kek1;
                for (auto x: need) {
                    kek1 += char('0' + x);
                }
                 for (int j = last + sz(need); j < sz(s) - 1; j++) {
                    kek1 += '9';
                }
                sort(all(kek1));
                reverse(all(kek1));
                kek += kek1;
                if (sz(ans) < sz(kek)) {
                    ans = kek;
                } else {
                    chkmax(ans, kek);
                }
        } else {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < sz(s) / 2; i++) {
            cnt[s[i] - '0']++;
        }
            for (int i = sz(s) / 2; i < sz(s); i++) {
            if (s[i] >= '1') {
                for (char c = s[i] - 1; c >= '0'; c--) {
                    cnt[c - '0']++;
                    vector<int> need;
                    for (int j = 0; j <= 9; j++) {
                        if (cnt[j] & 1) {
                            need.push_back(j);
                        }
                    }
                    int have = sz(s) - i - 1;
                    if (have >= sz(need)) {
                        if ((have - sz(need)) % 2 == 0) {
                            if (last == i) {
                            string lol;
                            for (auto x: need) {
                                lol += char('0' + x);
                            }
                            for (int i = 0; i < have - sz(need); i++) {
                                lol += '9';
                            }
                            sort(all(lol));
                            reverse(all(lol));
                            string kek;
                            for (int j = 0; j < i; j++) {
                                kek += s[j];
                            }
                            kek += c;
                            kek += lol;
                            if (sz(ans) < sz(kek)) {
                                ans = kek;
                            } else {
                                chkmax(ans, kek);
                            }
                            break;
                            }
                        }
                    }
                    cnt[c - '0']--;
                }
            }
            cnt[s[i] - '0']++; 
            }
        }
        cout << ans << '\n';
    }
    return 0;     
}