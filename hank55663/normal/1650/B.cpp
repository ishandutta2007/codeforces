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
const int mod=1e9+7;
#define MXN 2005
void solve(){
    int l,r,a;
    scanf("%d %d %d",&l,&r,&a);
    if(r%a==a-1){
        printf("%lld\n",r/a+a-1ll);
    }
    else{
        int x=(r/a-1)*a+a-1;
      //  printf("%d\n",x);
        if(x>=l){
            printf("%d\n",x/a+a-1);
        }
        else{
            printf("%lld\n",r/a+r%a+0ll);
        }
    }
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