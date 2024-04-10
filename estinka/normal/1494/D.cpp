#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <list>
typedef long long ll;
using namespace std;

const int maxn = 512;
vector<vector<int> > a(maxn, vector<int>(maxn));
vector<pair<int, pair<int, int> > > v;
vector<int> p(maxn* maxn, -1), c(maxn * maxn, -1);
int boss(int vr)
{
    while (p[vr] != -1) vr = p[vr];
    return vr;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (i == j) c[i] = a[i][j];
            else v.push_back({ a[i][j], {i,j} });
        }
    }
    sort(v.begin(), v.end());
    int k = n;
    for (int i = 0; i < v.size(); i++)
    {
        int a = boss(v[i].second.first), b = boss(v[i].second.second), s = v[i].first;
        if (a == b) continue;
        if (c[a] < c[b]) swap(a, b);
        if (s == c[a])
        {
            p[b] = a;
            continue;
        }
        c[k] = s;
        p[a] = p[b] = k++;
    }
    cout << k << "\n";
    for (int i = 0; i < k; i++) cout << c[i] << " ";
    cout << "\n";
    cout << min_element(p.begin(), p.begin() + k) - p.begin() + 1 << "\n";
    for (int i = 0; i < k; i++)
    {
        if (p[i] != -1) cout << i + 1 << " " << p[i] + 1 << "\n";
    }
    return 0;
}