#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[105], ones, curzero, ans;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int left_zeroes = 0;
    for (int i = 0; i < n; ++i)
        left_zeroes += !a[i];
    for (int i = n - 1; i >= 0; --i) {
        if (a[i])
            ++ones;
        else
            --left_zeroes;
        ans = max(ans, left_zeroes + ones);
    }
    ans = max(ans, n - ones);
    cout << ans << endl;

    return 0;
}