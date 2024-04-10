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
int n,m,k,b[100111],a[100111];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]=i;
    int x,y;
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        int pos=b[x];
        if(b[x]>1)
        {
            swap(b[x],b[a[pos-1]]);
            swap(a[pos],a[pos-1]);
        }
        ans+=(pos-1)/k+1;
    }
    printf("%I64d\n",ans);
    return 0;
}