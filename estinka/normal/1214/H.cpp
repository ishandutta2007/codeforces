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

const int maxn = 2e5 + 79;
vector<vector<int> > g(maxn);
vector<int> mycol(maxn, -1), d0(maxn, -1), d1(maxn, -1), d2(maxn, -1);
int n, k, r1, r2;
void end(bool happy = false)
{
    cout << (happy ? "Yes\n" : "No\n");
    if (happy) for (int i = 0; i < n; i++) cout << mycol[i] + 1 << (i == n - 1 ? "\n" : " ");
    exit(0);
}
void dfsd1(vector<int> &d, int v)
{
    for (int i : g[v])
    {
        if (d[i] != -1) continue;
        d[i] = d[v] + 1;
        dfsd1(d, i);
    }
}
void dfsd2(int v)
{
    for (int i : g[v])
    {
        if (d2[i] != -1) continue;
        d2[i] = d2[v] - 1;
        dfsd2(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    d0[0] = 0;
    dfsd1(d0, 0);
    r1 = max_element(d0.begin(), d0.begin() + n) - d0.begin();
    d1[r1] = 0;
    dfsd1(d1, r1);
    r2 = max_element(d1.begin(), d1.begin() + n) - d1.begin();
    d2[r2] = d1[r2];
    dfsd2(r2);
    for (int i = 0; i < n; i++)
    {
        if (d1[i] >= k - 1 && d2[r2] - d2[i] + 1 >= k && d1[i] % k != d2[i] % k)
            end();
    }
    for (int i = 0; i < n; i++)
    {
        if (d1[i] >= d2[r2] - d2[i]) mycol[i] = d1[i] % k;
        else mycol[i] = d2[i] % k;
    }
    end(true);
    return 0;
}