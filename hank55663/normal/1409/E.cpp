#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;

void solve(){   
    int n,k;
    scanf("%d %d",&n,&k);
    int x[200005],y[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    for(int i= 0;i<n;i++){
        scanf("%d",&y[i]);
    }
    sort(x+1,x+n+1);
    int pre[200005];
    pre[0]=0;
    x[0]=0;
    for(int i = 1;i<=n;i++){
        int val=i-(lower_bound(x+1,x+n+1,x[i]-k)-x)+1;
        pre[i]=max(pre[i-1],val);
    //    printf("%d ",pre[i]);
    }
   // printf("\n");
    int suf[200005];
    suf[n+1]=0;
    for(int i = n;i>=1;i--){
        int val=(upper_bound(x+1,x+n+1,x[i]+k)-x)-i;
        suf[i]=max(suf[i+1],val);
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        ans=max(ans,pre[i]+suf[i+1]);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/