#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 3e5 + 13;
const int B = 350;
const int A = 26;

int dp[A][A];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < A; i++)
        for(int j = 0; j < A; j++)
            dp[i][j] = -1;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int a = s[0] - 'a';
        int b = s[s.size() - 1] - 'a';

        for(int x = 0; x < A; x++) {
            if(dp[x][a] != -1) {
                dp[x][b] = max(dp[x][b], dp[x][a] + int(s.size()));
            }
        }
        dp[a][b] = max(dp[a][b], int(s.size()));
    }

    int ans = 0;
    for(int i = 0; i < A; i++)
        ans = max(ans, dp[i][i]);
    cout << ans << endl;
}