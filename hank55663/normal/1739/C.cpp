
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL C[60][60];
const int mod=998244353;
void solve(int T){
    
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        C[i][0]=C[i][i]=1;
        for(int j = 1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    LL ans1=0,ans2=0;
  //  printf("%d\n",C[2][1]);
    for(int i = 2;i<n;i+=2){
        ans1+=C[n-i][n/2-(i/2)-1];
        ans2+=C[n-i][n/2-(i/2)-1];
        
        // printf("%lld %lld %d\n",ans1%mod,ans2%mod,1);
        if(i%4==2)ans1+=C[n-i][n/2-(i/2)];
        else ans2+=C[n-i][n/2-(i/2)];
      //   printf("%lld %lld %d \n",ans1%mod,ans2%mod,1);
    }
    if(n%4==2)ans1++;
    else ans2++;
    printf("%lld %lld %d\n",ans1%mod,ans2%mod,1);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/