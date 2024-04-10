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
int mysqrt(int x)
{
    int s=1,e=2000;
    while(s<e)
    {
        int m=s+(e-s+1)/2;
        if(m*m<=x)
            s=m;
        else
            e=m-1;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int&t:v)
        cin>>t;
    vector<pi>nv;
    for(int&t:v)
    {
        if(nv.empty())
            nv.eb(t,t);
        else if(t-nv.back().se<=mysqrt(nv.back().se))
            nv.back().se=t;
        else
            nv.eb(t,t);
    }
    n=nv.size();
    vector<pair<pi,int> >blk(n);
    for(int i=0;i<n;i++)
    {
        blk[i].fi=nv[i];
        int j=mysqrt(nv[i].fi);
        if(j<nv[i].se-nv[i].fi)
            blk[i].se=nv[i].se-nv[i].fi;
        else if(nv[i].se<=(ll)j*j+j)
            blk[i].se=j;
        else
            blk[i].se=j+1;
    }
    int cnt=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq; //max, min, index
    ll mn=-INF;
    for(int i=0;i<n;i++)
    {
        auto&t=blk[i];
        ll j=t.se;
        mn=max(mn,j*j-t.fi.fi);
        ll mx=j*j+j-t.fi.se;
        pq.ep(mx,i);
    }
    while(1)
    {
        if(cnt>=n*2)
        {
            vector<pair<pi,int> >pv;
            for(auto&t:blk)
            {
                if(pv.empty())
                    pv.eb(t);
                else if(t.fi.fi-pv.back().fi.se<=pv.back().se)
                    pv.back().fi.se=t.fi.se,blk.back().se=max(blk.back().se,t.se);
                else
                    pv.eb(t);
            }
            blk=pv;
            n=blk.size();
            for(auto&t:blk)
            {
                int j=mysqrt(t.fi.fi);
                if(j<t.fi.se-t.fi.fi)
                    j=t.fi.se-t.fi.fi;
                else if(t.fi.se>(ll)j*j+j)
                    j++;
                if(j>t.se)
                    t.se=j;
            }
            cnt=0;
            while(!pq.empty())
                pq.pop();
            mn=-INF;
            for(int i=0;i<n;i++)
            {
                auto&t=blk[i];
                ll j=t.se;
                mn=max(mn,j*j-t.fi.fi);
                ll mx=j*j+j-t.fi.se;
                pq.ep(mx,i);
            }
        }
        cnt++;
        ll mx=pq.top().fi;
        int i=pq.top().se;
        pq.pop();
        if(mn<=mx&&mx>=0)
        {
            cout<<max(mn,(ll)0)<<endl;
            break;
        }
        auto&t=blk[i];
        t.se++;
        ll j=t.se;
        mn=max(mn,j*j-t.fi.fi);
        mx=j*j+j-t.fi.se;
        pq.ep(mx,i);
    }
    return 0;
}