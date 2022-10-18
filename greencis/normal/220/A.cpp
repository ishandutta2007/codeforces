#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
vector<int> a, b;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    b = a;
    sort(b.begin(), b.end());
    int x = 0;
    for (int i = 0; i < n; ++i)
        x += a[i] != b[i];
    cout << (x == 0 || x == 2 ? "YES" : "NO");

    return 0;
}