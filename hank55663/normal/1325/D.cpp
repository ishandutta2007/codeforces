#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long
#define ULL unsigned long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main(){
    LL u,v;
    //srand(time(NULL));
    //LL u=rand()%10000000;
    //LL v=u+rand()%10000000;
    //if(u%2!=v%2)v++;
    //printf("%lld %lld\n",u,v);
    scanf("%lld %lld",&u,&v);
    if(u%2!=v%2||u>v){
        printf("-1\n");
    }
    else{
        int num[64];
        MEM(num);
        int go=0;
        for(int i = 0;i<60;i++){
            if(((u&(1ll<<i))==(v&(1ll<<i))&&!go)||((u&(1ll<<i))!=(v&(1ll<<i))&&go)){
                if(u&(1ll<<i))num[i]=1;
                else num[i]=0,go=0;
            }
            else{
                num[i-1]+=2;
                if(u&(1ll<<i))num[i]=1,go=1;
                else num[i]=0;
            }
           // if(i<5)printf("%d\n",go);
        }
        int Max=0;
        vector<LL> ans(15,0);
        for(int i = 0;i<60;i++){
            Max=max(Max,num[i]);
          //  printf("%d ",num[i]);
            for(int j=0;j<num[i];j++){
                ans[j]+=(1ll<<i);
            }
        }
        printf("%d\n",Max);
        LL sum=0,res=0;
        for(int i = 0;i<Max;i++){
            printf("%lld ",ans[i]);
            sum+=ans[i];
            res^=ans[i];
        }
        printf("\n");
      //  printf("\n%lld %lld\n",sum,res);
    }

}
/*
5
0 9 7 1 100
-1 0 -1 -1 91
-1 5 0 -1 96
-1 8 9 0 99
-1 -1 -1 -1 0
3 4
3 5
5 6
5 7
3 or 4
3 or 5
5 or 6
5 or 7

dp[x]=max(dp[x-w_i*j]+j*t_i-delta t_i*j*(j-1)/2)
dp[x]=max(dp[j]+x*t_i-j*t_i-delta t_i*(x-j)*(x-j-1)/2)
dp[x]=max(dp[j]-j*t_i-delta t_i *(j^2/2+j/2) - 
        delta t_i * xj + x*t_i + delta t_i * (x^2/2-x/2))
dp[x]=max(dp[j] + g(j) - delta t_i *xj + w(i) )
g(j)= dp[j]-j*t_i-delta t_i *(j^2/2+j/2)
w(i)=  x*t_i + delta t_i * (x^2/2-x/2)
x^2/2 -xj -x/2  +j^2/2 +j/2
*/