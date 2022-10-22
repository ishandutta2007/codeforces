#include<cstdio>
using namespace std;
int n,cnt[105][105];

int tot,ans[10005][105];

void Make_Dif()
{
    while(1)
    {
        int pos=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cnt[i][j] > 1)
                {
                    pos=i;
                    break;
                }
            }
        }
        if(!pos) return;
        int Now=0;
        tot++;
        for(int i=pos;;)
        {
            cnt[i][Now]++; 
            for(int j=1;j<=n;j++) if(cnt[i][j] > 1) Now=j;
            ans[tot][i]=Now;
            cnt[i][Now]--;
            i=(i%n)+1;
            if(i == pos) break;
        }
        cnt[pos][0]--;
        cnt[pos][Now]++;
    }
}

void Make_Same()
{
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            tot++;
            for(int k=1;k<=n;k++)
            {
                ans[tot][k]=((i-j+k-1+n)%n)+1;
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            cnt[i][x]++;
        }
    }
    Make_Dif();
    Make_Same();
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}