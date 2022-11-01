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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],q[N],n;
int u[N],v[N];
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
void modify()
{
   int res=0;
   for(int i=1<<18;i>>=1;)
   {
       int t=res+i;
       if(t<=n&&!q[t])res=t;
   }
   add(res+1,-1);
}
void solve(int *u)
{
    for(int i=1;i<=n;++i)
    {
        u[i]+=ask(a[i]);
        add(a[i],2);
        modify();
    }
    memset(q+1,0,n<<2);
    for(int i=n;i>=1;--i)
    {
        u[i]+=ask(a[i]);
        add(a[i],2);
        modify();
    }
    memset(q+1,0,n<<2);
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    solve(u);
    for(int i=1;i<=n;++i)a[i]=n+1-a[i];
    solve(v);
    for(int i=1;i<=n;++i)write(max(u[i],v[i]+1)>>1,' ');

}