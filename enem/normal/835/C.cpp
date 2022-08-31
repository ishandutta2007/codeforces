#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>
#define ull unsigned long long int
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define ren(i,a,b) for(ll i=b;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>
#define MOD 1000000007
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll powM(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=powM(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
namespace std {
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);}};}
////////////////////

int main()
{
    ll n,q,c;
    cin>>n>>q>>c;
    int x[n],y[n],s[n],ac[101][101][11]={0},f[101][101][11]={0};
    rep(i,0,n-1){
        cin>>x[i]>>y[i]>>s[i];
        ac[x[i]][y[i]][0]+=s[i];
        rep(j,1,10)
        {
            s[i]++;
            if(s[i]<=c) ac[x[i]][y[i]][j]+=s[i];
            else {
                s[i]=0;
            }
        }
        //cout<<ac[x[i]][y[i]][4]<<endl;
    }
    rep(i,1,100)
    {
        rep(j,1,100)
        {
            rep(k,0,10)
            {
                f[i][j][k]+=ac[i][j][k]+f[i][j-1][k]+f[i-1][j][k]-f[i-1][j-1][k];
            }
        }
    }
    //cout<<f[5][5][3]<<endl;
    while(q--)
    {
        ll t,x1,y1,x2,y2,sum=0;
        cin>>t>>x1>>y1>>x2>>y2;
        t=t%(c+1);
        cout<<f[x2][y2][t]-f[x1-1][y2][t]-f[x2][y1-1][t]+f[x1-1][y1-1][t]<<endl;
    }
    return 0;
}