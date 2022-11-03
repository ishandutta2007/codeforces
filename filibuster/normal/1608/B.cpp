#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if(n - 2 < a + b || max(a, b) > (n - 1) / 2 || a > b + 1 || b > a + 1) {
        cout << -1 << endl;
        return;
    }

    int l = b + 1, r = n - a;

    bool fl = false;


    vector<int> res;

    if(a == b) {
        res.push_back(l);
        l++;

        for(int i = 0; i < b; i++) {
//            cout << n - a + i + 1 << ' ' << i + 1 << ' ';
            res.push_back(n - a + i + 1);
            res.push_back(i + 1);
        }

        for(int i = l; i <= r; i++)
            res.push_back(i);
//            cout << i << ' ';
//        cout << endl;
    } else if(a > b) {
        res.push_back(r);
        r--;

        for(int i = 0; i < b; i++) {
            res.push_back(n - a + i + 1);
            res.push_back(i + 1);
        }

        res.push_back(n);
        for(int i = r; i >= l; i--)
            res.push_back(i);
    } else {
        res.push_back(l);

        l++;

        for(int i = 0; i < a; i++) {
//            cout << i + 1 << ' ' << n - a + i + 1 << ' ';
            res.push_back(i + 1);
            res.push_back(n - a + i + 1);

        }

//        fl =

//        cout << b << ' ';
        res.push_back(b);
        for(int i = l; i <= r; i++)
            res.push_back(i);
//            cout << i << ' ';
//        cout << endl;
    }

    for(auto x : res)
        cout << x << ' ';
    cout << endl;

//    for(int i = 0; i < n - 2; i++) {
//        if(a > 0) {
//            cout << n - a + 1 << ' ';
//            a--;
//        }
//
//        if(b > 0) {
//            cout << b << ' ';
//            b--;
//        }
//
//        if(l < r) {
//            cout << l << ' ';
//            l++;
//        }
//    }

//    cout << r << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}