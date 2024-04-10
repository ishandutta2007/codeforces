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


    int n;
    cin >> n;
    vector< pair<int, int> > c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }
    int k;
    cin >> k;
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (c[i].second < k) {
            ans--;
        }
    }
    cout << ans << '\n';


    return 0;
}