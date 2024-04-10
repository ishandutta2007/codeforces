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
#define ii pair<pii,int>
const int N=3e5+10;
int n,w,t[4*N],T[4*N],v[N],dd[N];
pii a[N];
priority_queue<pii,vector<pii>,greater<pii> > h;
priority_queue<ii,vector<ii>,greater<ii> > heap;
vector<int> e;
void upd(int s,int l,int r,int u,int x)
{
    if(l>u||r<u) return;
    if(l==r)
    {
        t[s]+=x;
        T[s]+=v[l]*x;
        return;
    }
    int mid=(l+r)/2;
    upd(2*s,l,mid,u,x);
    upd(2*s+1,mid+1,r,u,x);
    t[s]=t[2*s]+t[2*s+1];
    T[s]=T[2*s]+T[2*s+1];
}
int get(int s,int l,int r,int k)
{
    if(l==r) return k*v[l];
    int mid=(l+r)/2;
    if(t[2*s]>=k) return get(2*s,l,mid,k);
    return T[2*s]+get(2*s+1,mid+1,r,k-t[2*s]);
}
main()
{
    //freopen("436E.inp","r",stdin);
    n=in,w=in;
    forinc(i,1,n)
    {
        a[i]={in,in};
        e.pb(a[i].se);
        h.push(a[i]);
    }
    sort(all(e));
    e.erase(unique(all(e)),e.end());
    forinc(i,1,n)
    {
        int x=lower_bound(all(e),a[i].se)-e.begin()+1;
        v[x]=a[i].se;
        upd(1,1,n,x,1);
    }
    int ans=get(1,1,n,(w+1)/2),I=0,r1=0,s=0;
    while(!h.empty())
    {
        pii u=h.top();h.pop();
        r1+=u.fi,s++;
        if(u.se!=-1)
        {
            upd(1,1,n,lower_bound(all(e),u.se)-e.begin()+1,-1);
            h.push({u.se-u.fi,-1});
        }
        if(t[1]>=(w-s+1)/2)
        {
            int r2=get(1,1,n,(w-s+1)/2);
            if(r1+r2<ans) ans=r1+r2,I=s;
        }
    }
    cout<<ans<<"\n";
    forinc(i,1,n) heap.push({{a[i].fi,a[i].se},i});
    forinc(i,1,I)
    {
        ii tg=heap.top();heap.pop();
        pii u=tg.fi;
        dd[tg.se]++;
        if(dd[tg.se]==1) heap.push({{u.se-u.fi,-1},tg.se});
    }
    vector<pii> sv;
    forinc(i,1,n) if(!dd[i]) sv.pb({a[i].se,i});
    sort(all(sv));
    forinc(i,0,(w-I+1)/2-1) dd[sv[i].se]=2;
    forinc(i,1,n) cout<<dd[i];
}