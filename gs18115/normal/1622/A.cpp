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
        vector<int>v(3);
        for(int&t:v)
            cin>>t;
        sort(all(v));
        bool f=0;
        if(v[2]==v[0]+v[1])
            f=1;
        if(v[0]==v[1]&&v[2]%2==0)
            f=1;
        if(v[1]==v[2]&&v[0]%2==0)
            f=1;
        cout<<(f?"YES":"NO")<<endl;
    }
    return 0;
}