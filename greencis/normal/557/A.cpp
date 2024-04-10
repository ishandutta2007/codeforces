#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,mn[3],mx[3],a;

int main()
{
    cin >> n >> mn[0] >> mx[0] >> mn[1] >> mx[1] >> mn[2] >> mx[2];

    n -= mn[0];
    n -= mn[1];
    n -= mn[2];

    if (n) {
        a = min(n, mx[0] - mn[0]);
        mn[0] += a;
        n -= a;
    }

    if (n) {
        a = min(n, mx[1] - mn[1]);
        mn[1] += a;
        n -= a;
    }

    if (n) {
        a = min(n, mx[2] - mn[2]);
        mn[2] += a;
        n -= a;
    }

    cout << mn[0] << " " << mn[1] << " " << mn[2];

    return 0;
}