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
const ll INF=1e18+7;
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
        vector<int>pos(n+1);
        for(int i=0;i<n;i++)
            pos[v[i]]=i;
        int c=n;
        bool f=0;
        vector<bool>chk(n+1,0);
        chk[c]=1;
        for(int i=0;i++<n;)
        {
            if(!chk[c]&&pos[i]!=c)
                f=1;
            chk[pos[i]]=1;
            c=pos[i]+1;
        }
        cout<<(!f?"Yes\n":"No\n");
    }
    cout.flush();
    return 0;
}