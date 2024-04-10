#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],l[N],r[N];
bitset<N>b;
int mn[2],s[2],c[2];
void exi()
{
    puts("-1");
    exit(0);
}
void push(bool k,int w)
{
    mn[k]=a[w];
    ++s[k];
    c[k]+=b[w];
}
int main()
{
    int n=read();
    for(int i=n;i--;)
    {
        int u=read(),v=read();
        bool k=0;
        if(u>v)
        {
            swap(u,v);
            k=1;
        }
        if(u>n)exi();
        a[u]=v;
        b[u]=k;
    }
    l[0]=inf;
    for(int i=1;i<=n;++i)
    {
        l[i]=min(l[i-1],a[i]);
    }
    for(int i=n;i>=1;--i)
    {
        r[i]=max(r[i+1],a[i]);
    }
    mn[0]=mn[1]=inf;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]<mn[0])push(0,i);
        else if(a[i]<mn[1])push(1,i);
        else exi();
        if(l[i]>r[i+1])
        {
            ans+=min(c[0]+s[1]-c[1],c[1]+s[0]-c[0]);
            mn[0]=mn[1]=inf;
            s[0]=s[1]=0;
            c[0]=c[1]=0;
        }
    }
    write(ans,'\n');
}