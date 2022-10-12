#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

const int N = 8005;
ll c[N][N], dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s; int n = s.size();
    for (int i = 0; i < n; i++) {
        auto p = prefix_function(s.substr(i, n));
        for (int j = i; j < n; j++) {
            int k = j+1-p[j-i]-i;
            if ((j-i+1)%k == 0)
                c[i][j] = k+to_string((j-i+1)/k).size();
            else c[i][j] = j-i+2;
        }
    }
    fill(dp+1, dp+N, inf_ll);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] = min(dp[i], dp[j]+c[j][i-1]);
    cout << dp[n] << "\n";
}