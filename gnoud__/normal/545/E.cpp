#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define read3(a,b,c) read(a),read(b),read(c)
using namespace std;
const int N=300010;
int dd[N],n,m,s,t,d[N],trc[N],c[N],kq;
pii id[N];
vector<pii> ke[N],ad[N];
vector<int> o;
priority_queue<pii,vector<pii>,greater<pii> > heap;
void BFS(int u)
{
    memset(dd,0,sizeof(dd));
    forinc(i,1,n) d[i]=1e17;
    d[u]=0;
    heap.push({0,s});
    while(!heap.empty())
    {
        pii u=heap.top();heap.pop();
        forv(v,ke[u.se]) if(u.fi+c[v.se]<d[v.fi]||((d[v.fi]==u.fi+c[v.se])&&d[id[v.fi].se]<u.fi))
        {
            kq-=c[id[v.fi].fi];
            kq+=c[v.se];
            id[v.fi]={v.se,u.se};
            trc[v.fi]=u.se;
            d[v.fi]=u.fi+c[v.se];
            heap.push({d[v.fi],v.fi});
        }
    }
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9') {x=x*10+c-'0';c=getchar();}
}
main()
{
    //freopen("567E.inp","r",stdin);
    //freopen("567E.out","w",stdout);
    read(n);read(m);
    forinc(i,1,m)
    {
        int u,v,C;
        read3(u,v,C);
        c[i]=C;
        ke[u].pb({v,i});
        ke[v].pb({u,i});
    }
    read(s);
    BFS(s);
    cout<<kq<<"\n";
    forinc(i,1,n) if(i!=s) o.pb(id[i].fi);
    sort(o.begin(),o.end());
    forv(v,o) cout<<v<<" ";
}