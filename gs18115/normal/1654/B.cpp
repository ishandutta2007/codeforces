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
        string s;
        cin>>s;
        vector<bool>chk(26);
        int n=s.size();
        int mi=inf;
        for(int i=n;i-->0;)
        {
            int c=s[i]-'a';
            if(!chk[c])
                chk[c]=1,mi=i;
        }
        for(int i=mi;i<n;i++)
            cout<<s[i];
        cout<<'\n';
    }
    return 0;
}