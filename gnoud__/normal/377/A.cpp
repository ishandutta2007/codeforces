#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=510;
int m,n,k,res,dd[N][N];
char a[N][N];
pii r;
vector<pii> ke[N][N];
void add(int x,int y,int u,int v)
{
    ke[x][y].pb({u,v});
    ke[u][v].pb({x,y});
}
void DFS(int u,int v)
{
    if(res) {res--;a[u][v]='X';}
    dd[u][v]=1;
    forv(x,ke[u][v]) if(!dd[x.fi][x.se]) DFS(x.fi,x.se);
}
int main()
{
    //freopen("377A.inp","r",stdin);
    m=in,n=in,k=in;
    forinc(i,1,m) forinc(j,1,n)
    {
        a[i][j]=getchar();
        while(a[i][j]!='.'&&a[i][j]!='#') a[i][j]=getchar();
        if(a[i][j]=='.')
        {
            res++;
            r={i,j};
            if(i>1&&a[i-1][j]=='.') add(i,j,i-1,j);
            if(j>1&&a[i][j-1]=='.') add(i,j,i,j-1);
        }
    }
    res-=k;
    DFS(r.fi,r.se);
    forinc(i,1,m)
    {
        forinc(j,1,n)
        {
            if(a[i][j]=='X') cout<<'.';
            else if(a[i][j]=='.') cout<<'X';
            else cout<<'#';
        }
        cout<<"\n";
    }
}