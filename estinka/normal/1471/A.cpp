#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        ll mini = 0, maxi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mini += a[i];
            maxi += (a[i] + x - 1) / x;
        }
        mini = (mini + x - 1) / x;
        cout << mini << " " << maxi << "\n";
    }
    return 0;
}