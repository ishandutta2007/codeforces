// March 11, 2019
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


    int n, k;
    cin >> n >> k;
    if (2 * k > n) {
        k = n + 1 - k;
    }
    cout << 3 * n + k - 1 << '\n';


    return 0;
}