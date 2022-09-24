#include<iostream>
#include<vector>
#include<set>
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
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int m=1;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int c=0;
                for(int k=i;k<n;k++)
                {
                    if((ll)(v[k]-v[i])*(j-i)==(ll)(v[j]-v[i])*(k-i))
                        c++;
                }
                m=max(m,c);
            }
        cout<<n-m<<'\n';
    }
    return 0;
}