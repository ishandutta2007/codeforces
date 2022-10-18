#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,c[999],r[999];
char s[105][105];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i] + 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            c[j] += s[i][j] == 'C', r[i] += s[i][j] == 'C';
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += c[i] * (c[i] - 1) / 2 + r[i] * (r[i] - 1) / 2;
    cout << ans;

    return 0;
}