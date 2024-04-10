#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vint;

const long long inf = 123456789012345678;

vector < pair <int, int> > v;
vector <long long> ans;
vint D1[1000000], D2[1000000];
vint *d1 = D1 + 500000, *d2 = D2 + 500000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    ans.assign(k, inf);
    for (int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
        d1[x - y].push_back(i);
        d2[x + y].push_back(i);
    }

    int x = 0, y = 0;
    int dk = 0, dn = 0;
    long long time = 0;

    do
    {
        int nx, ny;

        if (dk == 0)
        {
            if (x == 0 || y == 0)
            {
                int iter = min(n - x, m - y);
                nx = x + iter, ny = y + iter;
            }
            else
            {
                int iter = min(x, y);
                nx = x - iter, ny = y - iter;
            }
        }
        else
        {
            if (x == 0 || y == m)
            {
                int iter = min(n - x, y);
                nx = x + iter, ny = y - iter;
            }
            else
            {
                int iter = min(x, m - y);
                nx = x - iter, ny = y + iter;
            }
        }

        vint &d = (dk == 0) ? d1[dn] : d2[dn];
        for (int i = 0; i < d.size(); i++)
            ans[d[i]] = min(ans[d[i]], time + abs(x - v[d[i]].first));

        time += abs(nx - x);
        x = nx; y = ny;
        dk = !dk;
        dn = (dk == 0) ? (x - y) : (x + y);
    }
    while ((x != 0 || y != 0) &&
           (x != 0 || y != m) &&
           (x != n || y != 0) &&
           (x != n || y != m));

    for (int i = 0; i < k; i++)
        if (ans[i] == inf)
            ans[i] = -1;
    for (int i = 0; i < k; i++)
        cout << ans[i] << endl;

    return 0;
}