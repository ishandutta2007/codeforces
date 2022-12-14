#include <algorithm>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <random>
typedef long long ll;
using namespace std;

const int maxn = 1 << 18, inf = 1e9;
vector<int> st(maxn * 2, -1);
void update(int i, int x)
{
    for (i += maxn; i > 0; i >>= 1) st[i] = max(st[i], x);
}
int query(int l, int r)
{
    int ans = -1;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1) ans = max(ans, st[l++]);
        if (r & 1) ans = max(ans, st[--r]);
    }
    return ans;
}
struct question
{
    int t, l, r, x, j;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<question> v(q);
    vector<vector<int> > h(n + 1);
    for (int i = 0; i < q; i++)
    {
        cin >> v[i].t;
        if (v[i].t == 0)
        {
            cin >> v[i].l >> v[i].r >> v[i].x;
            v[i].l--, v[i].r--;
            if (v[i].x == 0)
            {
                h[v[i].l].push_back(i);
                h[v[i].r + 1].push_back(i);
            }
        }
        else
        {
            cin >> v[i].j;
            v[i].j--;
        }
    }
    set<int> hq;
    vector<int> when(n, inf);
    vector<int> state(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j : h[i])
        {
            if (hq.count(j)) hq.erase(j);
            else hq.insert(j);
        }
        if (hq.size())
        {
            when[i] = *hq.begin();
            update(i, when[i]);
            state[i] = 0; // this person is healthy
        }
    }
    vector<int> pf(n + 1, 0);
    vector<int> idk;
    for (int i = 0; i < n; i++)
    {
        pf[i + 1] = pf[i];
        if (state[i] != 0)
        {
            pf[i + 1]++;
            idk.push_back(i);
        }
    }
    for (int i = 0; i < q; i++) if (v[i].t == 0 && v[i].x == 1 && pf[v[i].r + 1] - pf[v[i].l] == 1)
    {
        int sick = *lower_bound(idk.begin(), idk.end(), v[i].l);
        state[sick] = 1;
        int tim = max(i, query(v[i].l, v[i].r));
        when[sick] = min(when[sick], tim);
    }
    for (int i = 0; i < q; i++) if (v[i].t == 1)
    {
        if (when[v[i].j] < i) cout << (state[v[i].j] ? "YES\n" : "NO\n");
        else cout << "N/A\n";
    }
    return 0;
}