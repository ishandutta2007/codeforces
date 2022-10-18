#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int x,y,xs,ys,n;
int u[505][505],ans[100005];
char s[100005];
int len;

int main()
{
    cin >> y >> x >> ys >> xs >> s + 1;
    n = strlen(s + 1);
    ans[0] += !u[ys][xs];
    u[ys][xs] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'L') xs = max(1, xs - 1);
        else if (s[i] == 'R') xs = min(x, xs + 1);
        else if (s[i] == 'U') ys = max(1, ys - 1);
        else if (s[i] == 'D') ys = min(y, ys + 1);
        ans[i] += !u[ys][xs];
        u[ys][xs] = 1;
    }
    for (int i = 1; i <= x; ++i)
        for (int j = 1; j <= y; ++j)
            ans[n] += !u[j][i];
    for (int i = 0; i <= n; ++i)
        cout << ans[i] << " ";

    return 0;
}