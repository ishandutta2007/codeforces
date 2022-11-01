#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1E5+10;
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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int q[N],f[N],n;
pii a[N];
void add(int x,int val)
{
    while(x<=n)
    {
        q[x]+=val;
        x+=x&-x;
    }
}
int ask(int x)
{
    int res=0;
    while(x)
    {
        res+=q[x];
        x-=x&-x;
    }
    return res;
}
int kth(int x)
{
    if(!x)return 0;
    int res=0;
    for(int i=1<<17;i>>=1;)
    {
        int t=res+i;
        if(t<=n&&q[t]<x)
        {
            x-=q[res=t];
        }
    }
    return res+1;
}
void push(int x)
{
    add(x,-1);
    int k=ask(x);
    int l=kth(k)+1;
    f[l]=max(f[l],kth(k+1)-l);
}
int main()
{
    n=read();
    int m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=mp(read(),i);
        add(i,1);
    }
    sort(a+1,a+1+n);
    for(int l=1,r=1;r<=n;)
    {
        if(a[r].fi-a[l].fi<=m)push(a[r++].se);
        else add(a[l++].se,1);
    }
    int mx=0,sum;
    for(int i=1;i<=n;++i)
    {
        if(f[i]>mx)
        {
            mx=f[i];
            sum=0;
        }
        if(f[i]==mx)++sum;
    }
    printf("%d %d\n",mx,sum);
    for(int i=1;i<=n;++i)
    {
        if(f[i]==mx)
        {
            printf("%d %d\n",i,i+mx-1);
        }
    }
}