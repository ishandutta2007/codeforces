#include <iostream>
#include <string>

using namespace std;

const int mod = 1e9 + 7;
string s, t;
int dp[2][5001] = {{0}}, ans = 0;

int main(void)
{
    int i, j;
    cin >> s >> t;
    for (i = 0; i < (int)s.length(); ++i)
    {
        for (j = 0; j < (int)t.length(); ++j)
            dp[(i + 1) % 2][j + 1] = (dp[(i + 1) % 2][j] + (s[i] == t[j]) * (dp[i % 2][j] + 1)) % mod;
        ans = (ans + dp[(i + 1) % 2][(int)t.length()]) % mod;
    }
    cout << ans;
    return 0;
}