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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 200228;


int n;
int a[MAXN];
bool used[MAXN];
vector<pair<int, int> > ans;


void mySwap(int i, int j){
    swap(a[i], a[j]);
    a[i] = -a[i];
    a[j] = -a[j];
    ans.pb(mp(i, j));
}


void swapCycle(int i, int j) {
    mySwap(i, j);
    int uk = i;
    while (a[-a[uk]] > 0) {
        mySwap(uk, -a[uk]);
    }
    uk = -a[uk];
    while (a[-a[uk]] > 0) {
        mySwap(uk, -a[uk]);
    }
    mySwap(uk, -a[uk]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  //read(FILENAME);
    cin >> n;
    for (int x = 1; x <= n; x++) {
        cin >> a[x];
    }
    int p = -1;
    for (int x = 1; x <= n; x++) {
        if (!used[x]) {
            if (a[x] == x) {
                continue;
            }
            int uk = x;
            do {
                used[uk] = true;
                uk = a[uk];
            } while (uk != x);
            if (p == -1) {
                p = x;
            } else {
                swapCycle(p,x);
                p = -1;
            }
        }
    }
    if (p != -1) {
        bool can = false;
        for (int x = 1; x <= n; x++) {
            if (a[x] == x) {
                swapCycle(p, x);
                can = true;
                break;
            }
        }
        if (!can) {
            int t1 = a[p], t2 = a[a[p]];
            mySwap(p, t1);
            swapCycle(t1, t2);
        }
    }
    cout << sz(ans) << endl;
    for (auto x: ans) {
        cout << x.first << ' ' << x.second << '\n';
    }
}