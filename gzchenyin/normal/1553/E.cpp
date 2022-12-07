#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,T,a[300005],cnt[300005],b[300005],To[300005];
bool vis[300005];
bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        b[i]=(i-x+n-1)%n+1;
        To[b[i]]=a[i];
        vis[i]=false;
    }
    int Res=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        Res++;
        int Now=i;
        do
        {
            vis[Now]=true;
            Now=To[Now];
        }while(Now!=i);
    }
    return n-Res<=m;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n-1;i++) cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[(i-a[i]+n)%n]++;
        }
        vector<int> vec,ans;
        for(int i=0;i<=n-1;i++)
        {
            if(cnt[i]>=n-2*m) vec.push_back(i);
        }
        if(!vec.empty()) sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++)
        {
            if(check(vec[i])) ans.push_back(vec[i]);
        }
        printf("%d ",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}