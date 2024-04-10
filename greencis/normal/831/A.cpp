#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int status = 0;
    int bad = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] < a[i] && status > 0 || a[i - 1] == a[i] && status > 1)
            bad = 1;
        if (a[i - 1] == a[i])
            status = 1;
        if (a[i - 1] > a[i])
            status = 2;
        if (bad)
            return 0 * puts("NO");
    }
    puts("YES");

    return 0;
}