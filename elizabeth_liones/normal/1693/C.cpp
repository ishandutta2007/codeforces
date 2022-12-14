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

const int inf = 1e9 + 5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > gi(n);
    vector<vector<int> > go(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        go[--a].push_back(--b);
        gi[b].push_back(a);
    }
    vector<int> t(n, inf);
    vector<int> cnt(n, 0);
    set<pair<int, int> > q;
    q.insert({ 0, n - 1 });
    while (!q.empty())
    {
        int v, d;
        tie(d, v) = *q.begin();
        q.erase(q.begin());
        if (t[v] != inf)
        {
            continue;
        }
        t[v] = d;
        for (int u : gi[v]) if (t[u] == inf)
        {
            cnt[u]++;
            q.insert({ t[v] + go[u].size() - cnt[u] + 1, u });
        }
    }
    cout << t[0] << "\n";
    return 0;
}