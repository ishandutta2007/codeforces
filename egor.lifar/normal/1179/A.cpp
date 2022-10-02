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
const int MAXN = 300228;


int n, qs;
int a[MAXN];

 
int main() {
    fast_io();
    //read("input");
    cin >> n >> qs;
    deque<int> q;
    int ress = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q.push_back(a[i]);
        chkmax(ress, a[i]);
    }
    vector<pair<int, int> > st;
    while (true) {
        int a = q.front();
        if (a == ress) {
            break;
        }
        q.pop_front();
        int b = q.front();
        q.pop_front();
        st.pb({a, b});
        if (a > b) {
            q.push_front(a);
            q.push_back(b);
        } else {
            q.push_front(b);
            q.push_back(a);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        res.pb(q.front());
        q.pop_front();
    }
    for (int i = 0; i < qs; i++) {
        long long cnt;
        cin >> cnt;
        if (cnt <= sz(st)) {
            cout << st[cnt - 1].first << ' ' << st[cnt - 1].second << '\n';
        }  else {
            cout << res[0] << ' ' << res[1 + (cnt - sz(st) - 1) % (sz(res) - 1)] << '\n';
        }
    }
    return 0; 
}