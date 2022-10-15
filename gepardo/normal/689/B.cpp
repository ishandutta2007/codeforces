#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int inf = 123456789;

int main()
{
    int n; scanf("%d", &n);
    vector < vector <int> > g(n);
    for (int i = 1; i < n; i++)
        g[i-1].push_back(i),
        g[i].push_back(i-1);
    for (int i = 0; i < n; i++)
    {
        int a; scanf("%d", &a); a--;
        g[i].push_back(a);
    }
    vector <int> d(n, inf);
    d[0] = 0;
    queue <int> q;
    q.push(0);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if (d[v] + 1 < d[to])
            {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 0; i < n; i++) printf("%s%d", i ? " " : "", d[i]);
    puts("\n");
}