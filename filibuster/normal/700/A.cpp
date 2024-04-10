#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const ld e = 1e-8;

/*
10000 1000000000 1 1000000000 10000
*/


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    li n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;

    ld lf = 0, rg = ld(l) / v2 + 1e-3;
    li p = (n + k - 1) / k;
//    cout << setprecision(10) << fixed;
    for(int j = 0; j < 60; j++) {
        ld m = (lf + rg) / 2;

//        cout << m << ' ' << p * m + ld(v2 - v1) * m / (v2 + v1) * (p - 1) << ' ' <<
//            (l - m * v2) / v1 + m << endl;

        if(p * m + ld(v2 - v1) * m / (v2 + v1) * (p - 1) >
           (l - m * v2) / v1 + m)
            rg = m;
        else
            lf = m;
    }


    cout << setprecision(30) << fixed << (l - lf * v2) / v1 + lf << endl;
}