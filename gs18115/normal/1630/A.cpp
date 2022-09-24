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
        if(k==n-1)
        {
            if(n==4)
                cout<<-1<<'\n';
            else
            {
                int c1=k/2;
                int c2=k/2+1;
                int m=n-1;
                cout<<0<<' '<<1<<'\n';
                cout<<c1<<' '<<n-1<<'\n';
                cout<<c2<<' '<<n-2<<'\n';
                for(int i=0;i<n;i++)
                {
                    if(i==0||i==1||i==k/2||i==k/2+1||i==n-1||i==n-2)
                        continue;
                    if(i<(m^i))
                        cout<<i<<' '<<(m^i)<<'\n';
                }
            }
        }
        else if(k==0)
        {
            int m=n-1;
            for(int i=0;i<n;i++)
                if(i<(m^i))
                    cout<<i<<' '<<(m^i)<<'\n';
        }
        else
        {
            int m=n-1;
            cout<<0<<' '<<(m^k)<<'\n';
            cout<<k<<' '<<m<<'\n';
            for(int i=0;i<n;i++)
            {
                if(i==0||i==k||i==(m^k)||i==m)
                    continue;
                if(i<(m^i))
                    cout<<i<<' '<<(m^i)<<'\n';
            }
        }
    }
    return 0;
}