#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ll n,a[100105],sum;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    if (sum % 2) {
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2) {
                sum -= a[i];
                break;
            }
        }
    }
    cout << sum;

    return 0;
}