#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=4E5+10;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
int fa[N],a[N][2];
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
void solve()
{
    int n=read(),s=n<<1;
    for(int i=1;i<=s;++i)fa[i]=i,a[i][0]=a[i][1]=0;
    for(int m=read();m--;)
    {
        int u=read(),v=read();
        char c[10];
        scanf("%s",c);
        int t=c[0]^'i'?0:n;
        fa[find(v+t)]=find(u);
        fa[find(v+n-t)]=find(u+n);
    }
    for(int i=1;i<=n;++i)
    {
        if(find(i)==find(i+n))
        {
            puts("-1");
            return;
        }
    }
    for(int i=1;i<=s;++i)++a[find(i)][i>n];
    int res=0;
    for(int i=1;i<=n;++i)res+=max(a[i][0],a[i][1]);
    write(res,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}