#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
const int N=82;
int n,k,f[N][N],x[N],dd[N],ans=INT_MAX;
vector<pii> e[N][N];
void duyet(int i)
{
    if(i>k/2)
    {
        int ret=0;
        forinc(j,1,k/2)
        {
            int t=j+1;
            if(t==k/2+1) t=1;
            bool ok=0;
            forv(x,e[x[j]][x[t]]) if(!dd[x.se])
            {
                ok=1;
                ret+=x.fi;
                break;
            }
        }
        ans=min(ans,ret);
        return;
    }
    if(i==1)
    {
        x[i]=1,dd[1]=1;
        duyet(i+1);
    }
    else forinc(j,1,n)
    {
        x[i]=j;
        dd[j]++;
        duyet(i+1);
        dd[j]--;
    }
}
int main()
{
    //freopen("1314D.inp","r",stdin);
    //freopen("1314D.out","w",stdout);
    n=in,k=in;
    forinc(i,1,n) forinc(j,1,n) f[i][j]=in;
    forinc(i,1,n) forinc(j,1,n)
    {
        forinc(k,1,n) if(k!=i&&k!=j) e[i][j].pb({f[i][k]+f[k][j],k});
        sort(all(e[i][j]));
        if(e[i][j].size()>5) e[i][j].resize(5);
    }
    duyet(1);
    cout<<ans<<"\n";
}