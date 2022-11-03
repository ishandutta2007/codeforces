#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 5000;
const int A = 1e6 + 13;

/*
3
177650 578041 907590

329549 45091

*/

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2 || y1 == y2)
        cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    else
        cout << abs(x1 - x2) + abs(y1 - y2) + 2 << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}