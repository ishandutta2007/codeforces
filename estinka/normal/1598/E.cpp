#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

const int maxn = 1005;
bool lock[maxn][maxn];
pair<int, int> v[maxn][maxn][2];
ll c2(ll x)
{
    return (x * (x - 1)) / 2ll;
}
int cnt = 0;
set<int> s[maxn * 2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    ll ans = 0, fr = n*m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (i)
        {
            v[i][j][0] = v[i-1][j][1];
            v[i][j][0].second++;
            s[v[i][j][0].first].erase(v[i][j][0].second);
            s[v[i][j][0].first].insert(v[i][j][0].second+1);
        }
        else
        {
            v[i][j][0] = { cnt, 0 };
            s[cnt] = { -1, 1 };
            cnt++;
        }
        if (j)
        {
            v[i][j][1] = v[i][j-1][0];
            v[i][j][1].second++;
            s[v[i][j][1].first].erase(v[i][j][1].second);
            s[v[i][j][1].first].insert(v[i][j][1].second+1);
        }
        else
        {
            v[i][j][1] = { cnt, 0 };
            s[cnt] = { -1, 1 };
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) ans += c2(*prev(s[i].end()) - *s[i].begin());
    while (q--)
    {
        int x, y; 
        cin >> x >> y;
        x--, y--;
        if (lock[x][y])
        {
            for (int i = 0; i < 2; i++)
            {
                auto it = s[v[x][y][i].first].lower_bound(v[x][y][i].second);
                ans += c2(*next(it) - *prev(it)) - c2(*it - *prev(it)) - c2(*next(it) - *it);
                s[v[x][y][i].first].erase(it);
            }
            fr++;
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                s[v[x][y][i].first].insert(v[x][y][i].second);
                auto it = s[v[x][y][i].first].lower_bound(v[x][y][i].second);
                ans += -c2(*next(it) - *prev(it)) + c2(*it - *prev(it)) + c2(*next(it) - *it);
            }
            fr--;
        }
        lock[x][y] = !lock[x][y];
        cout << ans - fr << "\n";
    }
    return 0;
}