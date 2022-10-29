#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define Maxn 500000
using namespace std;
vector<int>v[200005];
int i,j,m,n,p,k,a[Maxn];
int mu[Maxn+5],vis[Maxn+5],prime[Maxn+5],Q,F[Maxn+5];
int sum[Maxn+5];
long long ans;
void ins(int x)
{
      for (i=0;i<v[x].size();++i)
      {
           p=v[x][i];
           ans+=mu[p]*sum[p];
           sum[p]++;
      }
}
void del(int x)
{
       for (i=0;i<v[x].size();++i)
      {
           p=v[x][i];
           sum[p]--;
           ans-=mu[p]*sum[p];
      }
}
void pre()  
{  
    memset(vis,0,sizeof(vis));  
    mu[1] = 1;    
    for(i=2;i<=Maxn;i++)  
    {  
        if(!vis[i])  
        {  
            prime[++prime[0]] = i;  
            mu[i] = -1;  
        }  
        for(j=1;j<=prime[0]&&i*prime[j]<=Maxn;j++)  
        {  
            vis[i*prime[j]]=1;  
            if(i%prime[j]) mu[i*prime[j]]=-mu[i];  
            else  
            {  
                mu[i*prime[j]] = 0;  
                break;  
            }  
        }  
    }  
}  
int main()
{ 
    scanf("%d%d",&n,&Q);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    pre();
    for (i=1;i<=n;++i)
      for (j=1;j*j<=a[i];++j)
        if (a[i]%j==0)
        {
                       if (j*j!=a[i]&&mu[j]!=0) v[i].push_back(j);
                       if (mu[a[i]/j]!=0) v[i].push_back(a[i]/j);
        }
    for (;Q--;)
 { 
        scanf("%d",&k);
        if (F[k]) del(k),F[k]=0;
        else ins(k),F[k]=1;
        printf("%I64d\n",ans);
 }
}