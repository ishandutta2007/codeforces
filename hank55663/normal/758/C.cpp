#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
int main(){
    LL n,m,k,x,y;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&x,&y);
    LL row[105];
    if(n==1){
        row[0]=k;
    }
    else{
        LL re=k%m;
        k/=m;
        int rem=0;
        for(int i = 0;i<n;i++){
            rem++;
            row[i]=(k-i-1+2*(n-1))/(2*(n-1))*m;
        }
        for(int i = n-2;i>0;i--){
            rem++;
            row[i]+=(k-rem+2*(n-1))/(2*(n-1))*m;
        }
        if((k)%(2*(n-1))<n){
            row[(k)%(2*(n-1))]+=re;
        }
        else{
            LL value=k%(2*(n-1))-(n-1);
            //printf("%lld\n",value);
            row[n-value-1]+=re;
        }
    }
    LL ans[105][105];
    LL Max=0,Min=1e18;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            ans[i][j]=row[i]/m+(row[i]%m>j);
         //   printf("%lld ",ans[i][j]);
            Max=max(Max,ans[i][j]);
            Min=min(Min,ans[i][j]);
        }
        //printf("\n");
    }
    printf("%lld %lld %lld\n",Max,Min,ans[x-1][y-1]);
    return 0;
}
/*
1 
2 6 
3 5 
4
*/