#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int dp[505][205][205];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s, t; fin >> s >> t;
    for (int i = s.size(); i >= 0; i--)
        for (int j = t.size(); j >= 0; j--) {
            bool rev = ((i == s.size() || s[i] == ')') && (j == t.size() || t[j] == ')'));

            for (int d = (rev ? 501 : 0); (rev ? d >= 0 : d < 502); d += (rev ? -1 : 1)) {

                if (i == s.size() && j == t.size()) {
                    dp[d][i][j] = d;
                    continue;
                }

                int a = i+(i < s.size() && s[i] == '(' ? 1 : 0);
                int b = j+(j < t.size() && t[j] == '(' ? 1 : 0);
                dp[d][i][j] = 1+dp[d+1][a][b];

                if (d > 0) {
                    a = i+(i < s.size() && s[i] == ')' ? 1 : 0);
                    b = j+(j < t.size() && t[j] == ')' ? 1 : 0);
                    dp[d][i][j] = min(dp[d][i][j], 1+dp[d-1][a][b]);
                }

                if (d < 1) debug(d, i, j, dp[d][i][j]);
            }
        }

    int d = 0, i = 0, j = 0;

    for (int len = dp[0][0][0]; len > 0; len--) {
        int a = i+(i < s.size() && s[i] == '(' ? 1 : 0);
        int b = j+(j < t.size() && t[j] == '(' ? 1 : 0);
        if (dp[d+1][a][b] == len-1) {
            d++; i = a; j = b;
            cout << '(';
        } else {
            a = i+(i < s.size() && s[i] == ')' ? 1 : 0);
            b = j+(j < t.size() && t[j] == ')' ? 1 : 0);
            d--; i = a; j = b;
            cout << ')';
        }
    }

    cout << "\n";
}