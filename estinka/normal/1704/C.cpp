#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
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
        vector<ll> l;
        vector<ll> a(m);
        for (int i = 0; i < m; i++) cin >> a[i], a[i]--;
        sort(a.begin(), a.end());
        for (int i = 0; i + 1 < m; i++) l.push_back(a[i + 1] - a[i] - 1);
        l.push_back(n + a[0] - a[m - 1] - 1);
        sort(l.begin(), l.end(), greater<ll>());
        ll pr = 0, t = 0;
        for (int i = 0; i < l.size(); i++)
        {
            ll len = 0;
            if (l[i] == t * 2 + 1) len = 1, t++;
            if (l[i] >= t * 2 + 2) len = l[i] - t * 2 - 1, t += 2; // kolko vieme zachranit
            pr += len;
        }
        //cout << "                     ";
        cout << n - pr << "\n";
    }
    return 0;
}