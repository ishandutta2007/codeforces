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
const int mx=500010;
struct seg
{
    ll sum[mx*4];
    int mxt[mx*4];
    int lza[mx*4],lzb[mx*4];
    void init(int n,int s,int e)
    {
        sum[n]=0;
        mxt[n]=0;
        lza[n]=1,lzb[n]=0;
        if(s==e)
            return;
        int m=s+(e-s)/2;
        init(n*2,s,m);
        init(n*2+1,m+1,e);
        return;
    }
    inline void put(int n,int s,int e,int a,int b)
    {
        sum[n]=sum[n]*a+(ll)b*(e-s+1);
        mxt[n]=mxt[n]*a+b;
        lza[n]*=a;
        lzb[n]=lzb[n]*a+b;
        return;
    }
    inline void prop(int n,int s,int e,int m)
    {
        if(lza[n]==1&&lzb[n]==0)
            return;
        put(n*2,s,m,lza[n],lzb[n]);
        put(n*2+1,m+1,e,lza[n],lzb[n]);
        lza[n]=1,lzb[n]=0;
        return;
    }
    inline void merge(int n)
    {
        sum[n]=sum[n*2]+sum[n*2+1];
        mxt[n]=max(mxt[n*2],mxt[n*2+1]);
        return;
    }
    void upd(int n,int s,int e,int S,int E,int a,int b)
    {
        if(s>E||S>e)
            return;
        if(S<=s&&e<=E)
            return put(n,s,e,a,b);
        int m=s+(e-s)/2;
        prop(n,s,e,m);
        upd(n*2,s,m,S,E,a,b);
        upd(n*2+1,m+1,e,S,E,a,b);
        merge(n);
        return;
    }
    int search(int n,int s,int e,int k)
    {
        if(s==e)
            return mxt[n]<k?s:s+1;
        int m=s+(e-s)/2;
        prop(n,s,e,m);
        if(mxt[n*2+1]<k)
            return search(n*2,s,m,k);
        return search(n*2+1,m+1,e,k);
    }
}st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int co=0;
    ll ans=0;
    st.init(1,1,n);
    for(int i=0;i++<n;)
    {
        auto cur=s[i-1];
        if(cur=='1')
        {
            co++;
            int pos=st.search(1,1,n,co);
            if(pos<=i-co)
                st.upd(1,1,n,pos,i-co,0,co);
            st.upd(1,1,n,i-co+1,i,1,1);
        }
        else
            co=0;
        ans+=st.sum[1];
    }
    cout<<ans<<endl;
    return 0;
}