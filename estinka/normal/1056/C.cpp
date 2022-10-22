#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int maxn2 = 2128;
vector<int> p(maxn2), sp(maxn2, -1), taken(maxn2, 0);
void take(int i)
{
    taken[i] = true;
    cout << i + 1 << endl;
    cout.flush();
}
int get()
{
    int h; cin >> h;
    taken[--h] = true;
    return h;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 2 * n; i++) cin >> p[i];
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        sp[--a] = --b;
        sp[b] = a;
    }
    int t;
    cin >> t;
    if (t == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (m)
            {
                for (int j = 0; j < 2 * n; j++)
                {
                    if (!taken[j] && sp[j] != -1)
                    {
                        if (p[sp[j]] > p[j]) j = sp[j];
                        take(j); m--;
                        break;
                    }
                }
            }
            else
            {
                int best = -1;
                for (int j = 0; j < 2 * n; j++) if (!taken[j] && (best == -1 || p[j] > p[best])) best = j;
                take(best);
            }
            get();
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int h = get();
            if (sp[h] != -1 && !taken[sp[h]])
            {
                take(sp[h]); m--;
            }
            else if (m)
            {
                for (int j = 0; j < 2 * n; j++)
                {
                    if (!taken[j] && sp[j] != -1)
                    {
                        if (p[sp[j]] > p[j]) j = sp[j];
                        take(j); m--;
                        break;
                    }
                }
            }
            else
            {
                int best = -1;
                for (int j = 0; j < 2 * n; j++) if (!taken[j] && (best == -1 || p[j] > p[best])) best = j;
                take(best);
            }
        }
    }
    return 0;
}