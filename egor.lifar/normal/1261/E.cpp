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
const int MAXN = 1028;


int n;
int a[MAXN];
vector<bitset<1000>> res;
bool used[MAXN];



void get(vector<int> ids, vector<bitset<1000>> &ans) {
    if (sz(ids) == 1) {
        bitset<1000> k;
        k[ids[0]] = 1;
        if (a[ids[0]]) {
            ans.pb(k);
        }
        return;
    }
    int mind = ids[0];
    for (int i = 0; i < sz(ids); i++) {
        if (a[ids[i]] < a[mind]) {
            mind = ids[i];
        }
    }
    bool was = false;
    bitset<1000> k;
    bitset<1000> g;
    for (int i = 0; i < sz(ids); i++) {
        if (ids[i] != mind) {
            if (a[ids[i]] == sz(ids)) {
                was = true;
                k[ids[i]] = 1;
                a[ids[i]]--;
            }
        }
    }
    if (was) {
        a[mind]--;
        k[mind] = 1;
    }
    vector<int> ids1;
    for (int i = 0; i < sz(ids); i++) {
        if (ids[i] != mind) {
            ids1.pb(ids[i]);
        }
    }
    get(ids1, ans);
    for (int i = 0; i < sz(ans); i++) {
        if (!a[mind]) {
            break;
        }
        ans[i][mind] = 1;
        if (ans[i] != k) {
            a[mind]--;
        } else {
            ans[i][mind] = 0;
        }
    }
    if (a[mind]) {
        g[mind] = 1;
        a[mind]--;
        ans.pb(g);
    }
    if (was) {
        ans.push_back(k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d.pb(i);
    }
    vector<bitset<1000>> res;
    get(d, res);
    assert(sz(res) <= n + 1);
    cout << sz(res) << '\n';
    for (auto x: res) {
        for (int j = 0; j < n; j++) {
            if (x[j] == 1) {
                cout << '1';
            }  else {
                cout << '0';
            }
        }
        cout << '\n';
    }
}