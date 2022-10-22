#include<bits/stdc++.h>
#define rep(i,a,n) for(auto i=(a);i<=(n);i++)
#define per(i,a,n) for(auto i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int maxn = 1000010;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header
bool np[maxn+5];
int Mpfac[maxn+5];
vi pfacs[maxn+5];

int a[maxn+5];

void precal(int x)
{
    if(pfacs[x].size()>0) return;
    vi &A=pfacs[x];
    while(x!=1)
    {
        int p=Mpfac[x];
        A.pb(p);
        while(x%p==0) x/=p;
    }
}

struct Union_Set
{
    array<int,maxn+5> fa,sz;
    void init(int n) 
    {
        rep(i,1,n) fa[i]=i,sz[i]=1;
    }
    int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
	bool check(int x,int y) {return getfa(x)==getfa(y);}
    void merge(int x,int y)
    {
        int fx=getfa(x),fy=getfa(y);
        if(fx==fy) return;
        if(sz[fx]<sz[fy]) swap(fx,fy);
        fa[fy]=fx;
        sz[fx]+=sz[fy];
    }
}us;

set<int> link[maxn+5];

int main()
{
    np[0]=np[1]=1;
    rep(i,2,maxn) if(np[i]==0)
    {
        chmax(Mpfac[i],i);
        for(int j=i*2;j<=maxn;j+=i) np[j]=1,chmax(Mpfac[j],i);
    }

    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) precal(a[i]),precal(a[i]+1);

    us.init(maxn);
    rep(i,1,n)
    {
        int x=a[i];
        if(pfacs[x].size()>1)
        {
            int N=pfacs[x].size();
            rep(i,2,N)
            {
                int px=pfacs[x][i-2],py=pfacs[x][i-1];
                us.merge(px,py);
            }
        }
    }
    //puts("ok");

    vi tmp;
    rep(i,1,n)
    {
        int x=a[i];
        tmp.clear();
        tmp.pb(us.getfa(Mpfac[x]));
        for(auto p: pfacs[x+1]) tmp.pb(us.getfa(p));
        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        int N=tmp.size();
        rep(i,1,N) rep(j,i+1,N)
        {
            link[tmp[i-1]].insert(tmp[j-1]);
        }
    }

    while(q--)
    {
        int id1,id2; scanf("%d%d",&id1,&id2);
        int x=a[id1],y=a[id2];
        int fx=us.getfa(Mpfac[x]);
        int fy=us.getfa(Mpfac[y]);

        if(fx==fy) puts("0");
        else
        {
            if(fx>fy) swap(fx,fy);
            if(link[fx].count(fy)>0) puts("1");
            else puts("2");
        }
    }
    return 0; 
}