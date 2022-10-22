#include <algorithm>
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

vector<int> pf;
int sum(int l, int r)
{
    return pf[r + 1] - pf[l];
}
vector<pair<int, int> > solve()
{
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;
    pf.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x = (s[i] == '(' ? 1 : -1);
        pf[i + 1] = pf[i] + x;
    }
    int l = n, r = -1;
    for (int i = 1; i <= n; i++)
    {
        if (pf[i] < 0)
        {
            l = min(l, i - 1);
            r = max(r, i - 1);
        }
    }
    if (r == -1) return {};
    vector<pair<int, int> > ans;
    for (int i = l; i >= 0; i--) if (pf[i] > pf[l]) l = i;
    for (int i = r + 1; i <= n; i++) if (pf[i] > pf[r + 1]) r = i - 1;
    bool ok = true;
    for (int i = l; i <= r; i++)
    {
        if (pf[l] + pf[r + 1] - pf[i + 1] < 0) ok = false;
    }
    if (ok) return { { l, r } };
    int m = max_element(pf.begin(), pf.end()) - pf.begin();
    return { { 0, m - 1 }, { m, n - 1 } };
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int> > ans = solve();
        cout << ans.size() << "\n";
        for (pair<int, int> i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
    return 0;
}