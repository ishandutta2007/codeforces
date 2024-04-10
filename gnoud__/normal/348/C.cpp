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
const int N=100010,T=500;
int n,m,q,x[N],id,ke[N][210];
ll a[N],val[N],ans[N];
vector<int> e[N],sv[N];
int main()
{
    //freopen("348C.inp","r",stdin);
    //freopen("348C.out","w",stdout);
    n=in,m=in,q=in;
    forinc(i,1,n) a[i]=in;
    forinc(i,1,m)
    {
        forinc(j,1,in) e[i].pb(in);
        forv(j,e[i]) sv[j].pb(i);
        if(e[i].size()>T)
        {
            x[++id]=i;
            forv(j,e[i]) ans[i]+=a[j];
        }
    }
    forinc(i,1,id)
    {
        int u=x[i];
        forv(v,e[u]) forv(o,sv[v]) ke[o][i]++;
    }
    while(q--)
    {
        char it=getchar();
        while(it!='+'&&it!='?') it=getchar();
        if(it=='+')
        {
            int u=in,c=in;
            if(e[u].size()<=T)
            {
                forv(i,e[u]) a[i]+=c;
                forinc(i,1,id) ans[x[i]]+=1ll*c*ke[u][i];
            }
            else val[u]+=c;
        }
        else
        {
            int u=in;
            if(e[u].size()<=T)
            {
                ll kq=0;
                forv(i,e[u]) kq+=a[i];
                forinc(i,1,id) kq+=1ll*ke[u][i]*val[x[i]];
                cout<<kq<<"\n";
            }
            else
            {
                ll kq=ans[u];
                forinc(i,1,id) kq+=1ll*ke[u][i]*val[x[i]];
                cout<<kq<<"\n";
            }
        }
    }
}