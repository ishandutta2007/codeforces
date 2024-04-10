#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 500 + 13;


/*

*/

bool dp[N][N];
int a[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);


    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = k - a[i]; j >= 0; j--) {
            for(int l = j; l >= 0; l--) {
                if(dp[j][l]) {
                    dp[j + a[i]][l] = true;
                    dp[j + a[i]][l + a[i]] = true;
                }
            }
        }
    }

    vector<int> b;
    for(int i = 0; i <= k; i++)
        if(dp[k][i])
            b.push_back(i);

    cout << b.size() << endl;
    for(auto x : b)
        cout << x << ' ';
}