#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int n;
vector<int> a = {5, 1, 4, 2, 3};

//int get(int l, int r) {
//    int mx1 = l, mx2 = -1;
//    for(int i = l + 1; i < r; i++) {
//        if(a[i] > a[mx1]) {
//            mx2 = mx1;
//            mx1 = i;
//        } else if(mx2 == -1 || a[mx2] < a[i]) {
//            mx2 = i;
//        }
//    }
//
//    return mx2;
//}

map<pii, int> mp;

int get(int l, int r) {
    if(mp.count({l, r}))
        return mp[{l, r}];

    cout << "? " << l + 1 << ' ' << r << endl;

    int x;
    cin >> x;

    x--;

    return mp[{l, r}] = x;
}

int main() {
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    cin >> n;

    int i = get(0, n);

    int l = 0, r = n;
    while(r - l > 3) {
        int m = (l + r) / 2;

        int j = (i < m ? get(l, m) : get(m, r));
        if(j == i) {
            if(i < m)
                r = m;
            else
                l = m;
        } else {
            if(i < m)
                l = m;
            else
                r = m;
        }

        i = j;

        if(i < l || i >= r)
            i = get(l, r);
    }

//    cout << "ans " << l << ' ' << r << endl;

    int ans = l;

    if(r - l == 2) {
//        int j = get(l, r);
        ans = l ^ (l + 1) ^ i;
    } else if(r - l == 3) {
        if(i == l) {
            int j = get(l, l + 2);
            if(j == i)
                ans = l + 1;
            else
                ans = l + 2;
        } else if(i == l + 1) {
            int j = get(l, l + 2);
            if(i == j)
                ans = l;
            else
                ans = l + 2;
        } else {
            int j = get(l + 1, l + 3);
            if(j == i)
                ans = l + 1;
            else
                ans = l;
        }
    }

    cout << "! " << ans + 1 << endl;

//    ans(l);
}