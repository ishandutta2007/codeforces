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
int n,k,i;
string s,t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    cin>>s;
    t=s;
    for(i=0;i<k;i++)
        t[i]=s[i];
    for(i=k;i<n;i++)
        t[i]=t[i-k];
    for(i=0;i<n;i++)
    {
        if(t[i]>s[i])
            break;
        if(t[i]<s[i])
            i=n+1;
    }
    if(i==n+2)
        t[k-1]++;
    for(i=k;--i>0;)
        if(t[i]>'9')
            t[i-1]++,t[i]-=10;
    for(i=k;i<n;i++)
        t[i]=t[i-k];
    cout<<n<<endl;
    cout<<t<<endl;
    return 0;
}