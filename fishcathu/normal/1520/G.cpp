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
typedef pair<ll,ll> pll;
const int N=2010;
const ll inf=1LL<<61;
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
int a[N][N],c[N][N],k;
const int z[4][2]={0,1,0,-1,1,0,-1,0};
ll b[N][N];
ll m1=inf,m2=inf;
queue<pii>q;
void push(int x,int y,ll val,ll &m1)
{
    b[x][y]=val;
    q.push(mp(x,y));
    if(a[x][y])m1=min(m1,val+a[x][y]);
    a[x][y]=-1;
}
void bfs(int x,int y,ll &m1)
{
    push(x,y,0,m1);
    while(!q.empty())
    {
        x=q.front().fi,y=q.front().se;
        q.pop();
        for(int i=4;i--;)
        {
            int l=x+z[i][0],r=y+z[i][1];
            if(!~a[l][r])continue;
            push(l,r,b[x][y]+k,m1);
        }
    }
}
int main()
{
    memset(a,-1,sizeof a);
    int n=read(),m=read();
    k=read();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]=read();
        }
    }
    memcpy(c,a,sizeof c);
    bfs(1,1,m1);
    ll ans=inf;
    if(b[n][m])ans=b[n][m];
    memcpy(a,c,sizeof a);
    bfs(n,m,m2);
    ans=min(ans,m1+m2);
    write(ans==inf?-1:ans,'\n');
}