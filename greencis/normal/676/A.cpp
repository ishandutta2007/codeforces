#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);

    int n, x, p1, pn;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 1)
            p1 = i;
        else if (x == n)
            pn = i;
    }

    cout << max(abs(p1 - pn), max(p1, max(n - 1 - p1, max(pn, n - 1 - pn))));

    return 0;
}