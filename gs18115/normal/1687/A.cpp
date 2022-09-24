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
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        if(k>=n)
        {
            ll s=0;
            for(int&t:v)
                s+=t;
            cout<<s+(ll)k*n-(ll)n*(n+1)/2;
        }
        else
        {
            ll m=0;
            ll s=0;
            for(int i=0;i<k;i++)
                s+=v[i];
            m=s;
            for(int i=k;i<n;i++)
            {
                s+=v[i]-v[i-k];
                m=max(m,s);
            }
            cout<<m+(ll)k*(k-1)/2;
        }
        cout<<'\n';
    }
    return 0;
}