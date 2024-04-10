#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, a[105];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
    for (int k = j + 1; k < n; ++k) {
        if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k] &&
            abs(a[i] - a[j]) <= 2 && abs(a[k] - a[j]) <= 2 && abs(a[i] - a[k]) <= 2) {
                cout << "YES"; return 0;
            }
    }cout << "NO";

    return 0;
}