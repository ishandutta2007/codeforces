#include<iostream>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,m,k;
        cin>>n>>m>>k;
        k=min(k,m-1);
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        vector<int>v2(m);
        int ans=-inf;
        for(int i=0;i<m;i++)
            v2[i]=max(v[i],v[n-m+i]);
        for(int i=0;i<=k;i++)
        {
            int a2=inf;
            for(int j=i;j<i+m-k;j++)
                a2=min(a2,v2[j]);
            ans=max(ans,a2);
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    return 0;
}