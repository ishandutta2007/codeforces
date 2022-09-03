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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
LL val[5005][5005];
LL tot[5005];
LL mod=1e9+7;
bool solve(){
    int n,k,q;
    scanf("%d %d %d",&n,&k,&q);
    for(int i = 1;i<=n;i++){
        val[0][i]=1;
   //     tot[i]++;
    }
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=n;j++){
            val[i][j]=val[i-1][j-1]+val[i-1][j+1];
            val[i][j]%=mod;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=k;j++){
            tot[i]+=val[j][i]*val[k-j][i]%mod;
            tot[i]%=mod;
        }
      //  printf("%d ",tot[i]);
    }
    LL ans=0;
    LL a[5005];
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        ans+=a[i]*tot[i]%mod;
        ans%=mod;
    //    printf("%lld ",tot[i]);
    }
   // printf("\n");
    while(q--){
        int i,x;
        scanf("%d %d",&i,&x);
        ans-=a[i]*tot[i]%mod;
        ans+=mod;
        ans%=mod;
        a[i]=x;
        ans+=a[i]*tot[i]%mod;
        ans+=mod;
        ans%=mod;
        printf("%lld\n",ans);
    }
}
int main(){
    int t=1;//00000;
 //   scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/