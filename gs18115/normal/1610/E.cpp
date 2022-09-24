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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int j=i;
            while(j<n&&v[i]==v[j])
                j++;
            int d=j-i;
            j--;
            i=j;
            int f=v[i],pr=v[i];
            while(j!=n)
            {
                int nx=pr*2-f;
                int k=lower_bound(j+1+all(v),nx)-v.begin();
                if(k==n)
                    break;
                j=k;
                pr=v[j];
                d++;
            }
            ans=max(ans,d);
        }
        cout<<n-ans<<'\n';
    }
    return 0;
}