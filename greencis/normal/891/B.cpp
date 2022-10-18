#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, b[25];
pii a[25];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        b[a[i].second] = a[(i + 1) % n].first;
    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}