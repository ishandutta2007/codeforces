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
    const int maxa = 1e6 + 79;
    vector<int> primes;
    for (ll i = 2; i * i <= maxa; i++)
    {
        bool prime = true;
        for (ll j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime) primes.push_back(i);
    }
    int t;
    cin >> t;
    vector<vector<int> > f(maxa);
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            for (int& j : primes)
            {
                while (a[i] % (j * j) == 0) a[i] /= (j * j);
            }
            m[a[i]]++;
        }
        int ans0 = 0, ans1 = 0, plus1 = 0;
        for (pair<int, int> i : m)
        {
            ans0 = max(ans0, i.second);
            if ((i.first == 1) || !(i.second & 1)) plus1 += i.second;
            else ans1 = max(ans1, i.second);
        }
        int q;
        cin >> q;
        while (q--)
        {
            ll tmp;
            cin >> tmp;
            if (!tmp) cout << ans0 << "\n";
            else cout << max(ans1, plus1) << "\n";
        }
    }
    return 0;
}