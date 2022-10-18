#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[200105];
int mx = 2.1e9, mxc = 0;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i + 1 < n; ++i) {
        int x = a[i + 1] - a[i];
        if (x < mx)
            mx = x, mxc = 1;
        else if (x == mx)
            ++mxc;
    }

    cout << mx << " " << mxc << endl;

    return 0;
}