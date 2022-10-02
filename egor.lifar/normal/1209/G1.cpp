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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 200222;



int n, q;
int a[MAXN];
int last[MAXN];
int d[MAXN * 4];
int ss = 1;
int mink[MAXN];
int cnt[MAXN];
int d1[MAXN * 4];
int d2[MAXN * 4];

void change(int i, int val) {
    i += ss;
    i--;
    d[i] = val;
    while (i >> 1 > 0) {
        i >>= 1;
        d[i] = max(d[i * 2], d[i * 2 + 1]);
    }
}


int get(int l, int r) {
    l += ss - 1;
    r += ss - 1;
    int res = 0;
    while (l <= r) {
        if (l & 1) {
            chkmax(res, d[l]);
            l++;
        }
        if (!(r & 1)) {
            chkmax(res, d[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return res;
}

void change2(int i, int val) {
    i += ss;
    i--;
    d2[i] = val;
    while (i >> 1 > 0) {
        i >>= 1;
        d2[i] = max(d2[i * 2], d2[i * 2 + 1]);
    }
}


int get2(int l, int r) {
    l += ss - 1;
    r += ss - 1;
    int res = 0;
    while (l <= r) {
        if (l & 1) {
            chkmax(res, d2[l]);
            l++;
        }
        if (!(r & 1)) {
            chkmax(res, d2[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return res;
}




void change1(int i, int val) {
    i += ss;
    i--;
    d1[i] = val;
    while (i >> 1 > 0) {
        i >>= 1;
        d1[i] = min(d1[i * 2], d1[i * 2 + 1]);
    }
}


int get1(int l, int r) {
    l += ss - 1;
    r += ss - 1;
    int res = 1e9;
    while (l <= r) {
        if (l & 1) {
            chkmin(res, d1[l]);
            l++;
        }
        if (!(r & 1)) {
            chkmin(res, d1[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n >> q;
    for (int i = 1; i <= 200000; i++) {
        mink[i] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        chkmin(mink[a[i]], i);
        last[a[i]] = i;
        cnt[a[i]]++;
    }
    while (ss <= 200000) {
        ss <<= 1;
    }
    for (int i = 0; i < 2 * ss; i++) {
        d[i] = 0;
        d2[i] = 0; 
        d1[i] = 1e9;
    }
    vector<pair<int, int> > st;
    for (int i = 1; i <= 200000; i++) {
        if (last[i]) {
            st.pb({last[i], i});
        }
    }
    sort(all(st));
    vector<pair<int, int> > kek;
    for (auto x: st) {
        int val = 0;
        int ft1 = get1(mink[x.second], x.first);
        chkmin(ft1, mink[x.second] - 1);
        change2(x.first, cnt[x.second]);
        kek.pb({ft1 + 1, x.first});
        change1(x.first, ft1);
    }
    reverse(all(kek));
    int res = 0;
    int last = n + 2;
    for (auto z: kek) {
        if (z.second < last) {
            res += get2(z.first, z.second);
        }
        chkmin(last, z.first);
    }
    cout << n - res << endl;
    return 0; 
}