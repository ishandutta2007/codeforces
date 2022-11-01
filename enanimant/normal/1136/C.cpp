// March 11, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int n, m;
int A[500][500], B[500][500];
map<int, int> sa[999], sb[999];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug_output.txt", "w", stderr);
#endif


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            sa[i + j][A[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> B[i][j];
            sb[i + j][B[i][j]]++;
        }
    }
    for (int d = 0; d < n + m - 1; d++) {
        for (auto p : sa[d]) {
            if (sb[d][p.first] != p.second) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";


    return 0;
}