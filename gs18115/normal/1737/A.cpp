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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>cnt(26,0);
        for(auto&t:s)
            cnt[t-'a']++;
        for(int i=0;i<k;i++)
        {
            int mx=0;
            for(int j=0;j<n/k;j++)
            {
                if(cnt[j]>0)
                    mx=j+1,cnt[j]--;
                else
                    break;
            }
            cout<<(char)(mx+'a');
        }
        cout<<'\n';
    }
    return 0;
}