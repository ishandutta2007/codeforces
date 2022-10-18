#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, y[200105];
map<int, int> mp;
pair<pii, int> a[200105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> x;
        ++mp[x];
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> y[i];
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[i] = make_pair(make_pair(mp[y[i]], mp[x]), i + 1);
    }
    sort(a, a + n, greater<pair<pii,int>>());
    cout << a[0].second;

    return 0;
}