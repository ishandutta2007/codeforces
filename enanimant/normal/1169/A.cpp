// May 26, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug_output.txt", "w", stderr);
#endif


    int n, a, b, x, y;
    cin >> n >> a >> x >> b >> y;
    int same = false;
    while (a != x && b != y) {
        a++;
        if (a == n + 1) {
            a = 1;
        }
        b--;
        if (b == 0) {
            b = n;
        }
        if (a == b) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";


    return 0;
}