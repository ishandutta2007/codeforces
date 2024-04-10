#include<iostream>
#include<vector>
#include<queue>
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
const int inf=1e9+7;
const ll INF=1e18;
const int mx=500010;
vector<pi>adj[mx];
int tp[mx];
int pa[mx],pai[mx];
int sz[mx];
void dfs(int x)
{
    sz[x]=1;
    for(pi&t:adj[x])
        adj[t.fi].erase(find(all(adj[t.fi]),pi(pa[t.fi]=x,pai[t.fi]=t.se))),
        dfs(t.fi),sz[x]+=sz[t.fi];
    sort(all(adj[x]),[&](const pi&x,const pi&y){return sz[x.fi]>sz[y.fi];});
    return;
}
int dct;
int din[mx],ord[mx];
int hc[mx];
int bot[mx];
void hld(int x)
{
    ord[din[x]=++dct]=x;
    if(hc[x]==0)
        hc[x]=x;
    if(!adj[x].empty())
        hc[adj[x][0].fi]=hc[x];
    bot[hc[x]]=x;
    for(pi&t:adj[x])
        hld(t.fi);
    return;
}
priority_queue<int>anspq,ansdel;
inline int getans()
{
    while(!ansdel.empty()&&ansdel.top()==anspq.top())
        anspq.pop(),ansdel.pop();
    return anspq.top();
}
struct seg
{
    vector<pi>dpu;
    vector<pi>dpl;
    vector<int>mxv;
    vector<int>rc;
    inline void merge(int n,int s,int e,int m)
    {
        int pt=tp[pai[ord[m+1]]];
        rc[n]=rc[n*2]^rc[n*2+1]^pt;
        mxv[n]=max(mxv[n*2],mxv[n*2+1]);
        dpu[n]=dpu[n*2],dpl[n]=dpl[n*2+1];
        if(rc[n*2]==pt)
            dpu[n].fi=max(dpu[n].fi,dpu[n*2+1].fi+(m-s+1)),
            dpu[n].se=max(dpu[n].se,dpu[n*2+1].se+(m-s+1));
        else
            dpu[n].fi=max(dpu[n].fi,dpu[n*2+1].se+(m-s+1)),
            dpu[n].se=max(dpu[n].se,dpu[n*2+1].fi+(m-s+1));
        if(rc[n*2+1]==pt)
            dpl[n].fi=max(dpl[n].fi,dpl[n*2].fi+(e-m)),
            dpl[n].se=max(dpl[n].se,dpl[n*2].se+(e-m));
        else
            dpl[n].fi=max(dpl[n].fi,dpl[n*2].se+(e-m)),
            dpl[n].se=max(dpl[n].se,dpl[n*2].fi+(e-m));
        if(pt==0)
            mxv[n]=max({mxv[n],dpl[n*2].fi+dpu[n*2+1].fi+1,dpl[n*2].se+dpu[n*2+1].se+1});
        else
            mxv[n]=max({mxv[n],dpl[n*2].fi+dpu[n*2+1].se+1,dpl[n*2].se+dpu[n*2+1].fi+1});
        return;
    }
    void init(int n,int s,int e,int*v1,int*v2)
    {
        if(s==e)
        {
            dpu[n]=dpl[n]=pi(v1[s],v2[s]);
            mxv[n]=v1[s];
            rc[n]=0;
            return;
        }
        int m=s+(e-s)/2;
        init(n*2,s,m,v1,v2);
        init(n*2+1,m+1,e,v1,v2);
        merge(n,s,e,m);
        return;
    }
    inline void init(int s,int e,int*v1,int*v2)
    {
        int sz=e-s+1;
        dpu.resize(sz*4);
        dpl.resize(sz*4);
        mxv.resize(sz*4);
        rc.resize(sz*4);
        init(1,s,e,v1,v2);
        anspq.ep(mxv[1]);
        return;
    }
    void recal(int n,int s,int e,int x)
    {
        if(s==e)
            return;
        int m=s+(e-s)/2;
        if(x>m)
            recal(n*2+1,m+1,e,x);
        else
            recal(n*2,s,m,x);
        merge(n,s,e,m);
        return;
    }
    void renew(int n,int s,int e,int x,pi dp)
    {
        if(s==e)
        {
            dpu[n]=dpl[n]=dp;
            mxv[n]=dp.fi;
            return;
        }
        int m=s+(e-s)/2;
        if(x>m)
            renew(n*2+1,m+1,e,x,dp);
        else
            renew(n*2,s,m,x,dp);
        merge(n,s,e,m);
        return;
    }
    inline void recal(int s,int e,int x)
    {
        ansdel.ep(mxv[1]);
        recal(1,s,e,x);
        anspq.ep(mxv[1]);
        return;
    }
    inline void renew(int s,int e,int x,pi dp)
    {
        ansdel.ep(mxv[1]);
        renew(1,s,e,x,dp);
        anspq.ep(mxv[1]);
        return;
    }
}st[mx];
int d1[mx],d2[mx];
struct myset
{
    priority_queue<int>pq,del;
    inline void ins(int x)
    {
        pq.ep(x);
        return;
    }
    inline void delt(int x)
    {
        del.ep(x);
        return;
    }
    inline int get()
    {
        while(!del.empty()&&pq.top()==del.top())
            pq.pop(),del.pop();
        if(pq.empty())
            return-inf;
        return pq.top();
    }
}pq1[mx],pq2[mx];
void init(int x)
{
    for(pi&t:adj[x])
    {
        init(t.fi);
        if(t.fi==hc[t.fi])
        {
            pi tc=st[t.fi].dpu[1];
            if(tp[t.se]==0)
                pq1[x].ins(tc.fi+1),pq2[x].ins(tc.se+1);
            else
                pq1[x].ins(tc.se+1),pq2[x].ins(tc.fi+1);
        }
    }
    int mx1=max(pq1[x].get(),0),mx2=pq2[x].get();
    d1[din[x]]=mx1,d2[din[x]]=mx2;
    if(hc[x]==x)
        st[x].init(din[x],din[bot[x]],d1,d2);
    return;
}
inline void upd(int x)
{
    int cp=hc[x];
    while(cp!=1)
    {
        int ncp=hc[pa[cp]];
        int pcp=pa[cp];
        pi nx;
        pi tc=st[cp].dpu[1];
        if(tp[pai[cp]]==0)
            pq1[pcp].delt(tc.fi+1),pq2[pcp].delt(tc.se+1);
        else
            pq1[pcp].delt(tc.se+1),pq2[pcp].delt(tc.fi+1);
        cp=ncp;
    }
    tp[pai[x]]^=1;
    cp=hc[x];
    st[cp].recal(din[cp],din[bot[cp]],din[x]);
    while(cp!=1)
    {
        int ncp=hc[pa[cp]];
        int pcp=pa[cp];
        pi nx;
        pi tc=st[cp].dpu[1];
        if(tp[pai[cp]]==0)
            pq1[pcp].ins(tc.fi+1),pq2[pcp].ins(tc.se+1);
        else
            pq1[pcp].ins(tc.se+1),pq2[pcp].ins(tc.fi+1);
        pi cc(max(0,pq1[pcp].get()),pq2[pcp].get());
        st[ncp].renew(din[ncp],din[bot[ncp]],din[pcp],cc);
        cp=ncp;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pi>ed(n);
    for(int i=1;i<n;i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        ed[i]=pi(u,v);
        adj[u].eb(v,i);
        adj[v].eb(u,i);
        tp[i]=d;
    }
    dfs(1);
    hld(1);
    init(1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int id;
        cin>>id;
        if(pa[ed[id].fi]==ed[id].se)
            upd(ed[id].fi);
        else
            upd(ed[id].se);
        cout<<getans()<<'\n';
    }
    return 0;
}