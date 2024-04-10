#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,t,k[300005],c[300005];
priority_queue<int,vector<int>,greater<int> > Q;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&k[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&c[i]);
        }
        while(!Q.empty()) Q.pop();
        sort(k+1,k+n+1);
        int now=1;
        long long ans=0,sum=0;
        for(int i=1;i<=m;i++)
        {
            while(k[now]==i && now<=n)
            {
                if(!Q.empty())
                {
                    if(Q.top()<c[i]) 
                    {
                        ans+=c[i]-Q.top();
                        Q.pop();
                        Q.push(c[i]);
                    }
                }
                now++;
            }
            Q.push(c[i]);
        }
        for(int i=1;i<=n;i++) sum+=c[k[i]];
        printf("%lld\n",sum-ans);
    }
}