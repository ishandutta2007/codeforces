#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}

int n,m;
int s[100005];
bool flag[100005];
int w[100005];
ll ans=0;

struct node{
    ll f,num;
    friend bool operator < (node x,node y)
    {
        return x.f>y.f;
    }
}newx;
priority_queue<node> q;


int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
        s[i]=read();
    for(int i=1;i<=n;i++) w[i]=read();
    for(int i=1;i<=n;i++)
    {
        if(s[i]%100==0) continue;
        m-=s[i]%100;
        ll x=(ll)(100-(s[i]%100))*w[i];
        q.push((node){x,i});
        while(m<0)
        {
            newx=q.top();q.pop();
            flag[newx.num]=1;
            m+=100;
            ans+=newx.f;
        }
    }
    printf("%I64d\n",ans);
    for(int i=1;i<=n;i++)
    {
        if(s[i]%100==0) printf("%d 0\n",s[i]/100);
        else if(flag[i]) printf("%d 0\n",s[i]/100+1);
        else        printf("%d %d\n",s[i]/100,s[i]%100);
    }
    return 0;
}