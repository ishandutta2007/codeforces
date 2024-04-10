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
#define MXN 200005
int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    if(n%2==1){
        printf("0\n");
    }
    else{
        LL ans=1;
        for(int i = 1;i<=n/2;i++)ans=ans*i%mod;
        printf("%lld\n",ans*ans%mod);
    }
}  
 
 
int main(){
    int t=1;0000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
 
*/