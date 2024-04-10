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
const int N=3e5+10,mod=998244353;
int n,m,f[N],res,dd[N],cnt,sum,tg,Z[N],ok;
vector<int> ke[N];
void DFS(int u,int val)
{
    if (dd[u]==cnt)
    {
        if (Z[u]!=val)
            ok=0;
        return;
    }
    dd[u]=cnt;
    Z[u]=val;
    ++sum;
    tg+=val;
    forv(v,ke[u]) DFS(v,1-val);
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
    // freopen("a.inp","r",stdin);
    //  freopen("a.out","w",stdout);
    f[0]=1;
    forinc(i,1,N+1) f[i]=f[i-1]*2%mod;
    int t;
    read(t);
    while (t--)
    {
        read2(n,m);
        forinc(i,1,n) ke[i].clear();
        forinc(i,1,m)
        {
            int u,v;
            read2(u,v);
            ke[u].pb(v);
            ke[v].pb(u);
        }
        ++cnt;
        res=1;
        ok=1;
        forinc(i,1,n) if (dd[i]!=cnt)
        {
            sum=tg=0;
            DFS(i,0);
            if (ok==0)
            {
                cout << 0 << "\n";
                break;
            }
            res=(ll)res*(f[tg]+f[sum-tg])%mod;
        }
        if(ok) cout << res <<"\n";
    }
}