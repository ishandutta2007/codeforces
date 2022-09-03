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
LL pre[200005];
void solve(){
    int n;
    scanf("%d",&n);
    LL a[200005];
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    LL ans=-1e18;
    for(int i = 1;i<n;i++){
        LL t=-a[i];
        LL sum=a[1]*a[n]+a[1]*t+a[n]*t+(pre[n-1]-pre[i])*a[1]+(pre[n-1]-pre[i])*t+(n-1-i)*t*a[1]+
                                       (pre[i]-pre[1])*a[n]+(pre[i]-pre[1])*t+(i-1)*t*a[n];;
        ans=max(ans,sum);
        t=-a[i+1];
      sum=a[1]*a[n]+a[1]*t+a[n]*t+(pre[n-1]-pre[i])*a[1]+(pre[n-1]-pre[i])*t+(n-1-i)*t*a[1]+
                                       (pre[i]-pre[1])*a[n]+(pre[i]-pre[1])*t+(i-1)*t*a[n];;
        ans=max(ans,sum);
    //    printf("%lld\n",sum);
    }
    if(a[n]*(n-1)+pre[n-1]<0){
        printf("INF\n");
    }
    else if(a[1]*(n-1)+pre[n]-pre[1]>0){
        printf("INF\n");
    }
    else{
        printf("%lld\n",ans);
    }
}


int main(){
    int t=10000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/