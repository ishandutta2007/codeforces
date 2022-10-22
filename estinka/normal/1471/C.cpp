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
        int n, m;
        cin >> n >> m;
        vector<int> k(n);
        for (int i = 0; i < n; i++)
        {
            cin >> k[i];
        }
        vector<ll> c(m);
        for (int i = 0; i < m; i++) cin >> c[i];
        sort(k.begin(), k.end(), greater<int>());
        ll ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i == n || i + 1 > k[i])
            {
                // we'll buy presents for the first i-1 friends
                for (int j = 0; j < i; j++) ans += c[j];
                for (int j = i; j < n; j++) ans += c[k[j] - 1];
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}