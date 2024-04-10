#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, t, ord[200005], a[200005], b[200005];
vector<int> vec[200005];
bool cmp(int x, int y)
{
    return vec[x].size() > vec[y].size();
}
int In[200005];
vector<int> Edge[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            vec[i].clear();
        for (int i = 1; i <= n; i++)
            Edge[i].clear();
        for (int i = 1; i <= n; i++)
            In[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            vec[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            ord[i] = i;
        }
        sort(ord + 1, ord + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
            if (b[i] != ord[1])
            {
                Edge[a[i]].push_back(b[i]);
                In[b[i]]++;
            }
        }
        queue<int> Q;
        for (int i = 1; i <= n; i++)
        {
            if (In[i] == 0)
                Q.push(i);
        }
        int cnt = 0;
        while (!Q.empty())
        {
            cnt++;
            int Now = Q.front();
            Q.pop();
            for (auto &p : Edge[Now])
            {
                In[p]--;
                if (In[p] == 0)
                    Q.push(p);
            }
        }
        printf(cnt == n ? "AC\n" : "WA\n");
    }
}