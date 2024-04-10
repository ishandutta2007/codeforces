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
int n,l[6],r[6],a[6];
double t[6],ans;
void dfs(int x,int p,double prob,int cnt0,int cnt1,int cnt2)
{
    if(prob==0)return;
    if(cnt2>1)return;
    if(p==n+1)
    {
        if(cnt2==1&&cnt1>0||cnt2==0&&cnt1>1)ans+=1.0*prob*x;
    }
    dfs(x,p+1,prob*max(0,min(r[p],x-1)-l[p]+1)/(r[p]-l[p]+1),cnt0+1,cnt1,cnt2);
    dfs(x,p+1,prob*max(0,min(r[p],x)-max(l[p],x)+1)/(r[p]-l[p]+1),cnt0,cnt1+1,cnt2);
    dfs(x,p+1,prob*max(0,r[p]-max(l[p]-1,x))/(r[p]-l[p]+1),cnt0,cnt1,cnt2+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
    for(int i=1;i<=10000;i++)dfs(i,1,1,0,0,0);
    cout<<setprecision(10)<<ans<<endl;  
    return 0;
}