#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
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

const int N=200010;

int n,k,ret,dis[N],sz[N];
vector<int> ke[N];
priority_queue<int> q;

void dfs(int u,int p)
{
    int la=1;
    forv(v,ke[u]) if(v!=p){
        la=0;
        dis[v]=dis[u]+1;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    q.push(dis[u]-sz[u]); sz[u]++;
}

main(){
    //freopen("A.inp","r",stdin);
    //freopen("A.out","w",stdout);

    n=in,k=in;
    forinc(i,2,n)
    {
        int u=in,v=in;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    dfs(1,0);
    forinc(i,1,k)
    {
        ret+=q.top();
        q.pop();
    }
    cout<<ret;
}