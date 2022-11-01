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
const int N=200010;
int n,m,dd[N],id,M[N],fre[N];
vector<int> ke[N];
void DFS(int u)
{
    dd[u]=id;
    M[id]=max(M[id],u);
    forv(v,ke[u]) if(!dd[v]) DFS(v);
}
int main()
{
    //freopen("1253D.inp","r",stdin);
    n=in,m=in;
    forinc(i,1,m)
    {
        int u=in,v=in;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    forinc(i,1,n) if(!dd[i]) ++id,DFS(i);
    int ans=0;
    int i=1;
    while(i<=n)
    {
        int r=M[dd[i]],ret=0;
        while(i<=r)
        {
            if(!fre[dd[i]])
            {
                ++ret;
                fre[dd[i]]=1;
            }
            r=max(r,M[dd[i++]]);
        }
        ans+=(ret-1);
    }
    cout<<ans<<"\n";
}