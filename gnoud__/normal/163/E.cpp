#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned ull;
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
#define pl pair<ll,ll>
const int N=1e6+10;
int n,m,tin[N],tout[N],id=1,it,t[N],dd[N][26],sl[N],ed[N],nx[N];
char c[N];
string a;
vector<int> ad[N],ke[N];
void add(int s,int i,int o)
{
    if(i==a.size())
    {
        ed[o]=s;
        return;
    }
    if(!dd[s][a[i]-'a'])
    {
        dd[s][a[i]-'a']=++id;
        ad[s].pb(id);
        c[id]=a[i];
    }
    add(dd[s][a[i]-'a'],i+1,o);
}
void BFS(int s)
{
    queue<int> q;
    ke[1]=ad[1];
    forv(v,ad[s]) nx[v]=1,q.push(v);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        forv(v,ad[u])
        {
            int k=nx[u];
            while(k!=1&&!dd[k][c[v]-'a']) k=nx[k];
            if(dd[k][c[v]-'a']) k=dd[k][c[v]-'a'];
            nx[v]=k;
            ke[k].pb(v);
            q.push(v);
        }
    }
}
void DFS(int u)
{
    tin[u]=++it;
    forv(v,ke[u]) DFS(v);
    tout[u]=it;
}
void update(int i,int x)
{
    for(;i<=it;i+=i&-i) t[i]+=x;
}
int get(int i)
{
    int g=0;
    for(;i;i-=i&-i) g+=t[i];
    return g;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("163E.inp","r",stdin);
    //freopen("163E.out","w",stdout);
    cin>>m>>n;
    forinc(i,1,n)
    {
        cin>>a;
        add(1,0,i);
    }
    BFS(1);
    DFS(1);
    forinc(i,1,n)
    {
        sl[i]=1;
        update(tin[ed[i]],1);
        update(tout[ed[i]]+1,-1);
    }
    while(m--)
    {
        char c;cin>>c;
        if(c=='?')
        {
            cin>>a;
            int k=1;
            ll ans=0;
            forv(x,a)
            {
                while(k!=1&&!dd[k][x-'a']) k=nx[k];
                if(dd[k][x-'a']) k=dd[k][x-'a'];
                ans+=get(tin[k]);
            }
            cout<<ans<<"\n";
        }
        else
        {
            int i;cin>>i;
            if(c=='+')
            {
                if(sl[i]) continue;
                sl[i]=1;
                update(tin[ed[i]],1);
                update(tout[ed[i]]+1,-1);
            }
            else
            {
                if(!sl[i]) continue;
                sl[i]=0;
                update(tin[ed[i]],-1);
                update(tout[ed[i]]+1,1);
            }
        }
    }
}