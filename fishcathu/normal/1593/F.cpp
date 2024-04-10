#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=41;
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
char a[N];
struct node{bool b;node *pre;char val;}f[N][N][N][N];
void dfs(node *x){if(x!=&f[0][0][0][0])dfs(x->pre),putchar(x->val);}
void solve()
{
    memset(f,0,sizeof f);
    f[0][0][0][0].b=1;
    int n=read(),u=read(),v=read();
    scanf("%s",a);
    node *res;
    int mn=n;
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n-i;++j)
        {
            for(int l=0;l<u;++l)
            {
                for(int r=0;r<v;++r)
                {
                    node *x=&f[i][j][l][r];
                    if(!x->b)continue;
                    if(i+j^n)
                    {
                        f[i+1][j][(l*10+a[i+j]-48)%u][r]={1,x,'R'};
                        f[i][j+1][l][(r*10+a[i+j]-48)%v]={1,x,'B'};
                    }
                    else if(!l&&!r)
                    {
                        int t=abs(i-j);
                        if(t<mn)res=x,mn=t;
                    }
                }
            }
        }
    }
    if(mn^n)dfs(res),putchar('\n');
    else puts("-1");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}