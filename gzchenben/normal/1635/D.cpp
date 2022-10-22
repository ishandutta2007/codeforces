#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int Mod=1000000007;

int n,p,a[200005],F[200005],sum[200005];
map<int,bool> mp;
int main()
{
    scanf("%d%d",&n,&p);
    F[1]=1;
    F[2]=1;
    sum[1]=1;
    sum[2]=2;
    for(int i=3;i<=p+1;i++)
    {
        F[i]=(F[i-1]+F[i-2])%Mod;
        sum[i]=(sum[i-1]+F[i])%Mod;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=a[i];
        bool flag=false;
        while(tmp)
        {
            if(tmp%2==1) tmp>>=1;
            else if(tmp%4==0) tmp>>=2;
            else break;
            if(mp[tmp]) 
            {
                flag=true;
                break;
            }
        }
        if(flag) continue;
        int len=0;
        while(a[i])
        {
            len++;
            a[i]>>=1;
        }
        if(p-len+1>=0) ans=(ans+sum[p-len+1])%Mod;
    }
    printf("%d\n",ans);
}