#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
struct point
{
    int id;
    ll x,y,z;
    point(){}
    point(ll x,ll y,ll z,int id=0):x(x),y(y),z(z),id(id){}
};
struct poly
{
    ld x,y,z;
    poly():x(0),y(0),z(0){}
    poly(ld z):x(0),y(0),z(z){}
    poly(ld y,ld z):x(0),y(y),z(z){}
    poly(ld x,ld y,ld z):x(x),y(y),z(z){}
    poly(point x):x(x.x),y(x.y),z(x.z){}
    poly operator+(poly t)
    {
        return poly(x+t.x,y+t.y,z+t.z);
    }
    poly operator-(poly t)
    {
        return poly(x-t.x,y-t.y,z-t.z);
    }
    poly operator*(poly t)
    {
        return poly(x*t.z+y*t.y+z*t.x,y*t.z+z*t.y,z*t.z);
    }
    poly operator*(ld t)
    {
        return poly(x*t,y*t,z*t);
    }
    poly operator/(ld t)
    {
        return poly(x/t,y/t,z/t);
    }
    ld eval(ld h)
    {
        return x*h*h+y*h+z;
    }
};
const int mxn=100010;
poly hap[mxn];
int pa[mxn];
int par(int x)
{
    if(pa[x]==-1)
        return x;
    return pa[x]=par(pa[x]);
}
void uni(int x,int y)
{
    x=par(x);
    y=par(y);
    if(x==y)
        return;
    pa[x]=y;
    hap[y]=hap[x]+hap[y];
    return;
}
poly face[mxn];
int isup[mxn];
void inituni()
{
    fill(isup,isup+mxn,0);
    fill(face,face+mxn,poly());
    fill(hap,hap+mxn,poly());
    fill(pa,pa+mxn,-1);
    return;
}
poly crossprod(poly x,poly y)
{
    return poly(x.y*y.z-x.z*y.y,x.z*y.x-x.x*y.z,x.x*y.y-x.y*y.x);
}
ld calc_area(poly x,poly y,poly z)
{
    poly av=crossprod(x-y,x-z);
    return sqrt(av.x*av.x+av.y*av.y+av.z*av.z)/2;
}
poly incut(poly x,poly y,ld p,ld q)
{
    return (x*q+y*p)/(p+q);
}
void upds(int s,vector<point>&vp,vector<point>&surf)
{
    const point&cur=surf[s];
    int unipa=par(s);
    hap[unipa]=hap[unipa]-face[s];
    vector<point>upv,downv;
    (isup[cur.x]==1?upv:downv).eb(vp[cur.x]);
    (isup[cur.y]==1?upv:downv).eb(vp[cur.y]);
    (isup[cur.z]==1?upv:downv).eb(vp[cur.z]);
    int upc=upv.size();
    if(upc==0)
        face[s]=poly();
    if(upc==1)
    {
        if(upv[0].z==downv[0].z||upv[0].z==downv[1].z)
            face[s]=0;
        else
        {
            poly p1=incut(poly(upv[0]),poly(downv[0]),1,(upv[0].z-downv[0].z)-1);
            poly p2=incut(poly(upv[0]),poly(downv[1]),1,(upv[0].z-downv[1].z)-1);
            poly unita(calc_area(poly(upv[0]),p1,p2));
            poly hei(-1,upv[0].z);
            face[s]=hei*hei*unita;
        }
    }
    if(upc==2)
    {
        if(upv[0].z==downv[0].z||upv[1].z==downv[0].z)
            face[s]=poly(calc_area(poly(upv[0]),poly(upv[1]),poly(downv[0])));
        else
        {
            poly alla(calc_area(poly(upv[0]),poly(upv[1]),poly(downv[0])));
            poly p1=incut(poly(downv[0]),poly(upv[0]),1,(upv[0].z-downv[0].z)-1);
            poly p2=incut(poly(downv[0]),poly(upv[1]),1,(upv[1].z-downv[0].z)-1);
            poly unita(calc_area(poly(downv[0]),p1,p2));
            poly hei(1,-downv[0].z);
            face[s]=alla-hei*hei*unita;
        }
    }
    if(upc==3)
        face[s]=poly(calc_area(poly(upv[0]),poly(upv[1]),poly(upv[2])));
    hap[unipa]=hap[unipa]+face[s];
    return;
}
void updp(int p,vector<point>&vp,vector<point>&surf,vector<vector<int> >&psv)
{
    isup[p]=1;
    for(int i=1;i<(int)psv[p].size();i++)
        uni(psv[p][i-1],psv[p][i]);
    for(int&t:psv[p])
        upds(t,vp,surf);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int n,m,q;
    cin>>n;
    vector<point>vp(n);
    for(auto&t:vp)
        cin>>t.x>>t.y>>t.z;
    cin>>m;
    vector<point>surf(m);
    for(auto&t:surf)
        cin>>t.x>>t.y>>t.z;
    vector<vector<int> >psv(n);
    for(int i=0;i<m;i++)
    {
        auto&t=surf[i];
        psv[--t.x].eb(i);
        psv[--t.y].eb(i);
        psv[--t.z].eb(i);
    }
    cin>>q;
    vector<point>vq(q);
    for(int i=0;i<q;i++)
    {
        auto&t=vq[i];
        cin>>t.x>>t.y;
        t.z=i;
    }

    vector<int>pidv(n);
    for(int i=0;i<n;i++)
        pidv[i]=i;
    sort(all(pidv),[&](const int&x,const int&y){return vp[x].z>vp[y].z;});
    sort(all(vq),[](const point&x,const point&y){return x.x>y.x;});
    int vpi=0;
    inituni();
    vector<bool>islow(q);
    vector<ld>ans(q);
    for(auto&t:vq)
    {
        while(vpi<n&&vp[pidv[vpi]].z>t.x)
        {
            updp(pidv[vpi],vp,surf,psv);
            vpi++;
        }
        t.y--;
        if(isup[t.y]==0)
            islow[t.z]=1;
        else if(psv[t.y].empty())
            ans[t.z]=0;
        else
            ans[t.z]=hap[par(psv[t.y][0])].eval(t.x);
    }
    for(int i=0;i<q;i++)
    {
        if(islow[i])
            cout<<-1;
        else
            cout<<ans[i];
        cout<<'\n';
    }
    return 0;
}