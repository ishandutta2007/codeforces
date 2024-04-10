//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,k,a[10];
double ans,tt;
void dfs(int x,int *p)
{
    if(x==k+1)
    {
        int tmp=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(p[i]>p[j])tmp++;
            }
        }
        ans+=1.0*tmp;
        return;
    }
    int p2[10]={};
    for(int i=1;i<=n;i++)p2[i]=p[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<=j;k++)p2[k]=p[j-k+i];
            dfs(x+1,p2);
            for(int k=i;k<=j;k++)p2[k]=p[k];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    tt=n*(n+1)/2;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,a);
    for(int i=1;i<=k;i++)ans/=tt;
    cout<<setprecision(12)<<ans<<endl;
    return 0;
}