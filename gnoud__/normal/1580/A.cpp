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
const int N = 410;
int m, n,a[N][N],s[N][N],tren[N],duoi[N],f[N],g[N];
int get(int x,int y,int u,int v){return s[u][v]-s[u][y-1]-s[x-1][v]+s[x-1][y-1];}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("A.inp","r",stdin);
    int Test; cin>>Test;
    while(Test--)
    {
        cin>>m>>n;
        forinc(i,1,m) forinc(j,1,n)
        {
            char ch; cin>>ch;
            a[i][j]=ch-'0';
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
        int ans=INT_MAX;
        forinc(i,1,m) forinc(j,i+4,m)
        {
            int tot=INT_MAX;
            forinc(t,1,n)
            {
                f[t]=j-i-1-get(i+1,t,j-1,t);
                tren[t]=tren[t-1]+(!a[i][t]);
                duoi[t]=duoi[t-1]+(!a[j][t]);
                g[t]=g[t-1] + get(i+1,t,j-1,t);
                if(t>3) ans=min(ans,g[t-1]+tren[t-1]+duoi[t-1]+f[t]+tot);
                if(t>=3) tot=min(tot,-g[t-2]-tren[t-2]-duoi[t-2]+f[t - 2]);
            }
        }
        cout<<ans<<endl;
    }
}