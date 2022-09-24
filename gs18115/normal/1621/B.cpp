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
        cin>>n;
        pi mn(inf,0);
        pi mx(-inf,0);
        int ans=inf*2,ans2=inf*2;
        for(int i=0;i<n;i++)
        {
            int l,r,x;
            cin>>l>>r>>x;
            pi as(l,x);
            pi df(r,-x);
            if(l<mn.fi||r>mx.fi)
                ans2=inf*2;
            mn=min(mn,as);
            mx=max(mx,df);
            if(l==mn.fi&&r==mx.fi)
                ans2=min(ans2,x),ans=min(x,mn.se-mx.se);
            else
                ans=mn.se-mx.se;
            cout<<min(ans,ans2)<<'\n';
        }
    }
    return 0;
}