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
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> pf(m + 1, -1), sf(m + 1, n);
    for (int i = 0; i < m; i++)
    {
        pf[i + 1] = pf[i] + 1;
        while (s[pf[i + 1]] != t[i]) pf[i + 1]++;
    }
    for (int i = 0; i < m; i++)
    {
        sf[i + 1] = sf[i] - 1;
        while (s[sf[i + 1]] != t[m - i - 1]) sf[i + 1]--;
    }
    int ans = 0;
    for (int i = 1; i < m; i++)
    {
        ans = max(ans, sf[m - i] - pf[i]);
    }
    cout << ans << "\n";
    return 0;
}