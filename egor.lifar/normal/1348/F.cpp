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
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 200228;



int n;
int a[MAXN], b[MAXN];
int c[MAXN];
vector<pair<int, int> > g[MAXN];


bool ok(int i, int val) {
    return a[i] <= val && val <= b[i];
}


int who[MAXN];
vector<int> ending[MAXN];


int main() {
   	ios_base::sync_with_stdio(false);
   	cin.tie(0);
   	cout.tie(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        g[a[i]].pb({b[i], i});
    }    
    set<pair<int, int> > s;
    for (int i = 1; i <= n; i++) {
        for (auto x: g[i]) {
            s.insert(x);
        }
        auto x = *s.begin();
        s.erase(x);
        c[x.second] = i;
    }
    for (int i = 0; i < n; i++) {
        who[c[i]] = i;
     //   cout << c[i] << ' ';
        ending[b[i]].pb(i);
    }
   // cout << endl;
    for (int i = 1; i <= n; i++) {
        if (!s.empty()) {
            auto x = *s.rbegin();
            int t = x.second;
            if (x.first >= a[who[i]]) {
               // cout << t << ' ' << x.first << ' ' << who[i] << ' ' << i << endl;
                assert(ok(t, i) && ok(who[i], c[t]));
            }
            if (ok(t, i) && ok(who[i], c[t])) {
                cout << "NO\n";
                for (int is = 0; is < n; is++) {
                    cout << c[is] << ' ';
                }
                cout << '\n';
                swap(c[t], c[who[i]]);
                for (int is = 0; is < n; is++) {
                    cout << c[is] << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
        s.insert(mp(i, who[i]));
        for (auto x: ending[i]) {
            s.erase(mp(c[x], x));
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (ok(i, c[i + 1]) && ok(i + 1, c[i])) {
            cout << "NO\n";
            for (int is = 0; is < n; is++) {
                cout << c[is] << ' ';
            }
            cout << '\n';
            swap(c[i], c[i + 1]);
            for (int is = 0; is < n; is++) {
                cout << c[is] << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
    }
    cout << '\n';
}