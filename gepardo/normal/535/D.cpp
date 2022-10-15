#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, k;
    string s;
    cin >> k >> m;
    getline(cin, s);
    getline(cin, s);
    n = s.length();
    vector <int> z(n), v(m);
    for (int i = 0; i < m; i++) cin >> v[i];
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r) z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    int rd;
    if (m == 0) rd = 0; else rd = n;
    for (int i = 1; i < m; i++)
    {
        rd += n;
        int p = v[i] - v[i - 1];
        if (p >= n) continue;
        if (z[p] < (n - p))
        {
            cout << 0;
            return 0;
        }
        rd -= (n - p);
    }
    rd = k - rd;
    long long ans = 1, p = 26;
    for (int i = 0; i < rd; i++)
        ans = (ans * p) % 1000000007;
    cout << ans;
}