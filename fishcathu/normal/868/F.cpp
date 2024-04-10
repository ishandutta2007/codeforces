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
const ll inf=1LL<<60;
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
int a[N],s[N];
ll f[N],g[N];
ll calc(int u,int v)
{
    static int l=1,r=0;
    static ll res=0;
    while(l<u)res-=--s[a[l++]];
    while(l>u)res+=s[a[--l]]++;
    while(r<v)res+=s[a[++r]]++;
    while(r>v)res-=--s[a[r--]];
    return res;
}
void cdq(int l,int r,int x,int y)
{
    if(l>r)return;
    int m=l+r>>1,w;
    f[m]=inf;
    for(int i=min(y,m);i>=x;--i)
    {
        ll t=g[i-1]+calc(i,m);
        if(t<f[m])
        {
            f[m]=t;
            w=i;
        }
    }
    cdq(l,m-1,x,w);
    cdq(m+1,r,w,y);
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        f[i]=inf;
    }
    while(m--)
    {
        memcpy(g+1,f+1,n<<3);
        cdq(1,n,1,n);
    }
    write(f[n],'\n');
}