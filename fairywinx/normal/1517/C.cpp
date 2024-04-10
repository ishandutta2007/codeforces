#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <random>
#include <ctime>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        int u = a;
        array<int, 2> j;
        j[0] = i, j[1] = i;
        ans[i].resize(n, -1);
        while (a) {
            ans[j[0]][j[1]] = u;
            if (a == 1)
                break;
            // cout << j[0] << ':' << j[1] << ' ';
            if (j[0] > 0 && ans[j[0] - 1][j[1]] == -1) {
                j[0]--;
            } else{
                j[1]++;
            }
            --a;
            // cout << j[0] << ' ' << j[1] << '\n';
            // if (ans[j[0]][j[1]] != -1)
            //     exit(1);
        }
        // cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << ans[j][i] << ' ';
    cout << '\n';
    }
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
    //     solve();
    solve();
}