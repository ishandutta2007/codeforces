#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
inline ll read()
{
   ll x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}

ll s[100005];
int n;
ll tf,tt,t;
ll beg,tot;
ll ans=200000000000000LL,times=0;

int main()
{
    tf=read();tt=read();t=read();n=(int)read();tt-=t;
    for(int i=1;i<=n;i++) s[i]=read();
    int i=1;
    s[0]=-1;
    for(;s[i]<tf&&i<=n;i++)
    {
        if(s[i]==s[i-1]) continue;
        if(ans>tf-(s[i]-1)+t*(i-1))
        {
            ans=tf-(s[i]-1)+t*(i-1);times=s[i]-1;
        }
    }
    beg=tf;tot=i-1;
    for(;i<=n&&s[i]<=tt;i++)
    {
        if(s[i]!=s[i-1])
        {
            if(beg+tot*t<=s[i]-1)
            {
                printf("%I64d\n",s[i]-1);
                return 0;
            }
            else
            {
                if(beg+tot*t-(s[i]-1)<ans)
                {
                    ans=beg+tot*t-(s[i]-1);
                    times=s[i]-1;
                }
            }
        }
        if(beg+tot*t<=s[i])
        {
            beg=s[i];tot=1;
        }
        else
            tot++;
    }
    if(beg+tot*t<=tt)
    {
        printf("%I64d\n",beg+tot*t);
    }
    else
        printf("%I64d\n",times);
    return 0;
}