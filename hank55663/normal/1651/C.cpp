#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 2005
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005],b[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    LL res=1e18;
    for(int i = 0;i<2;i++){
        LL Min=1e9,Min2=1e9;
        for(int i = 0;i<n;i++){
            Min=min(Min,abs(a[0]-b[i])*1ll);
            Min2=min(Min2,abs(b[0]-a[i])*1ll);
        }
        LL ans=min(Min+Min2,abs(a[0]-b[0])*1ll);
        Min=1e9,Min2=1e9;;
        for(int i = 0;i<n;i++){
            Min=min(Min,abs(a[n-1]-b[i])*1ll);
            Min2=min(Min2,abs(b[n-1]-a[i])*1ll);
        }
        ans+=min(Min+Min2,abs(a[n-1]-b[n-1]*1ll));
        res=min(res,ans);
        reverse(a,a+n);
    }
    printf("%lld\n",res);
}
int main(){
    int t=1;0000;
      scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
342475
784728
394591
622354
489948
37187.5
586271
70934.1
463806
235009
528719
786392
717050
936731
250005
382783
953168
610086
*/