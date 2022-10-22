#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> d;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if (i == 0)
        {
            for (ll j = 2; j * j <= a[i]; j++)
            {
                if (a[i] % j == 0)
                {
                    d.push_back(j);
                    while (a[i] % j == 0) a[i] /= j;
                }
            }
            if (a[i] > 1) d.push_back(a[i]);
            for (ll j = 2; j * j <= b[i]; j++)
            {
                if (b[i] % j == 0)
                {
                    d.push_back(j);
                    while (b[i] % j == 0) b[i] /= j;
                }
            }
            if (b[i] > 1) d.push_back(b[i]);
            sort(d.begin(), d.end());
            d.erase(unique(d.begin(), d.end()), d.end());
        }
    }
    for (int i = 0; i < d.size(); i++)
    {
        bool good = true;
        for (int j = 1; j < n; j++)
        {
            if (a[j] % d[i] > 0 && b[j] % d[i] > 0)
            {
                good = false;
                break;
            }
        }
        if (good)
        {
            cout << d[i] << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}