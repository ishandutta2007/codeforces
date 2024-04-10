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

vector<vector<int> > s;
vector<ll> l, r;
int ans;
ll dfs(int u)
{
    ll sum = 0;
    for (int v : s[u])
    {
        sum += dfs(v);
    }
    if (sum < l[u])
    {
        ans++;
        return r[u];
    }
    return min(sum, r[u]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans = 0;
        s.assign(n, {});
        l.assign(n, 0);
        r.assign(n, 0);
        for (int i = 1; i < n; i++)
        {
            int p;
            cin >> p;
            s[--p].push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i];
        }
        dfs(0);
        //cout << "           ";
        cout << ans << "\n";
    }
    return 0;
}