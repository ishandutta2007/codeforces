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
inline int ispal(vector<int>v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
        if(v[i]!=v[n-1-i])
            return i;
    return-1;
}
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
        bool f=1;
        int i=ispal(v);
        if(i!=-1)
        {
            vector<int>v2,v3;
            for(int&t:v)
            {
                if(t!=v[i])
                    v2.eb(t);
                if(t!=v[n-1-i])
                    v3.eb(t);
            }
            f=ispal(v2)==-1||ispal(v3)==-1;
        }
        cout<<(f?"YES":"NO")<<'\n';
    }
    return 0;
}