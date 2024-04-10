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
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 3001;

int n;
string s[MAXN], t[MAXN];
vector<pair<int, int> > post;

bool chesk(string ss, string tt) {
    for (int j = 0; j < n; j++) {
        pair<int, int> pos = make_pair(-1, -1);
            vector<int> z;
            z.resize(sz(s[j]) + 1 + sz(ss));
            string k;
            k += ss;
            k += "#";
            k += s[j];
            for (int i=1, l=0, r=0; i<sz(k); ++i) {
                if (i <= r)
                    z[i] = min (r-i+1, z[i-l]);
                while (i+z[i] < sz(k) && k[z[i]] == k[i+z[i]])
                    ++z[i];
                if (i+z[i]-1 > r)
                    l = i,  r = i+z[i]-1;
            }
            int ff = -1;
            for (int i = sz(ss) + 1; i < sz(k); i++) {
                if (z[i] == sz(ss)) {
                    ff = i - sz(ss) - 1;
                    break;
                }
            }
            if (ff != post[j].first) {
                return false;
            }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    set<pair<string, string> > lens;
    vector<int> ids;
    post.resize(n);
    for (int i = 0; i < n; i++) {
        vector<int> pos;
        for (int j = 0; j < sz(s[i]); j++) {
            if (s[i][j] != t[i][j]) {
                pos.pb(j);
            }
        }
        if (pos.empty()) {
            post[i] = make_pair(-1, -1);
            continue;
        }
        string ka, kb;
        for (int j = pos[0]; j <= pos.back(); j++) {
            ka += s[i][j];
            kb += t[i][j];
        }
        lens.insert({ka, kb});
        ids.pb(i);
        post[i] = {pos[0], pos.back()};
    }
    if (sz(lens) > 1) {
        cout << "NO\n";
        return 0;
    }
    string pr, pr1;
    string suff, suff1;
    int l = 0;
    while (true) {
        bool bad = false;
        pair<char, char> c = make_pair(-1, -1);
        for (auto x: ids) {
            if (post[x].first <= l) {
                bad = true;
                break;
            }
            if (c.first != -1 && c !=  make_pair(s[x][post[x].first - l - 1], t[x][post[x].first - l - 1])) {
                bad = true;
                break;
            }
            if (s[x][post[x].first - l - 1] != t[x][post[x].first - l - 1]) {
                continue;
            }
            c = make_pair(s[x][post[x].first - l - 1], t[x][post[x].first - l - 1]);
        }
        if (bad) {
            break;
        }
        pr += c.first;
        pr1 += c.second;
        l++;
    }
   
    for (int i = 0; i < n; i++) {
        if (post[i].first != -1) {
            post[i].first -= l;
        }
    }
     l = 0;
    while (true) {
        bool bad = false;
        pair<char, char> c = make_pair(-1, -1);
        for (auto x: ids) {
            if (sz(s[x]) - post[x].second - 1 < l + 1) {
                bad = true;
                break;
            }
            if (c.first != -1 && c !=  make_pair(s[x][post[x].second + l + 1], t[x][post[x].second + l + 1])) {
                bad = true;
                break;
            }
            if (s[x][post[x].second + l + 1] != t[x][post[x].second + l + 1]) {
                continue;
            }
            c = make_pair(s[x][post[x].second + l + 1], t[x][post[x].second + l + 1]);
        }
        if (bad) {
            break;
        }
        suff += c.first;
        suff1 += c.second;
        l++;
    }
    reverse(all(pr));
    reverse(all(pr1));
    string ss, tt;
    ss = pr;
    ss += (*lens.begin()).first;
    ss += suff;
    tt = pr1;
    tt += (*lens.begin()).second;
    tt += suff1;
    //cout << ss << ' ' << tt << endl;
    if (!chesk(ss, tt)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << ss << "\n" << tt << '\n';
    return 0;
}