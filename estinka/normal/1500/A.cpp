#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

void end(bool how, int i1, int i2, int i3, int i4)
{
    cout << (how ? "YES\n" : "NO\n");
    if (how) cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << " " << i4 + 1 << "\n";
    exit(0);
}
const int maxa = 5e6 + 128;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int> > f(maxa);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]].push_back(i);
    }
    vector<int> two;
    vector<int> v;
    for (int i = 0; i < maxa; i++)
    {
        if (f[i].size() >= 4)
        {
            end(true, f[i][0], f[i][1], f[i][2], f[i][3]);
        }
        if (f[i].size() >= 2) two.push_back(i);
        if (f[i].size()) v.push_back(f[i][0]);
    }
    vector<pair<int, int> > seen(maxa, { -1, -1 });
    if (two.size() > 1)
    {
        end(true, f[two[0]][0], f[two[1]][0], f[two[0]][1], f[two[1]][1]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            int sum = a[v[i]] + a[v[j]];
            if (seen[sum].first != -1) end(true, v[i], v[j], seen[sum].first, seen[sum].second);
            seen[sum] = { v[i], v[j] };
        }
    }
    for (int i = 0; i < maxa; i++)
    {
        if (f[i].size() >= 2 && seen[i+i].first != -1)
        {
            end(true, f[i][0], f[i][1], seen[i + i].first, seen[i + i].second);
        }
    }
    end(false, -1, -1, -1, -1);
    return 0;
}