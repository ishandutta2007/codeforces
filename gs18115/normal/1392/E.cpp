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
ll dp[30][30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    dp[1][1]=dp[n][n]=0;
    for(int i=1;i<n*2-1;i++)
        for(int j=max(0,i-(n-1));j<=i&&j<n;j++)
            dp[i-j+1][j+1]=j*(1ll<<(i-1));
    for(int i=0;i++<n;cout<<'\n')
        for(int j=0;j++<n;)
            cout<<dp[i][j]<<' ';
    cout.flush();
    int q;
    cin>>q;
    while(q-->0)
    {
        ll k;
        cin>>k;
        int ci=0,cj=0;
        cout<<1<<' '<<1<<'\n';
        for(int i=0;i<n*2-2;i++)
        {
            k-=cj;
            if(k&1)
                cj++;
            else
                ci++;
            k/=2;
            cout<<ci+1<<' '<<cj+1<<'\n';
        }
        cout.flush();
    }
    return 0;
}