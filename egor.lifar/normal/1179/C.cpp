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


struct rmqs
{
    vector<int> d;
    vector<int> mod;
    int ss = 1;
    void init(int n) {
        while (ss < n) {
            ss <<= 1;
        }
        d.resize(2 * ss, 0);
        mod.resize(2 * ss, 0);
    }
    void push(int v) {
        if (mod[v] != 0) {
            d[v] += mod[v];
            if (v < ss) {
                mod[v * 2] += mod[v];
                mod[v * 2 + 1] += mod[v];
            }
            mod[v] = 0;
        }
    }
    void add(int v, int vl, int vr, int l, int r, int x) {
        if (vl > r || vr < l) {
            push(v);
            return;
        }
        if  (l <= vl && vr <= r) {
            mod[v] += x;
            push(v);
            return;
        }
        push(v);
        add(v * 2, vl, (vl + vr) / 2, l, r, x);
        add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
        d[v] = max(d[v * 2], d[v * 2 + 1]);
    }
    int rmq(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r) {
            push(v);
            return d[v];
        }
        if (l > vr || vl > r) {
            return -1e9;
        }
        push(v);
        return max(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
    } 
};

 
rmqs kek;
int n, m;
int a[MAXN];
int b[MAXN];


int main() {
    fast_io();
   // read("input");
    kek.init(1000001);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        kek.add(1, 1, kek.ss, 1, a[i], 1);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        kek.add(1, 1, kek.ss, 1, b[i], -1);
    }
    int q;
    cin >> q;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        int g, c;
        cin >> g >> c;
        g--;
        if (t == 1) {
            kek.add(1, 1, kek.ss, 1, a[g], -1);
            a[g] = c;
            kek.add(1, 1, kek.ss, 1, a[g], 1);
        }  else {
            kek.add(1, 1, kek.ss, 1, b[g], 1);
            b[g] = c;
            kek.add(1, 1, kek.ss, 1, b[g], -1);
        }
        //exit(0);
        int l = 1;
        int r = 1000000;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int f = kek.rmq(1, 1, kek.ss, mid, 1000000);
            if (f > 0) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }   
    //    cout << kek.rmq(1, 1, kek.ss, l - 1, 1000000) << endl;
        int f = kek.rmq(1, 1, kek.ss, l, 1000000);
       //cout << f << ' ' << l << endl;
        if (f <= 0) {
            cout << -1 << '\n';
        } else {
            cout << l << '\n';
        }
    }   
    return 0; 
}