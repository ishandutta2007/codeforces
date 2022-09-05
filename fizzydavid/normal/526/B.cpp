//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int t,n;
int mx[3050],sum[3050],a[3050],ans,mxx;
void dfs(int i)
{
    sum[i]=sum[i/2]+a[i];
    if(i*2<n)dfs(i*2),dfs(i*2+1);
    mx[i/2]=max(mx[i/2],mx[i]+a[i]);
    mxx=max(mxx,mx[i/2]);
}
void dfs2(int i)
{
    sum[i]=sum[i/2]+a[i];
    if(i!=1)
    {
        ans+=mxx-(sum[i]+mx[i]);
        sum[i]+=mxx-(sum[i]+mx[i]);
    }
    if(i*2<n)dfs2(i*2),dfs2(i*2+1);
}
int main()
{
    cin>>t;
    n=1;
    for(int i=1;i<=t+1;i++)n=n*2;
    for(int i=2;i<n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    dfs2(1);
    cout<<ans<<endl;
    return 0;
}