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
int n;
pair<int,int>a[100111];
int cnt[100111],cnt2[201],pre[100111];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].FF),cnt[a[i].FF]++;
    for(int i=1;i<=n;i++)scanf("%d",&a[i].SS),cnt2[a[i].SS]++;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i].SS;
    int ans=INF;
    for(int i=n;i>=1;i-=cnt[a[i].FF])
    {
        for(int j=i;j>i-cnt[a[i].FF];j--)cnt2[a[j].SS]--;
        int t=max(0,i-cnt[a[i].FF]*2+1),tsum=0;
        for(int j=1;j<=200&&t>0;j++)
        {
            tsum+=j*min(t,cnt2[j]);
            t-=cnt2[j];
        }
        ans=min(ans,pre[n]-pre[i]+tsum);
    }
    printf("%d\n",ans);
    return 0;
}