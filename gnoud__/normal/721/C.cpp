#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define stop system("pause")
#define fi first
#define se second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
#define mp make_pair
#define pp pop_back()
#define mp3(a,b,c) mp(a,mp(b,c))
#define mp4(a,b,c,d) mp(mp(a,b),mp(c,d))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(min(a,d),min(b,c))
#define pii pair<int,int>
#define piii pair<int,pii >
#define pi4 pair<pair<int,int>,pair<int,int>>
#define all(a) a.begin(),a.end()
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define two(n) (1<<n)
#define bit(x,i) ((x>>(i-1))&1)
#define batbit(x,i) (x|(1ll<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
#define read4(a,b,c,d) read(a),read(b),read(c),read(d)
#define gcd(a,b) abs(__gcd(a,b))
#define lim 2139062143
using namespace std;
const int N=5010;
int m,n,t,f[N][N],id,trc[N][N],kq[N];
vector<pii> ke[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("C.inp","r",stdin);
    cin>>n>>m>>t;
    forinc(i,1,m)
    {
        int u,v,c;
        cin>>u>>v>>c;
        ke[v].pb({u,c});
    }
    memset(f,-1,sizeof(f));
    f[1][1]=0;
    forinc(i,2,n)
    forinc(u,1,n)
    {
        forv(v,ke[u]) if(f[v.fi][i-1]!=-1&&f[v.fi][i-1]+v.se<=t)
        {
            if(f[u][i]==-1||f[u][i]>f[v.fi][i-1]+v.se)
            {
                f[u][i]=f[v.fi][i-1]+v.se;
                trc[u][i]=v.fi;
            }
        }
    }
    fordec(i,n,1) if(f[n][i]!=-1&&f[n][i]<=t)
    {
        cout<<i<<"\n";
        int o=n,j=i,_i=i;
        while(j)
        {
            kq[_i--]=o;
            o=trc[o][j];j--;
        }
        forinc(p,1,i) cout<<kq[p]<<" ";
        return 0;
    }
}