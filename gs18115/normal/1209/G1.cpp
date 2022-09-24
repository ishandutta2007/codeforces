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
int c[200010];
int par(int x)
{
    if(pa[x]==-1)
        return x;
    return pa[x]=par(pa[x]);
}
inline void uni(int x,int y)
{
    x=par(x);
    y=par(y);
    if(x==y)
        return;
    pa[x]=y;
    c[y]=max(c[x],c[y]);
    return;
}
int n,i,t,q;
int ans;
int e[200010],a[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    fill(pa,pa+200010,-1);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        e[a[i]]=i;
        c[a[i]]++;
    }
    for(i=0;i<n;i++)
    {
        if(i<e[t])
            uni(a[i],t);
        if(e[a[i]]>e[t])
            t=a[i];
    }
    ans=n;
    for(i=0;i<200010;i++)
        if(pa[i]==-1)
            ans-=c[i];
    cout<<ans<<endl;
    return 0;
}