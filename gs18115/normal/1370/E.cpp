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
const ll INF=1e18+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int cnt=0;
    int mx=-inf,mn=inf;
    for(int i=0;i<n;i++)
        cnt+=(s[i]=='0'?1:-1)+(t[i]=='0'?-1:1),mx=max(mx,cnt/2),mn=min(mn,cnt/2);
    mx-=mn;
    if(cnt!=0)
        mx=-1;
    cout<<mx<<endl;
    return 0;
}