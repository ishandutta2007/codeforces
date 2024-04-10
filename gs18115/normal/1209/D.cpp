#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
int pa[200010];
int par(int x)
{
    if(pa[x]==-1)
        return x;
    return pa[x]=par(pa[x]);
}
bool chk[200010];
int n,k,i;
int C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    fill(pa,pa+n,-1);
    for(i=0;i<k;i++)
    {
        int s,e;
        cin>>s>>e;
        s=par(s-1);
        e=par(e-1);
        if(s!=e)
            pa[s]=e,C++;
    }
    cout<<k-C<<endl;
    return 0;
}