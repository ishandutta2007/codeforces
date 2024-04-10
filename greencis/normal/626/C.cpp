#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n, m;

int main()
{
    cin >> n >> m;
    int L = 0, R = 10000000;
    while (L < R) {
        int mid = (L + R) / 2;
        int cnt2 = mid / 2 - mid / 6, cnt3 = mid / 3 - mid / 6, cnt6 = mid / 6;
        int mx1 = max(n - cnt2, 0);
        int mx2 = max(m - cnt3, 0);
        if (mx1 + mx2 <= cnt6)
            R = mid;
        else L = mid + 1;
    }
    cout << L;

    return 0;
}