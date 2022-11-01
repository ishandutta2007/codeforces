// July 5, 2018
// http://codeforces.com/contest/1004/problem/B

#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int x = 0;
    for (int i = 0; i < n; i++) {
        x ^= 1;
        cout << x;
    }
    cout << '\n';



    return 0;
}