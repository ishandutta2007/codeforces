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
    int t=1;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        n*=2;
        string s;
        cin>>s;
        vector<int>ps(n*2+1,0);
        int p=0;
        int ans=0;
        for(int i=0;i++<n;)
        {
            int d=(s[i-1]=='('?1:-1);
            if(d==1)
            {
                if(ps[p]==0)
                    ans++,ps[p]=1;
                p++;
            }
            else
            {
                ps[p]=0;
                p--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}