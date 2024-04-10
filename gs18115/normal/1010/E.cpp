#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const int INF=1e9;
int MX,MY,MZ,N,M,Q;
struct seg
{
    vector<int>n,v;
    inline void init()
    {
        sort(n.begin(),n.end());
        n.erase(unique(n.begin(),n.end()),n.end());
        v.resize(n.size()*4+10);
        fill(v.begin(),v.end(),-INF);
        return;
    }
    void SI(int N,int s,int e,int x,int p)
    {
        v[N]=max(v[N],p);
        if(s==e)
            return;
        int m=s+e>>1;
        if(x>m)
            SI(N<<1|1,m+1,e,x,p);
        else
            SI(N<<1,s,m,x,p);
        return;
    }
    int SM(int N,int s,int e,int S,int E)
    {
        if(s>E||S>e)
            return -INF;
        if(s>=S&&e<=E)
            return v[N];
        int m=s+e>>1;
        return max(SM(N<<1,s,m,S,E),SM(N<<1|1,m+1,e,S,E));
    }
};
struct seg2d
{
    seg2d*l,*r;
    seg*v;
    seg2d()
    {
        l=r=nullptr;
        v=new seg();
    }
    void init(int s,int e,bool flag)
    {
        if(flag)
            v->init();
        if(s==e)
            return;
        if(!l)
            l=new seg2d();
        if(!r)
            r=new seg2d();
        int m=s+e>>1;
        l->init(s,m,flag);
        r->init(m+1,e,flag);
    }
    void init(int s,int e,int x,int p)
    {
        v->n.push_back(p);
        if(s==e)
            return;
        int m=s+e>>1;
        if(x>m)
            r->init(m+1,e,x,p);
        else
            l->init(s,m,x,p);
    }
    void SI(int s,int e,int x,int y,int p)
    {
        v->SI(1,0,v->n.size()-1,lower_bound(v->n.begin(),v->n.end(),y)-v->n.begin(),p);
        if(s==e)
            return;
        int m=s+e>>1;
        if(x>m)
            r->SI(m+1,e,x,y,p);
        else
            l->SI(s,m,x,y,p);
        return;
    }
    int SM(int s,int e,int sx,int ex,int sy,int ey)
    {
        if(s>ex||sx>e)
            return -INF;
        if(s>=sx&&e<=ex)
        {
            sy=lower_bound(v->n.begin(),v->n.end(),sy)-v->n.begin();
            ey=upper_bound(v->n.begin(),v->n.end(),ey)-v->n.begin()-1;
            if(sy>ey)
                return -INF;
            return v->SM(1,0,v->n.size()-1,sy,ey);
        }
        int m=s+e>>1;
        return max(l->SM(s,m,sx,ex,sy,ey),r->SM(m+1,e,sx,ex,sy,ey));
    }
}MST,mst;
int mx,my,mz,mX,mY,mZ;
int i,x,y,z;
int xlb,xrb,ylb,yrb;
bool flag;
int nx[100010],ny[100010],nz[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>MX>>MY>>MZ>>N>>M>>Q;
    mx=MX;
    my=MY;
    mz=MZ;
    for(i=0;i<N;i++)
    {
        cin>>x>>y>>z;
        mx=min(mx,x);
        mX=max(mX,x);
        my=min(my,y);
        mY=max(mY,y);
        mz=min(mz,z);
        mZ=max(mZ,z);
    }
    MST.init(1,MX,false);
    mst.init(1,MX,false);
    for(i=0;i<M;i++)
    {
        cin>>nx[i]>>ny[i]>>nz[i];
        if(nz[i]<=mZ)
            MST.init(1,MX,nx[i],ny[i]);
        if(nz[i]>=mz)
            mst.init(1,MX,nx[i],ny[i]);
    }
    MST.init(1,MX,true);
    mst.init(1,MX,true);
    for(i=0;i<M;i++)
    {
        x=nx[i];
        y=ny[i];
        z=nz[i];
        if(mx<=x&&x<=mX&&my<=y&&y<=mY&&mz<=z&&z<=mZ)
            return cout<<"INCORRECT"<<endl,0;
        if(z<mz)
            MST.SI(1,MX,x,y,z);
        else if(z<=mZ)
        {
            MST.SI(1,MX,x,y,z);
            mst.SI(1,MX,x,y,-z);
        }
        else
            mst.SI(1,MX,x,y,-z);
    }
    cout<<"CORRECT";
    while(Q-->0)
    {
        cin>>x>>y>>z;
        if(mx<=x&&x<=mX&&my<=y&&y<=mY&&mz<=z&&z<=mZ)
            cout<<"\nOPEN";
        else
        {
            if(x<mx)
                xlb=x,xrb=mX;
            else if(x<=mX)
                xlb=mx,xrb=mX;
            else
                xlb=mx,xrb=x;
            if(y<my)
                ylb=y,yrb=mY;
            else if(y<=mY)
                ylb=my,yrb=mY;
            else
                ylb=my,yrb=y;
            if(z<mz)
                flag=MST.SM(1,MX,xlb,xrb,ylb,yrb)>=z;
            else if(z<=mZ)
                flag=MST.SM(1,MX,xlb,xrb,ylb,yrb)>=mz;
            else
                flag=-mst.SM(1,MX,xlb,xrb,ylb,yrb)<=z;
            if(flag)
                cout<<"\nCLOSED";
            else
                cout<<"\nUNKNOWN";
        }
    }
    cout<<endl;
    return 0;
}