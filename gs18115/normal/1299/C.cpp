#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
typedef long double ld;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll>v(n);
    for(ll&t:v)
        cin>>t;
    vector<int>nxt(n),sz(n);
    vector<ld>val(n);
    for(int i=0;i<n;i++)
        nxt[i]=i+1,sz[i]=1,val[i]=v[i];
    for(int i=n;i-->0;)
    {
        int j=i+1;
        while(j<n&&val[j]<val[i])
        {
            val[i]=(val[i]*sz[i]+val[j]*sz[j])/(sz[i]+sz[j]);
            sz[i]+=sz[j];
            nxt[i]=nxt[j];
            j=nxt[j];
        }
    }
    cout<<fixed<<setprecision(12);
    for(int i=0;i<n;i=nxt[i])
        for(int j=i;j<nxt[i];j++)
            cout<<val[i]<<'\n';
    cout.flush();
    return 0;
}