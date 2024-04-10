#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,a[505],pal[505][505],dp[505][505];

int f(int L, int R) {
    if (L > R) return 1e9;
    if (pal[L][R]) return 1;
    if (!dp[L][R]) {
        int ans = 1e9;
        for (int i = L; i < R; ++i) 
            ans = min(ans, f(L, i) + f(i + 1, R));
        if (a[L] == a[R]) ans = min(ans, f(L + 1, R - 1));
        dp[L][R] = ans + 1;
    }
    return dp[L][R] - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int L = i, R = i;
        while (L >= 1 && R <= n && a[L] == a[R]) {
            pal[L][R] = 1;
            --L; ++R;
        }
        L = i, R = i + 1;
        while (L >= 1 && R <= n && a[L] == a[R]) {
            pal[L][R] = 1;
            --L; ++R;
        }
    }
    cout << f(1, n);

    return 0;
}