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
#define db double
using namespace std;
const int N=1010;
db ESP=1e-15;
int id[N],n;
pii a[N];
int root(int x) {return id[x]<0?x:id[x]=root(id[x]);}
void unions(int u,int v)
{
    if(id[u]>id[v]) swap(u,v);
    id[u]+=id[v];
    id[v]=u;
}
int pw(int u) {return u*u;}
db dis(pii u,pii v) {return sqrt(db(pw(u.fi-v.fi))+db(pw(u.se-v.se)));}
bool cheq(int i,int j)
{
    if(dis(a[i],a[0])+dis(a[j],a[0])-dis(a[i],a[j])<ESP) return 1;
    if(dis(a[i],a[j])+dis(a[j],a[0])-dis(a[i],a[0])<ESP) return 1;
    if(dis(a[i],a[0])+dis(a[j],a[i])-dis(a[0],a[j])<ESP) return 1;
    return 0;
}
int main()
{
    //freopen("hsl.inp","r",stdin);
    cin>>n>>a[0].fi>>a[0].se;
    forinc(i,1,n) cin>>a[i].fi>>a[i].se;
    reset(id,-1);
    forinc(i,1,n-1) forinc(j,i+1,n) if(cheq(i,j))
    {
        int u=root(i),v=root(j);
        if(u==v) continue;
        unions(u,v);
    }
    int res=0;
    forinc(i,1,n) if(id[i]<0) res++;
    cout<<res;
}