#include<bits/stdc++.h>
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
static const double INF = 2147483647;
void solve(){
    int n,c;
    scanf("%d %d",&n,&c);
    int a[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    int b[200005];
    for(int i = 0;i<n-1;i++)scanf("%d",&b[i]);
    LL tot=0,num=0;
    LL ans=1e9;
    for(int i = 0;i<n;i++){
        ans=min(ans,(c-num+a[i]-1)/a[i]+tot);
      //  printf("%d %d\n",tot,num);
        LL need=(b[i]-num+a[i]-1)/a[i];
        tot+=need+1;
        num+=need*a[i];
        num-=b[i];
        
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/