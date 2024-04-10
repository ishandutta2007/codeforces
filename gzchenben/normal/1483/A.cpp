#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,t,k[100005],cnt[100005];
vector<int> vec[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=m;i++)
        {
            vec[i].clear();
            scanf("%d",&k[i]);
            for(int j=1;j<=k[i];j++)
            {
                int x;
                scanf("%d",&x);
                vec[i].push_back(x);
            }
            if(k[i]==1) cnt[vec[i][0]]++;
        }
        bool flag=false;
        for(int i=1;i<=n;i++) 
        {
            if(cnt[i]>(m+1)/2) 
            {
                printf("NO\n");
                flag=true;
                break;
            }
        }
        if(flag) continue;
        printf("YES\n");
        for(int i=1;i<=m;i++)
        {
            if(k[i]==1)
            {
                printf("%d ",vec[i][0]);
                continue;
            } 
            if(cnt[vec[i][0]]>=(m+1)/2) 
            {
                printf("%d ",vec[i][1]);
                cnt[vec[i][1]]++;
            }
            else
            {
                printf("%d ",vec[i][0]);
                cnt[vec[i][0]]++;
            }
        }
        printf("\n");
    }   
}