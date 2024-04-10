#include<bits/stdc++.h>
#define maxn 230402

using namespace std;
typedef long long ll;

struct number{
    int a[20];
};

ll n,t,k,r,ans,d,s,len;
number s1,s2;

ll pow_(ll x,ll y)
{
    number tmp=s1;
    number tt=s2;
    number ttt;
    ll p=1;
    while (x){
        if (x&p){
            x-=p;
            for (int i=0;i<y;i++) ttt.a[i]=0;
            for (int i=0;i<y;i++)
                for (int j=0;j<y;j++)
                    if (i+j<y) ttt.a[i+j]+=tmp.a[i]*tt.a[j];
            for (int i=0;i<y;i++) ttt.a[i+1]+=ttt.a[i]/10,ttt.a[i]%=10;
            ttt.a[y]=0;
            tmp=ttt;
        }
        for (int i=0;i<y;i++) ttt.a[i]=0;
        for (int i=0;i<y;i++)
            for (int j=0;j<y;j++)
                if (i+j<y) ttt.a[i+j]+=tt.a[i]*tt.a[j];
        for (int i=0;i<y;i++) ttt.a[i+1]+=ttt.a[i]/10,ttt.a[i]%=10;
        ttt.a[y]=0;
        tt=ttt;
        p<<=1;
    }
    ll cnt=0; p=1;
    for (int i=0;i<y;i++)
    {
        cnt=cnt+p*tmp.a[i];
        p=p*10;
    }
    return cnt;
}

int main()
{
    scanf("%d",&n);
    s1.a[0]=1;
    s2.a[0]=2;
    k=r+1;
    while (n--)
    {
        scanf("%I64d",&t);
        t=t*1000000ll;
        k=t%131072;
        t=t-k+131072;
        if (t%5==0) t=t+131072;
        r=t; len=0;
        while (r) len++,r/=10;
        r=1;d=1;s=2;ans=0;k=1;
        for (int i=1;i<=len;i++)
        {
            d=d*10;
            while (t%d!=pow_(ans,i))
            {
                ans+=k;
            }
            if (k==1) k=4; else k=k*5;
            //printf("%lld\n",k);printf("%lld\n",d);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}