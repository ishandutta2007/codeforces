#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forv(a,b) for(auto&a:b)
#define stop system("pause")
#define fi first
#define se second
#define ff first.first
#define fs first.second
#define sf second.first
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
const int N=100010;
struct oo {int u,v;};
oo q[N];
vector<int> ke[N];
int ans[N],t[N],m,n,Q,pos[N];
int f[1001][1001];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
void DFS(int u,int s)
{
    ans[u]=s;
    forv(v,ke[u])
    {
        vector<int> a;
        a.pb(0);
        int x=q[v].u,y=q[v].v;
        forinc(i,1,n) a.pb(f[x][i]);
        if(t[v]==1) f[x][y]=1;
        else if(t[v]==2) f[x][y]=0;
        else if(t[v]==3) forinc(i,1,n) f[x][i]=1-f[x][i];
        int ss=s;
        forinc(i,1,n) ss+=f[x][i]-a[i];
        DFS(v,ss);
        forinc(i,1,n) f[x][i]=a[i];
    }
}
int main()
{
    //freopen("D.inp","r",stdin);
    read3(m,n,Q);
    forinc(i,1,Q)
    {
        int c;read(c);
        t[i]=c;pos[i]=i;
        if(c==1||c==2)
        {
            int x,y;
            read2(x,y);
            q[i]={x,y};
            ke[i-1].pb(i);
        }
        else if(c==3)
        {
            int u;read(u);
            q[i].u=u;
            ke[i-1].pb(i);
        }
        else if(c==4)
        {
            int u;read(u);
            ke[u].pb(i);
            pos[i]=u;
        }
    }
    DFS(0,0);
    forinc(i,1,Q) cout<<ans[pos[i]]<<"\n";
}