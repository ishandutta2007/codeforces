#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
pii a[100105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    if (n == 1 || a[0].first < a[1].first)
        cout << a[0].second;
    else
        cout << "Still Rozdil";

    return 0;
}