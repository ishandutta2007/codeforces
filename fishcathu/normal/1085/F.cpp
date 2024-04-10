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
const int N=2E5+10,M=3;
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
char c[N],a[N],val[N];
int n,m,pos[N],ans[N],q[M][N];
bool b;
void push(char op,int x,int val)
{
    if(!x)return;
    while(x<=n)
    {
        q[op][x]+=val;
        x+=x&-x;
    }
}
int ask(int op)
{
    int res=0;
    for(int i=1<<18;i>>=1;)
    {
        int t=res+i;
        if(t<=n&&!q[op][t])res=t;
    }
    return res+1;
}
int sum(char op,int l,int r)
{
    int res=0;
    while(l)
    {
        res-=q[op][l];
        l-=l&-l;
    }
    --r;
    while(r)
    {
        res+=q[op][r];
        r-=r&-r;
    }
    return res;
}
void solve()
{
    memcpy(a+1,c+1,n);
    for(int i=1;i<=n;++i)push(a[i],i,1);
    for(int i=0;i<=m;++i)
    {
        push(a[pos[i]],pos[i],-1);
        push(val[i],pos[i],1);
        a[pos[i]]=val[i];
        for(int j=0,k=2;j<M;++j,++k%=M)
        {
            int l=ask(j),r=ask(k);
            if(l>=r)continue;
            if(r<=n)ans[i]+=sum(j^k^M,l,r);
            else if(b)ans[i]+=sum(j^k^M,0,r);
        }
    }
}
int main()
{
    n=read(),m=read();
    scanf("%s",c+1);
    for(int i=1;i<=n;++i)c[i]=c[i]-79>>1;
    for(int i=1;i<=m;++i)
    {
        pos[i]=read();
        do val[i]=getchar();while(val[i]<80||val[i]>83);
        val[i]=val[i]-79>>1;
    }
    solve();
    reverse(c+1,c+1+n);
    for(int i=1;i<=m;++i)pos[i]=n+1-pos[i];
    for(int i=0;i<M;++i)memset(q[i]+1,0,n<<2);
    b=1;
    solve();
    for(int i=0;i<=m;++i)write(n-ans[i],'\n');
}