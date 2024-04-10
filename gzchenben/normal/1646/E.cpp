#include<cstdio>
#include<cstring>
using namespace std;
int n,m,F[21];
bool vis[1000005];
long long ans;

bool tmp[20000005];
void Init(int x,int y)
{
    memset(tmp,0,sizeof(tmp));
    for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) tmp[i*j]=true;
    int cnt=0;
    for(int i=1;i<=x*y;i++) if(tmp[i]) cnt++;
    F[x]=cnt;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=20;i++)
    {
        Init(i,m);
    }
    ans=1;
    for(int i=2;i<=n;i++)
    {
        if(vis[i]) continue;
        int cnt=0;
        for(long long j=i;j<=n;j*=i)
        {
            vis[j]=true;
            cnt++;
        }
        ans+=F[cnt];
    }
    printf("%lld\n",ans);
}