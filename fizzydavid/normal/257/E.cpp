//No debug vision
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=200000000000000;
const ll LINF=1ll<<61;
struct person
{
    int id,from,to;
    ll ti;
    bool operator<(const person &tmp)const
    {
        return ti<tmp.ti;
    }
}p[100111];
int n,m;
struct BIT
{
    int a[100111];
    BIT(){memset(a,0,sizeof(a));}
    void add(int x,int i)
    {
        while(x<=m)
        {
            a[x]+=i;
            x+=x&(-x);
        }
    }
    int sum(int x)
    {
        int res=0;
        while(x>0)
        {
            res+=a[x];
            x-=x&(-x);
        }
        return res;
    }
}bit;
int curf;
ll curt,ans[100111];
map<int,set<int> >req;
set<int>reqfl;
bool on[100111];
set<int>::iterator it,it2;
void update(int p)
{
    if(req[p].size()==0&&reqfl.find(p)!=reqfl.end())reqfl.erase(p);
    else if(req[p].size()>0)reqfl.insert(p);
}
void move(ll lim)
{
    ll sumdown=bit.sum(curf),sumup=bit.sum(m)-sumdown,d=0;
    if(sumup==0&&sumdown==0)
    {
        if(lim<INF)curt=lim;else curt=INF;
    }
    else if(sumup>=sumdown)
    {
        d=min(ll(*(reqfl.lower_bound(curf))-curf),lim-curt);
        curf+=d;
    }
    else
    {
        d=min(ll(curf-*(--reqfl.lower_bound(curf))),lim-curt);
        curf-=d;
    }
    curt+=d;
}
void opendoor()
{
    it2=req[curf].end();
    for(it=req[curf].begin();it!=it2;it++)
    {
        int i=*it;
        bit.add(curf,-1);
        if(!on[i])
        {
            on[i]=1;
            req[p[i].to].insert(i);
            bit.add(p[i].to,1);
            update(p[i].to);
        }
        else ans[p[i].id]=curt;
    }
    req[curf].clear();
    update(curf);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%I64d%d%d",&p[i].ti,&p[i].from,&p[i].to),p[i].id=i;
    sort(p+1,p+1+n);
    curf=curt=1;
    int i=1;
    while(true)
    {
        ll lim;
        if(i<=n)lim=p[i].ti;else lim=INF;
        while(curt<lim)opendoor(),move(lim);
        if(curt==INF)break;
        while(i<=n&&curt==p[i].ti)
        {
            req[p[i].from].insert(i);
            bit.add(p[i].from,1);
            update(p[i].from);
            i++;
        }
        opendoor();
    }
    for(int i=1;i<=n;i++)printf("%I64d\n",ans[i]);
    return 0;
}