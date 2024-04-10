//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int mod=1e9+7;
int n,cnt;
int mk[5011],sz;
pair<int,int>a[5011];
pair<int,pair<short,short> > e[25000111];
inline int myabs(const int &x){return x>0?x:-x;}
inline int dist(const pair<int,int> &p1,const pair<int,int> &p2){return myabs(p1.FF-p2.FF)+myabs(p1.SS-p2.SS);}
struct dsu
{
    int f[5011],op[5011];
    dsu()
    {
        for(int i=0;i<=5000;i++)f[i]=i,op[i]=-1;
    }
    int Find(int x)
    {
        if(x==f[x])return x;
        return f[x]=Find(f[x]);
    }
    bool Union(pair<int,int> p)
    {
        if(Find(p.FF)==Find(p.SS))return false;
        if(op[p.FF]==-1)op[p.FF]=p.SS;
        if(op[p.SS]==-1)op[p.SS]=p.FF;
        f[Find(p.FF)]=f[Find(op[p.SS])];
        f[Find(p.SS)]=f[Find(op[p.FF])];
        return true;
    }
    void connect(pair<int,int> p)
    {
        f[Find(p.FF)]=f[Find(p.SS)];
    }
    int count()
    {
        int cnt=0;
        for(int i=1;i<=n;i++)if(f[i]==i)cnt++;
        return cnt;
    }
}d1,d2;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].FF>>a[i].SS;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            e[sz++]=MP(-dist(a[i],a[j]),MP(i,j));
        }
    }
    sort(e,e+sz);
    int last=-1,k=0;
    while(k<sz)
    {
        bool ok=1;
        while(k+1<sz&&e[k].FF==e[k+1].FF)
        {
            if(d1.Union(e[k++].SS)==0)
            {
                ok=0;
                break;
            }
        }
        if(ok==0||d1.Union(e[k].SS)==0)break;
        for(int i=last+1;i<=k;i++)d2.connect(e[i].SS);
        last=k++;
    }
    cout<<-e[last+1].FF<<endl;
    ll ans=1,cnt=d2.count();
    for(int i=1;i<=cnt;i++)ans=ans*2%mod;
    cout<<ans<<endl;
    return 0;
}