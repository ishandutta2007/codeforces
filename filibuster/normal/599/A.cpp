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

/*
7 400000
0 1
0 5
0 6
1 2
1 4
2 3

*/



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int res = min(a * 2 + b * 2, a + b + c);
    res = min(res, a * 2 + c * 2);
    res = min(res, b * 2 + c * 2);

    cout << res << endl;

}