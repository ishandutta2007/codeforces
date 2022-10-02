/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

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
const int Mod =  998244353;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 100228;


int n;
int a[MAXN], b[MAXN];
int cnt[101], cnt1[101];


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    memset(cnt, 0, sizeof(cnt));
    memset(cnt1, 0, sizeof(cnt1));
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cnt1[b[i]]++;
    }
    for (int k = n; ; k++) {
        cnt[100] += k - n;
        cnt1[0] += k - n;
        int top = k - k / 4;
        int top1 = top;
        int sum = 0;
        int sum1 = 0;
        for (int i = 100; i >= 0; i--) {
            int d = min(top, cnt[i]);
            top -= d;
            sum += d * i;
            int d1 = min(top1, cnt1[i]);
            top1 -= d1;
            sum1 += d1 * i;   
        }
        cnt[100] -= k - n;
        cnt1[0] -= k - n;
        if (sum >= sum1) {
            cout << k - n << '\n';
            return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
   // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}