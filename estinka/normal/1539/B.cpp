#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int> > pf(n+1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i-1];
        pf[i][s[i-1] - 'a']++;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            int cnt = pf[r][i] - pf[l-1][i];
            ans += cnt * (i + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}