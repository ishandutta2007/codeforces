#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n;
pair<int, pii> a[100105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second.first;
        a[i].second.second = i;
    }
    sort(a, a + n);
    for (int i = 2; i < n; ++i) {
        if ((a[0].first != a[1].first || (a[0].first == a[1].first && a[i].first != a[1].first))) {
            ll v1x = a[1].first - a[0].first;
            ll v1y = a[1].second.first - a[0].second.first;
            ll v2x = a[i].first - a[0].first;
            ll v2y = a[i].second.first - a[0].second.first;
            ll S = v1x * v2y - v2x * v1y;
            if (S != 0) {
                cout << a[0].second.second + 1 << " "
                     << a[1].second.second + 1 << " "
                     << a[i].second.second + 1;
                return 0;
            }
        }
    }

    return 0;
}