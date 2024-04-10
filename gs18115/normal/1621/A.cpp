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
        int n,k;
        cin>>n>>k;
        if(2*k-1>n)
        {
            cout<<-1<<'\n';
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j&&i%2==0)
                {
                    if(k>0)
                        k--,cout<<'R';
                    else
                        cout<<'.';
                }
                else
                    cout<<'.';
            }
            cout<<'\n';
        }
    }
    return 0;
}