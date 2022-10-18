#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, ans[5004];
int z[5004][5004];
char zz[5004][5004];
char u[5004][5004];
char s[5004];

vector<int> z_function(string s) {
    int n = (int)s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s;
    string ss = s;
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        string str = s;
        str = str.substr(i, n - i);
        vector<int> curz = z_function(str);
        for (int j = 0; j < n - i; ++j)
            z[j][i] = curz[j];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i)
            zz[len][i] = z[len - len / 2][i] >= len / 2;
    }

    for (int i = 0; i < n; ++i)
        u[i][i] = 1;
    for (int i = 0; i + 1 < n; ++i)
        if (s[i] == s[i + 1])
            u[i][i + 1] = 1;
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            if (s[i] == s[i + len - 1])
                u[i][i + len - 1] = u[i + 1][i + len - 2];
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans[1] += u[i][j];

    for (int iter = 2; iter <= 13 && iter <= n; ++iter) {
        for (int len = n; len >= 2; --len) {
            int len2 = len >> 1;
            for (int i = 0; i + len <= n; ++i) {
                if (!u[i][i + len2 - 1] || !u[i + len - len2][i + len - 1] || !zz[len][i])
                    u[i][i + len - 1] = 0;
                else
                    ++ans[iter];
            }
        }

        if (iter == 2)
            for (int i = 0; i < n; ++i)
                u[i][i] = 0;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}