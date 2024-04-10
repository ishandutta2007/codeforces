#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1000 + 13;

/*
*/

void solve() {
    int n, k;
    cin >> n >> k;

    int m = 3;

    vector<string> s(m);
    for(int i = 0; i < m; i++) {
        cin >> s[i];
    }

    vector<vector<bool>> dp(m, vector<bool> (n, false));
    for(int i = 0; i < m;i++) {
        for(int j = n - 2; j < n; j++)
            if(s[i][j] == '.')
                dp[i][j] = true;
    }

    for(int j = n - 3; j >= 0; j--) {
        for(int i = 0; i < m; i++) {
            if(s[i][j + 1] != '.')
                continue;

            for(int l = 0; l < m; l++)
                if(abs(l - i) <= 1) {
                    bool fl = false;
                    for(int x = j + 1; x < min(n, j + 4); x++)
                        if(s[l][x] != '.') {
                            fl = true;
                            break;
                        }

                    if(!fl)
                        dp[i][j] = dp[i][j] || dp[l][min(j + 3, n - 1)];
                }
        }
    }


    int beg = 0;
    for(int i = 0; i < m; i++)
        if(s[i][0] == 's')
            beg = i;

    cout << (dp[beg][0] ? "YES" : "NO") << endl;
    return;

    if(s[beg][1] != '.') {
        cout << "NO" << endl;
        return;
    }

    for(int i = 0; i < m; i++) {
        if(abs(i - beg) <= 1 && dp[i][1]) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}