#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int n;
    LL x;
    scanf("%d %lld",&n,&x);
    LL d[400005];
    for(int i = 1;i<=n;i++){
        scanf("%lld",&d[i]);
    }
    d[0]=d[n];
    for(int i = n+1;i<=2*n;i++)d[i]=d[i-n];
    reverse(d,d+n*2+1);
    int r=1;
    LL sum=0;
    LL ans=0;
    LL res=0;
    for(int i = 1;i<=n;i++){
        while(sum+d[r]<=x){
            sum+=d[r];
            ans+=(1+d[r])*d[r]/2;
            r++;
        }
      //  printf("%d %d\n",sum,r);
      //  if(x-sum!=0)
        if(d[r]>=x-sum){
            res=max(res,ans+(d[r]+1+d[r]-(x-sum))*(x-sum)/2);
        }
        sum-=d[i];
        ans-=(1+d[i])*(d[i])/2;
    }
    printf("%lld\n",res);
}
/*
2 11 14
9 3


000111222
001112220
*/