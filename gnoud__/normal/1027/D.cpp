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
#define db double
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
const int N=200010;
stack<int> st;
int dd[N],num[N],low[N],lt[N],c[N],C[N],id,slt,n,nex[N],res;
vector<int> ke[N],kem[N];
void DFS(int u)
{
    dd[u]=true;st.push(u);
    num[u]=low[u]=++id;
    forv(v,ke[u])
    if(!dd[v])
    {
        DFS(v);
        low[u]=min(low[u],low[v]);
    }
    else if(dd[v]==1) low[u]=min(low[u],num[v]);
    if(num[u]==low[u])
    {
        slt++;
        int v;
        do
        {
            v=st.top();
            st.pop();
            lt[v]=slt;
            dd[v]=2;
        }
        while(v!=u);
    }
}
void read(int & x)
{
    x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
}
int main()
{
    //freopen("bai1.inp","r",stdin);
    read(n);
    forinc(i,1,n) read(c[i]);
    forinc(i,1,n)
    {
        int x;
        read(x);nex[i]=x;
        ke[i].pb(x);
    }
    forinc(i,1,n) if(!dd[i]) DFS(i);
    reset(dd,0);reset(C,127);
    forinc(i,1,n) C[lt[i]]=min(C[lt[i]],c[i]);
    forinc(i,1,n)
    {
        if(lt[i]==lt[nex[i]]) continue;
        kem[lt[i]].pb(lt[nex[i]]);
    }
    forinc(i,1,n)
    {
        sort(kem[i].begin(),kem[i].end());
        kem[i].erase(unique(all(kem[i])),kem[i].end());
    }
    forinc(i,1,slt) if(kem[i].size()==0) res+=C[i];
    cout<<res;
}