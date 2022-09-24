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
const int mx=1000000;
struct seg
{
    ll t[mx/3*4];
    void init(int n,int s,int e)
    {
        t[n]=-INF;
        if(s==e)
            return;
        int m=s+(e-s)/2;
        init(n*2,s,m);
        init(n*2+1,m+1,e);
        return;
    }
    void upd(int n,int s,int e,int x,ll p)
    {
        if(s==e)
        {
            t[n]=p;
            return;
        }
        int m=s+(e-s)/2;
        if(x>m)
            upd(n*2+1,m+1,e,x,p);
        else
            upd(n*2,s,m,x,p);
        t[n]=max(t[n*2],t[n*2+1]);
        return;
    }
    ll query(int n,int s,int e,int S,int E)
    {
        if(s>E||S>e)
            return-INF;
        if(S<=s&&e<=E)
            return t[n];
        int m=s+(e-s)/2;
        return max(query(n*2,s,m,S,E),query(n*2+1,m+1,e,S,E));
    }
}st;
ll curmx[mx/3+10];
vector<ll>fc;
inline ll calc(int x)
{
    int i=0;
    ll ret=0;
    while(x>0)
    {
        int d=x%10;
        x/=10;
        if(d%3==0)
            ret+=d/3*fc[i];
        i++;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin>>k;
    k--;
    vector<int>f(6);
    for(int&t:f)
        cin>>t,fc.eb(t);
    curmx[0]=0;
    for(int mul=mx*3/10;mul>0;mul/=10)
    {
        ll cf=f.back();f.pop_back();
        const int cmx=mx/mul;
        st.init(1,0,cmx);
        for(int i=0;i<=cmx/10;i++)
            st.upd(1,0,cmx,i*10,curmx[i]-cf*(i*10));
        for(int i=0;i<=cmx;i++)
            curmx[i]=st.query(1,0,cmx,max(0,i-3*k),i)+i*cf;
    }
    int tn;
    cin>>tn;
    for(int ti=0;ti<tn;ti++)
    {
        int n;
        cin>>n;
        ll ans=0;
        for(int i=0;i<=n/3;i++)
            ans=max(ans,curmx[i]+calc(n-3*i));
        cout<<ans<<'\n';
    }
    return 0;
}