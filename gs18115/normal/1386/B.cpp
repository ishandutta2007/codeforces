#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1ll<<30;
const ll INF=inf*inf;
inline bool i128c(const ll&a,const ll&b,const ll&c,const ll&d)
{
    if(b>=0&&d<=0)
        return 0;
    if(b<0&&d>0)
        return 1;
    if(b==0)
        return d>0;
    if(d==0)
        return b<0;
    if(b<0)
        return i128c(c,-d,a,-b);
    ll v11=(a/inf)*(b/inf);
    ll v12=(a/inf)*(b%inf)+(a%inf)*(b/inf);
    ll v13=(a%inf)*(b%inf);
    v12+=v13/inf;
    v13%=inf;
    v11+=v12/inf;
    v12%=inf;
    ll v21=(c/inf)*(d/inf);
    ll v22=(c/inf)*(d%inf)+(c%inf)*(d/inf);
    ll v23=(c%inf)*(d%inf);
    v22+=v23/inf;
    v23%=inf;
    v21+=v22/inf;
    v22%=inf;
    return v11==v21?(v12==v22?v13<v23:v12<v22):v11<v21;
}
int zp,zm,zc;
inline bool cmpf(const pl&x,const pl&y)
{
    return i128c(x.se,y.fi,y.se,x.fi);
}
struct cmp
{
    inline bool operator()(const pl&x,const pl&y)const
    {
        return i128c(x.se,y.fi,y.se,x.fi);
    }
};
inline ll mygcd(ll x,ll y)
{
    while(y!=0)
        x%=y,swap(x,y);
    return x;
}
map<pl,int,cmp>pc,mc;
ll cmt;
pl bot[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll aa,bb,cc;
    cin>>aa>>bb>>cc;
    int flag=0;
    if(aa==0)
    {
        if(bb!=0)
            flag=1,swap(aa,bb);
        else
            flag=2,swap(aa,cc);
    }
    int tc;
    cin>>tc;
    int bct=0;
    for(int ti=0;ti<tc;ti++)
    {
        char tp;
        cin>>tp;
        if(tp=='A')
        {
            int id=++bct;
            ll a,b,c;
            cin>>a>>b>>c;
            if(flag==1)
                swap(a,b);
            else if(flag==2)
                swap(a,c);
            ll x=b*aa-bb*a;
            ll y=c*aa-cc*a;
            if(x!=0||y!=0)
            {
                ll g=abs(mygcd(x,y));
                x/=g;
                y/=g;
            }
            bot[id]=pl(x,y);
            if(x==0)
            {
                if(y==0)
                    zc++;
                else
                    (y==1?zp:zm)++;
            }
            else if(x>0)
            {
                cmt+=mc[pl(x,y)];
                pc[pl(x,y)]++;
            }
            else
            {
                cmt+=pc[pl(-x,-y)];
                mc[pl(-x,-y)]++;
            }
        }
        else
        {
            int id;
            cin>>id;
            ll x=bot[id].fi;
            ll y=bot[id].se;
            if(x==0)
            {
                if(y==0)
                    zc--;
                else
                    (y==1?zp:zm)--;
            }
            else if(x>0)
            {
                pc[pl(x,y)]--;
                cmt-=mc[pl(x,y)];
            }
            else
            {
                mc[pl(-x,-y)]--;
                cmt-=pc[pl(-x,-y)];
            }
        }
        while(!pc.empty()&&pc.begin()->se==0)
            pc.erase(pc.begin());
        while(!pc.empty()&&pc.rbegin()->se==0)
            pc.erase(--pc.end());
        while(!mc.empty()&&mc.begin()->se==0)
            mc.erase(mc.begin());
        while(!mc.empty()&&mc.rbegin()->se==0)
            mc.erase(--mc.end());
        if(zc>0)
            cout<<"1\n";
        else if((zp>0&&zm>0)||cmt>0)
            cout<<"2\n";
        else if(pc.empty()||mc.empty())
            cout<<"0\n";
        else
        {
            bool f1=cmpf(pc.begin()->fi,mc.rbegin()->fi)||zm>0;
            bool f2=cmpf(mc.begin()->fi,pc.rbegin()->fi)||zp>0;
            if(f1&&f2)
                cout<<"3\n";
            else
                cout<<"0\n";
        }
    }
    cout.flush();
    return 0;
}