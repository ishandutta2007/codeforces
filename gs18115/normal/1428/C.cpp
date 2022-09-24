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
        int ac=0,bc=0;
        for(auto&t:s)
        {
            if(t=='A')
                ac++;
            else if(ac>0)
                ac--;
            else
                bc^=1;
        }
        cout<<(ac+bc)<<'\n';
    }
    return 0;
}