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
int f[2010][2010],n,k,dis;
char a[2010][2010];
void read(char & c)
{
    c=getchar();
    while(c<'a'||c>'z') c=getchar();
}
vector<pii> q,_q;
main()
{
    //freopen("a.inp","r",stdin);
    cin>>n>>k;
    forinc(i,1,n) forinc(j,1,n) read(a[i][j]);
    memset(f,127,sizeof(f));
    if(a[1][1]=='a') f[1][1]=0;
    else f[1][1]=1;
    forinc(i,1,n) forinc(j,1,n)
    {
        int o=1;
        if(a[i][j]=='a') o=0;
        if(i>1) f[i][j]=min(f[i][j],f[i-1][j]+o);
        if(j>1) f[i][j]=min(f[i][j],f[i][j-1]+o);
        if(f[i][j]<=k) dis=max(dis,i+j-2);
    }
    forinc(i,1,n) forinc(j,1,n) if(f[i][j]<=k&&i+j-2==dis) q.pb({i,j});
    if(q.empty()) {q.pb({1,1});cout<<a[1][1];}
    else
    {
        forinc(i,1,dis+1) cout<<"a";
    }
    forinc(p,1,2*n-2-dis)
    {
        int o=25;
        forv(x,q)
        {
            if(x.fi<n) o=min(o,a[x.fi+1][x.se]-'a');
            if(x.se<n) o=min(o,a[x.fi][x.se+1]-'a');
        }
        cout<<char(o+'a');
        forv(x,q)
        {
            if(x.fi<n) if(a[x.fi+1][x.se]-'a'==o) _q.pb({x.fi+1,x.se});
            if(x.se<n) if(a[x.fi][x.se+1]-'a'==o) _q.pb({x.fi,x.se+1});
        }
        q=_q;_q.clear();
        sort(q.begin(),q.end());
        q.erase(unique(q.begin(),q.end()),q.end());
    }
}