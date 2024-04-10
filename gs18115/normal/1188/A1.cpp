#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL V,i,s,e;
vector<LL>adj[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>V;
    for(i=1;i<V;i++)
    {
        cin>>s>>e;
        adj[--s].eb(--e);
        adj[e].eb(s);
    }
    for(i=0;i<V;i++)
        if(adj[i].size()==2)
            return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    return 0;
}