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
        string s;
        cin>>s;
        int l=n-1;
        for(int i=0;i<n-1;i++)
        {
            if((i==0&&s[i]==s[i+1])||(char)s[i]<s[i+1])
            {
                l=i;
                break;
            }
        }
        for(int i=0;i<=l;i++)
            cout<<s[i];
        for(int i=l;i>=0;i--)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}