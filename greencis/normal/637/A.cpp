#include <bits/stdc++.h>
using namespace std;

int n, x, u[1001005], mx = -1, mxi;

int main()
{
    cin >> n;
    while (n--) {
        cin >> x;
        ++u[x];
        if (u[x] > mx)
            mx = u[x], mxi = x;
    }
    cout << mxi;
    return 0;
}