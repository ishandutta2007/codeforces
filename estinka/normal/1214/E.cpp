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
    int n;
    cin >> n;
    vector<pair<int, int> > d(n), g;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i].first;
        d[i].second = 2 * i;
    }
    sort(d.begin(), d.end(), greater<pair<int, int> > ());
    for (int i = 0; i < n; i++)
    {
        if (i + d[i].first >= d.size())
        {
            d.push_back({ 0, d[i].second + 1 });
        }
        else
        {
            g.push_back({ d[i + d[i].first - 1].second, d[i].second + 1 });
        }
    }
    for (int i = 0; i < d.size() - 1; i++) g.push_back({ d[i].second, d[i + 1].second });
    for (int i = 0; i < g.size(); i++)
    {
        cout << g[i].first + 1 << " " << g[i].second + 1 << "\n";
    }
    return 0;
}