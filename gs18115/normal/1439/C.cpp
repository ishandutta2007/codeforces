#include<iostream>
#include<vector>
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
const int mx=200010;
struct seg
{
    ll sum[mx*4];
    int mxt[mx*4],mn[mx*4];
    int lz[mx*4];
    void init(int n,int s,int e,vector<int>&v)
    {
        lz[n]=0;
        if(s==e)
        {
            sum[n]=mxt[n]=mn[n]=v[s];
            return;
        }
        int m=s+(e-s)/2;
        init(n*2,s,m,v);
        init(n*2+1,m+1,e,v);
        sum[n]=sum[n*2]+sum[n*2+1];
        mxt[n]=mxt[n*2];
        mn[n]=mn[n*2+1];
        return;
    }
    inline void put(int n,int s,int e,int p)
    {
        sum[n]=(ll)p*(e-s+1);
        mxt[n]=mn[n]=lz[n]=p;
        return;
    }
    inline void prop(int n,int s,int e,int m)
    {
        if(lz[n]==0)
            return;
        put(n*2,s,m,lz[n]);
        put(n*2+1,m+1,e,lz[n]);
        lz[n]=0;
        return;
    }
    void upd(int n,int s,int e,int E,int p)
    {
        if(s>E||mn[n]>=p)
            return;
        if(e<=E&&mxt[n]<=p)
        {
            put(n,s,e,p);
            return;
        }
        int m=s+(e-s)/2;
        prop(n,s,e,m);
        upd(n*2,s,m,E,p);
        upd(n*2+1,m+1,e,E,p);
        sum[n]=sum[n*2]+sum[n*2+1];
        mxt[n]=mxt[n*2];
        mn[n]=mn[n*2+1];
        return;
    }
    ll sumquery(int n,int s,int e,int S,int E)
    {
        if(s>E||S>e)
            return 0;
        if(S<=s&&e<=E)
            return sum[n];
        int m=s+(e-s)/2;
        prop(n,s,e,m);
        return sumquery(n*2,s,m,S,E)+sumquery(n*2+1,m+1,e,S,E);
    }
    int query1(int n,int s,int e,int val)
    {
        if(mxt[n]<=val)
            return s;
        if(s==e)
            return s+1;
        int m=s+(e-s)/2;
        prop(n,s,e,m);
        if(mxt[n*2+1]>val)
            return query1(n*2+1,m+1,e,val);
        return query1(n*2,s,m,val);
    }
    int query2(int n,int s,int e,ll val)
    {
        if(s==e)
            return s;
        int m=s+(e-s)/2;
        prop(n,s,e,m);
        if(sum[n*2]<=val)
            return query2(n*2+1,m+1,e,val-sum[n*2]);
        return query2(n*2,s,m,val);
    }
}st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int&t:v)
        cin>>t;
    v.insert(v.begin(),0);
    st.init(1,1,n,v);
    for(int qi=0;qi<q;qi++)
    {
        int t,x;
        ll y;
        cin>>t>>x>>y;
        if(t==1)
            st.upd(1,1,n,x,y);
        else
        {
            int ans=0;
            x=max(x,st.query1(1,1,n,y));
            while(x<=n)
            {
                ll csum=x==1?0:st.sumquery(1,1,n,1,x-1);
                if(csum+y>=st.sum[1])
                {
                    ans+=n+1-x;
                    x=n+1;
                    break;
                }
                int nx=st.query2(1,1,n,csum+y);
                ans+=nx-x;
                y-=st.sumquery(1,1,n,x,nx-1);
                x=max(nx,st.query1(1,1,n,y));
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}