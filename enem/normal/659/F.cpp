#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef long long ll;
typedef long double ld;
#define INF LLONG_MAX
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define g(a,b) get<a>(b)
#define REP(i,a,b) for(ll i = a; i<=b; i++)
#define REPI(i, a, n)  for(ll i = a; i >= (n); --i)
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define endl "\n"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ordered_set member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set*/
 
// DISJOINT SET UNION START
ll fn(ll x,ll rn[]) // finding the component
{
    if(x==rn[x]) // Top of its component
        return x;
    else //making parent node of each node of the component the highest node
        return rn[x]=fn(rn[x],rn);
}
bool un(ll x,ll y,ll rn[],ll sz[])// union of components
{
    x=fn(x,rn);
    y=fn(y,rn);
    if(x==y)// if connected already
        return false;
    if(sz[x]<sz[y])// otherwise connectiing light to heavy by swapping
        swap(x,y);
    sz[x]+=sz[y];
    rn[y]=x;// making parent node;
    return true;
}
//DISJOINT SET UNION END
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
ll MOD=998244353;
ll mod=1000000007;
ll power(ll x,ll y, ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll inv(ll val, ll MODx = MOD) 
{
    return power(val, MODx - 2, MODx);
}
vector <ll> fac, ifac;
void preFac(ll sz) 
{
    fac.resize(sz + 1),
    ifac.resize(sz + 1);
    fac[0] = 1;
    for(int i = 1; i <= sz; i++) 
    {
        fac[i] = (i * fac[i - 1]) % MOD;
    }
    ifac[sz] = inv(fac[sz]);
    for(int i=sz-1;i>=0;i--) 
    {
        ifac[i]=((i+1)*ifac[i+1])%MOD;
    }
}
ll nCr(ll N, ll R)
{
    if(R <= N  and  R >= 0) {
        return ((fac[N] * ifac[R]) % MOD * ifac[N - R]) % MOD;
    }
    return 0;
}
ll vis[1005][1005]={};
ll a[1005][1005];
ll zz=0;
void dfs(ll x,ll y,ll n,ll m,ll val)
{
    if(vis[x][y] || zz==0) return;
    vis[x][y]=1;
    a[x][y]=-1;
    zz--;
    if(x-1>=0 and a[x-1][y]==val)
    {
        dfs(x-1,y,n,m,val);
    }
    if(x+1<n and a[x+1][y]==val)
    {
        dfs(x+1,y,n,m,val);
    }
    if(y-1>=0 and a[x][y-1]==val)
    {
        dfs(x,y-1,n,m,val);
    }
    if(y+1<m and a[x][y+1]==val)
    {
        dfs(x,y+1,n,m,val);
    }
}
int main() 
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    ll n,m,k;
    cin>>n>>m>>k;
    map<ll,vector<pair<ll,ll>>> ux;
    REP(i,0,n-1)
    {
        REP(j,0,m-1)
        {
            cin>>a[i][j];
            ux[a[i][j]].PB({i,j});
        }
    }
    ll rn[n*m],sz[n*m];
    REP(i,0,n*m-1)
    {
        rn[i]=i;
        sz[i]=1;
    }
    vector<ll> vec;
    for(auto u:ux)
    {
        vec.PB((u.F));
    }
    reverse(vec.begin(),vec.end());
    ll ans=0,comp=0;
    ll flg=0;
    REP(zz,0,((ll)vec.size())-1) 
    {   
        for(auto u:ux[vec[zz]])
        {
            ll i=u.F,j=u.S;
            if(i+1<n && a[i+1][j]>=vec[zz])
            {
                un(i*m+j,(i+1)*m+j,rn,sz);
            }    
            if(i-1>= 0 && a[i-1][j]>=vec[zz])
            {
                un(i*m+j,(i-1)*m+j,rn,sz);
            }
            if(j+1<m && a[i][j+1]>=vec[zz])
            {
                un(i*m+j,(i)*m+j+1,rn,sz);
            }
            if(j-1>=0 && a[i][j-1]>=vec[zz])
            {
                un(i*m+j,(i)*m+j-1,rn,sz);
            }
        }
        if(k%vec[zz]==0)
        {
            ll comp_consider=0,size_of_component=0;
            for(auto u:ux[vec[zz]])
            {
                if(size_of_component<sz[fn(u.F*(m)+u.S,rn)])
                {
                    size_of_component=sz[fn(u.F*(m)+u.S,rn)];
                    comp_consider=u.F*(m)+u.S;
                }
            }
            if(size_of_component>=k/vec[zz])
            {
                ans=vec[zz];
                comp=comp_consider;
                flg=1;
                break;
            }
        }
    }
    if(flg==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    ll cnt=k/ans;
    ll x=comp/m,y=comp%m;
    REP(i,0,n-1)
    {
        REP(j,0,m-1)
        {
            if(fn(i*m+j,rn)==fn(comp,rn))
            {
                a[i][j]=ans;
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
    zz=cnt;
    dfs(x,y,n,m,ans);
    REP(i,0,n-1)
    {
        REP(j,0,m-1)
        {
            if(a[i][j]!=-1)
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=ans;
            }
        }
    }
    REP(i,0,n-1)
    {
        REP(j,0,m-1)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    
}
//try thinking from a different angle after spending some time
//PLEASE CHECK EDGE CASES!!!