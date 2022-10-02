// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//#include "grader.h"
#include <iostream>
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
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

using namespace std;

const string FILENAME = "input";
const int MAXN = 2e5 + 1, p = 1e9 + 7;

int n, m;
int used[MAXN];
vector <int> arr[MAXN];

int mul(long long a, int b) {
    return (a * b) % m;
}

int powx(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int fi(int k) {
    int cnt = 0;
    for (int i = 2; i < k; i++) {
        if (__gcd(i, k) == 1) {
            cnt++;
        }
    }
    return cnt;
 }

int rev[MAXN];
int dp[MAXN], way[MAXN];

int dev(int a, int b) {
    if (b == 0) return 0;
    int d = __gcd(m, a);
    return mul(b / d, rev[a / d]);
}

int main() {
	ios::sync_with_stdio(0);
    //read(FILENAME);
	//freopen("input", "r", stdin);
	//freopen("output", "w", stdout);
	cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        used[a] = 1;
    }
    int f = fi(m);
    //cout << f << endl;
    for (int i = 0; i < m; ++i) {
        rev[i] = powx(i, f);
        //cout << rev[i] << ' ';
        if (used[i]) continue;
        arr[__gcd(i, m)].pb(i);
    }
    //cout << endl;
    for (int i = m; i >= 1; --i) {
        dp[i] = arr[i].size();
        for (int j = i + i; j <= m; j += i) {
            if (arr[j].size() == 0) continue;
            if ((dp[j] + arr[i].size()) > dp[i]) {
                way[i] = j;
                dp[i] = (dp[j] + arr[i].size());
            }
        }
    }
    cout << dp[1] << endl;
    int i = 1, lst = 1, pr = 1;
    while (i != 0) {
        for (int j: arr[i]) {
            pr *= dev(lst, j);
            pr %= m;
            //cout << pr << '!';
            cout << dev(lst, j) << ' ';
            //cout << j << ' ';
            lst = j;
        }
        i = way[i];
    }
}