#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, t, ord[200005], a[200005];
vector<int> vec[200005];
bool cmp(int x, int y)
{
    return vec[x].size() > vec[y].size();
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            vec[i].clear();
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
        vector<int> ans;
        while (vec[ord[1]].size())
        {
            vector<int> tmp;
            for (int i = 1; i <= n; i++)
            {
                if (vec[ord[i]].size())
                {
                    tmp.push_back(vec[ord[i]].back());
                    vec[ord[i]].pop_back();
                }
                else
                    break;
            }
            reverse(tmp.begin(), tmp.end());
            for (auto &p : tmp)
                ans.push_back(p);
        }
        int x = a[ans[0]];
        for (int i = 0; i < n - 1; i++)
        {
            a[ans[i]] = a[ans[i + 1]];
        }
        a[ans[n - 1]] = x;
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}