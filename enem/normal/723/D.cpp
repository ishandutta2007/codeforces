#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
////////////////////
    int n,m,k;
    string s[51];
int vis[51][51]={};
int fl=1,cnt=0;
vector<set<pair<int,int>>> v;
vector<int> del;
set<pair<int,int>> temp;
void dfs(int i,int j)
{
    vis[i][j]=1;
    if(i==0||i==n-1||j==0||j==m-1)
    {
        fl=0;
    }
    temp.insert({i,j});
    if(i-1>=0 && vis[i-1][j]==0 && s[i-1][j]=='.') dfs(i-1,j);
    if(j-1>=0 &&vis[i][j-1]==0 && s[i][j-1]=='.') dfs(i,j-1);
    if(i+1<=n-1 &&vis[i+1][j]==0 && s[i+1][j]=='.') dfs(i+1,j);
    if(j+1<=m-1 &&vis[i][j+1]==0 && s[i][j+1]=='.') dfs(i,j+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*int t;
    cin>>t;
    while(t--)*/
    cin>>n>>m>>k;
    rep(i,0,n-1) cin>>s[i];
    rep(i,1,n-2)
    {
        rep(j,1,m-2)
        {
            fl=1;
            if(s[i][j]=='.'&&vis[i][j]==0)
            {
                dfs(i,j);
                if(fl==1)
                {
                    v.PB(temp);
                    del.PB((int)temp.size());
                }
                temp.clear();
            }
        }
    }
    sort(del.begin(),del.end());
    multiset<int> rem;
    int r=(int)del.size()-k;
    int j=0;
    while(r--)
    {
        rem.insert(del[j]);
        j++;
    }
    rep(i,0,(int)v.size()-1)
    {
        if(rem.count((int)v[i].size()))
        {
            for(auto u:v[i])
            {
                s[u.F][u.S]='*';
                cnt++;
            }
            rem.erase(rem.find((int)v[i].size()));
        }
        if(rem.empty()) break;
    }
    cout<<cnt<<'\n';
    rep(i,0,n-1) cout<<s[i]<<'\n';
    return 0;
}