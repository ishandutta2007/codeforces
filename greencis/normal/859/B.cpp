#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = 2e9;
    for (int h = 1; h <= n; ++h) {
        int w = (n + h - 1) / h;
        ans = min(ans, w + w + h + h);
    }
    cout << ans << endl;

    return 0;
}