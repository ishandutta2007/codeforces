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
#define last Last
#define MAXK 2500
LL tot[5005][5005];
void solve(){
    int n;
    scanf("%d",&n);
    LL a[5005],b[5005];
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i = 1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    int rev[5005];
    for(int i = 1;i<=n;i++)rev[i]=a[i];
    reverse(rev+1,rev+n+1);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            tot[i][j]=tot[i-1][j-1]+rev[i]*b[j];
        }
    }
    LL ans=0;
    LL sum=0;
    for(int i=1;i<=n;i++){
        //sum+=a[i]*b[i];
        LL sum2=0;
        for(int j=n;j>=i;j--){
            ans=max(ans,sum+sum2+tot[n-(i-1)][j]-tot[n-j][i-1]);
          //  printf("%d %d %d %d\n",n-j,n-(i-1),i-1,j);
            sum2+=a[j]*b[j];
        }
        sum+=a[i]*b[i];
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;00000;
//    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
*/