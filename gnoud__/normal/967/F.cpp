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
const int N=300010;
int n,m,dd[N],pre[N];
set<int> ke[N];
ull a[N],pw[N];
void BFS(int u)
{
    dd[u]=1;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        forv(v,ke[u]) if(!dd[v])
        {
            pre[v]=u;
            dd[v]=dd[u]+1;
            q.push(v);
        }
    }
}
int main()
{
    //freopen("967F.inp","r",stdin);
    n=in,m=in;
    forinc(i,1,m)
    {
        int u=in,v=in;
        ke[u].insert(v);
        ke[v].insert(u);
    }
    pw[0]=1;
    forinc(i,1,n)
    {
        pw[i]=pw[i-1]*1000000007;
        ke[i].insert(i);
    }
    forinc(u,1,n) forv(v,ke[u]) a[u]+=pw[v];
    BFS(1);
    if(dd[n]&&dd[n]<=5)
    {
        cout<<dd[n]-1<<"\n";
        vector<int> ans;
        while(n!=1) ans.pb(n),n=pre[n];
        ans.pb(1);
        reverse(all(ans));
        forv(x,ans) cout<<x<<" ";
        return 0;
    }
    forinc(i,1,n) if(dd[i]==3)
    {
        cout<<4<<"\n";
        return cout<<1<<" "<<pre[i]<<" "<<i<<" "<<1<<" "<<n,0;
    }
    forv(u,ke[1]) forv(v,ke[u]) if(u!=1&&v!=1&&a[u]!=a[v])
    {
        cout<<5<<"\n";
        forv(x,ke[u]) if(!ke[v].count(x)) return cout<<1<<" "<<v<<" "<<u<<" "<<x<<" "<<v<<" "<<n,0;
        forv(x,ke[v]) if(!ke[u].count(x)) return cout<<1<<" "<<u<<" "<<v<<" "<<x<<" "<<u<<" "<<n,0;
    }
    cout<<-1<<"\n";
}