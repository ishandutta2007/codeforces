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
        ll c=0;
        ll m=INF;
        for(int i=0;i<2*n;i++)
        {
            for(int j=0;j<2*n;j++)
            {
                ll x;
                cin>>x;
                if(i/n==j/n)
                    c+=x;
                else if((i%n==0||i%n==n-1)&&(j%n==0||j%n==n-1))
                    m=min(m,x);
            }
        }
        cout<<m+c<<'\n';
    }
    return 0;
}