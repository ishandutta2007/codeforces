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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll k2 = k;
        if (k < n) k = (n / k) * k;
        if (k < n) k += k2;
        cout << "            ";
        cout << (k + n - 1) / n << "\n";
    }
     return 0;
}