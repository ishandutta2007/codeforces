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
bool chk[200010];
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
            cin>>t,t=(t%n+n)%n;
        bool f=1;
        for(int i=0;i<n;i++)
            chk[i]=0;
        for(int i=0;i<n;chk[(i+v[i])%n]=1,i++)
            if(chk[(i+v[i])%n])
                f=0;
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    cout.flush();
    return 0;
}