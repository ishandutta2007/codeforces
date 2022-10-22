#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> q >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0, l, r; i < q; i++)
    {
        cin >> l >> r;
        l--; r--;
        int out = k - (a[r] - a[l] + 1);
        int in = a[r] - a[l] + 1 - (r - l + 1);
        cout << out + in * 2 << "\n";
    }
    return 0;
}