#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,k;
vector<int> vec[100005];
void dfs(int x)
{
    for(auto &p : vec[x])
        if(vec[p].size() == 0) printf("%d ",p);
    for(auto &p : vec[x])
        if(vec[p].size()) 
        {
            printf("%d ",p);
            dfs(p);
        }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        vector<int> a(n+1),b(n+1),c(n+1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            c[i] = b[i];
        }
        sort(c.begin(),c.end());
        int cur = 1;
        for(int i=0;i<=n;i++)
        {
            while(c[cur] <= i && cur <= n) cur++;
            if(cur-1 == n-i) k = i;
        }
        printf("%d\n",k);
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i] == n+1) b[i] = 0;
            vec[b[i]].push_back(i);
        }
        dfs(0);
        printf("\n");
    }  
}