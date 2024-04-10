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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL p[200005];
    p[0]=0;
    for(int i = 1;i<=n;i++){
        scanf("%lld",&p[i]);
        p[i]+=p[i-1];
    }
    int x[200005];
    for(int i = 0;i<m;i++){
        scanf("%d",&x[i]);
        x[i]+=100;
    }
    sort(x,x+m);
    LL ans=0;
    ans=max(ans,p[min((x[0]-1)/100,n)]);
   // printf("%lld\n",ans);
    if(x[m-1]<n*100){
        ans=max(ans,p[n]-p[x[m-1]/100]);
    }
    for(int i = 1;i<m;i++){
        int d=(x[i]-x[i-1]-1)/2/100+1;
       // printf("%d\n",d);
        for(int j = min(x[i-1]/100+1,n+1);j<=n&&j<=(x[i]-1)/100;j++){
            ans=max(ans,p[j]-p[max(j-d,(x[i-1])/100)]);
        }
    }
    printf("%lld\n",ans);
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
 //   scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/