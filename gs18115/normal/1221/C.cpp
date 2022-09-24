#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        ll c,m,x;
        cin>>c>>m>>x;
        ll ans=min({c,m,x});
        c-=ans;
        m-=ans;
        x-=ans;
        if(c==0||m==0)
            ans+=0;
        else if(c>m*2)
            ans+=m;
        else if(m>c*2)
            ans+=c;
        else
            ans+=(m+c)/3;
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}