#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;

void solve() {
}

const int N = 1e5 + 13;



int main() {
    li v, u;
    cin >>u >> v;

    if(u > v || (v - u) % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    if(v == u) {
        if(v == 0)
            cout << 0;
        else
            cout << 1 << endl << v;
        return 0;
    }

    li x = (v - u) / 2;

    if((x | u) == x + u) {
        cout << 2 << endl << x << ' ' << u + x << endl;
    } else {
        cout << 3 << endl << x << ' ' << x << ' ' << u << endl;
    }


//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();
}