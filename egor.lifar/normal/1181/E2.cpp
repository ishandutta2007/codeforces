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

template<class T1, class T2> inline int chkmin(T1 &x, const T2 &y) {
    if (x > y) {
        x = y;
        return 1;
    }
    else {
        return 0;
    }
}

template<class T1, class T2> inline int chkmax(T1 &x, const T2 &y) {
    if (x < y) {
        x = y;
        return 1;
    }
    else {
        return 0;
    }
}

#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}


template<class T> void output(const T &x, ostream &out = cerr) {
    output(x.begin(), x.end(), out);
}

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
}
const int MAXN = 100228;

int n;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

void solve(set<pair<int, int> > &up, set<pair<int, int> > &down, set<pair<int, int> > &left, set<pair<int, int> > &right);

void add(vector<pair<int, int> > &st, set<pair<int, int> > &up, set<pair<int, int> > &down, set<pair<int, int> > &left, set<pair<int, int> > &right) {
    set<pair<int, int> > up1, down1, left1, right1;
    for (auto x: st) {
        int i = x.second;
        up1.insert({a[i], i});
        up.erase({a[i], i});
         down1.insert({c[i], i});
        down.erase({c[i], i});
         left1.insert({b[i], i});
        left.erase({b[i], i});
         right1.insert({d[i], i});
        right.erase({d[i], i});
    }   
    solve(up1, down1, left1, right1);
    solve(up, down, left, right);
}       


void solve(set<pair<int, int> > &up, set<pair<int, int> > &down, set<pair<int, int> > &left, set<pair<int, int> > &right) {
    if (sz(up) < 4) {
        return;
    }
    auto it = up.begin();
    auto it1 = down.rbegin();
    auto it2 = left.begin();
    auto it3 = right.rbegin();
    int curit = -1e9;
    int curit1 = 1e9;
    int curit2 = -1e9;
    int curit3 = 1e9;
    vector<pair<int, int> > st, st1, st2, st3;
    while (true) {
        if (it != up.end()) {
            st.pb(*it);
            chkmax(curit, c[it->second]);
        }
        if (it1 != down.rend()) {
            st1.pb(*it1);
            chkmin(curit1, a[it1->second]);
        }
        if (it2 != left.end()) {
            st2.pb(*it2);
            chkmax(curit2, d[it2->second]);
        }
        if (it3 != right.rend()) {
            st3.pb(*it3);
            chkmin(curit3, b[it3->second]);
        }
        bool was = false;
        if (it != up.end()) {
            it++;
            if (it != up.end()) {
                was = true;
                if (it->first >= curit) {
                    add(st, up, down, left, right);
                    return;
                }
            }
        }
        if (it1 != down.rend()) {
            it1++;
            if (it1 != down.rend()) {
                was = true;
                if (it1->first <= curit1) {
                    add(st1, up, down, left, right);
                    return;
                }
            }
        }
        if (it2 != left.end()) {
            it2++;
            if (it2 != left.end()) {
                was = true;
                if (it2->first >= curit2) {
                    add(st2, up, down, left, right);
                    return;
                }
            }
        }
        if (it3 != right.rend()) {
            it3++;
            if (it3 != right.rend()) {
                was = true;
                if (it3->first <= curit3) {
                    add(st3, up, down, left, right);
                    return;
                }
            }
        }
        if (!was) {
            cout << "NO\n";
            exit(0);
        }
    }
}


int main() {
    fast_io();
    //read("input");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >>c[i] >> d[i];
    }
    set<pair<int, int> > up, down, left, right;
    for (int i = 0; i < n; i++) {
        up.insert({a[i], i});
        down.insert({c[i], i});
        left.insert({b[i], i});
        right.insert({d[i], i});
    }
    solve(up, down, left, right);
    cout << "YES\n";
    return 0;
}