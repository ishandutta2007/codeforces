#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <array>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin >> k;
    vector<int> p;
    for (ll i = k + 2; i >= 2; i--)
    {
        while ((i * (i - 1)) / 2 <= k)
        {
            p.push_back(i);
            k -= (i * (i - 1)) / 2;
        }
    }
    if (p.empty()) p.push_back(1);
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p[i]; j++) cout << (char)('a' + i);
    }
    cout << "\n";
    return 0;
}