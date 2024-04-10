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
    while(t--)
    {
        int n;
        ll k;
        cin>>n>>k;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        sort(all(v),greater<int>());
        ll ans=INF;
        int m=v.back();
        ll as=0,cs=0;
        for(int&t:v)
            as+=t;
        for(int i=0;i<n;i++)
        {
            //cs -> i*m
            ll d=i+1;
            ans=min(ans,max(0ll,(as-(cs-(ll)i*m)-k+d-1)/d)+i);
            cs+=v[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}