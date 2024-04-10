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
#define PI 3.141592653589793238462643383279502
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
int n,m;
char s[51][51];
int vis[51][51]={};
void dfs(int x,int y)
{
    if(vis[x][y]==1) return;
    vis[x][y]=1;
    if(y+1<=m-1 && s[x][y+1]!='#') dfs(x,y+1);
    if(x+1<=n-1 && s[x+1][y]!='#') dfs(x+1,y);
    if(y-1>=0 && s[x][y-1]!='#') dfs(x,y-1);
    if(x-1>=0 && s[x-1][y]!='#') dfs(x-1,y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        rep(i,0,n-1)
        {
            rep(j,0,m-1)
            {
                cin>>s[i][j];
            }
        }
        int flag=1;
        rep(i,0,n-1)
        {
            rep(j,0,m-1)
            {
                if(s[i][j]=='B')
                {
                    if(i>0)
                    {
                        if(s[i-1][j]=='G') flag=0;
                        if(s[i-1][j]=='.') s[i-1][j]='#';
                    }
                    if(j>0)
                    {
                        if(s[i][j-1]=='G') flag=0;
                        if(s[i][j-1]=='.') s[i][j-1]='#';
                    }
                    if(i<n-1)
                    {
                        if(s[i+1][j]=='G') flag=0;
                        if(s[i+1][j]=='.') s[i+1][j]='#';
                    }
                    if(j<m-1)
                    {
                        if(s[i][j+1]=='G') flag=0;
                        if(s[i][j+1]=='.') s[i][j+1]='#';
                    }
                }
            }
        }
        rep(i,0,50)
        {
            rep(j,0,50)
            {
                vis[i][j]=0;
            }
        }
        if(s[n-1][m-1]=='.') dfs(n-1,m-1);
        rep(i,0,n-1)
        {
            rep(j,0,m-1)
            {
                if(s[i][j]=='G'&&vis[i][j]==0)flag=0;
            }
        }
        if(flag==0) cout<<"No"<<'\n';
        else cout<<"Yes"<<'\n';
    }
    return 0;
}