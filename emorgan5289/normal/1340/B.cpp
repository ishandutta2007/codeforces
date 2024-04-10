#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int digit[] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
    vector<int> a(n); for (auto& x : a) {
        string num; cin >> num;
        x = stoi(num, 0, 2);
    }
    dp[n][0] = 1;
    string out = "";

    for (int i = n-1; i >= 0; i--)
        for (int x = 0; x <= k; x++)
            for (int j = 0; j < 10; j++) {
                if ((a[i]&(~digit[j])) == 0) {
                    int c = x-__builtin_popcount(a[i]^digit[j]);
                    if (c >= 0)
                        dp[i][x] = dp[i][x] || dp[i+1][c];
                }
            }

    if (!dp[0][k]) {
        cout << "-1\n"; return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 9; j >= 0; j--)
            if ((a[i]&(~digit[j])) == 0) {
                int c = k-__builtin_popcount(a[i]^digit[j]);
                if (c >= 0 && dp[i+1][c]) {
                    k = c;
                    out += to_string(j);
                    break;
                }
            }
    }

    cout << out << "\n";
}