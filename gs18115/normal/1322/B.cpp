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
    vector<int>v(n);
    for(int&t:v)
        cin>>t;
    int ans=0;
    for(int i=0;i<29;i++)
    {
        int x=1<<i;
        vector<int>v1,v2;
        for(int&t:v)
            (t>>i&1?v2:v1).eb(t);
        v.clear();
        for(int&t:v1)
            v.eb(t);
        for(int&t:v2)
            v.eb(t);
        v1.clear();
        for(int&t:v)
            v1.eb(t%(x*2));
        ll p=0;
        int j=n,k=n,l=n;
        for(int y=0;y<n;y++)
        {
            while(j>0&&v1[y]+v1[j-1]>=x)
                j--;
            while(k>0&&v1[y]+v1[k-1]>=x*2)
                k--;
            while(l>0&&v1[y]+v1[l-1]>=x*3)
                l--;
            p+=n-l+k-j;
            if(v1[y]+v1[y]>>i&1)
                p--;
        }
        if(p/2%2==1)
            ans+=1<<i;
    }
    cout<<ans<<endl;
    return 0;
}