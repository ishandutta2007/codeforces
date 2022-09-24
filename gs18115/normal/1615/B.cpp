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
inline int get(int x,int i)
{
    int d=1<<i;
    if(x>>i&1)
    {
        int a1=(x/d/2)*d;
        int a2=x%d+1;
        return a1+a2;
    }
    else
    {
        int a1=(x/d/2)*d;
        return a1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int m=0;
        for(int i=0;i<20;i++)
            m=max(m,get(r,i)-get(l-1,i));
        cout<<(r-l+1-m)<<'\n';
    }
    return 0;
}