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
    if(n%3==0){
        for(int j = 0;j<n;j+=3){
            printf("21");
        }
        printf("\n");
    }
    else if(n%3==1){
         for(int j = 1;j<n;j+=3){
            printf("12");
        }
        printf("1\n");
    }
    else{
        for(int j = 2;j<n;j+=3){
            printf("21");
        }
        printf("2\n");
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