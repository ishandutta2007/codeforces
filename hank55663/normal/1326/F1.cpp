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
#define pi acos(-1)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL dp[1<<14][14][1<<7];
int main(){
    int g[15][15];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            char c=rand()%2+'0';
           scanf(" %c",&c);
            g[i][j]=c-'0';
        }
        dp[1<<i][i][0]=1;
    }
    for(int i = 0;i<(1<<n);i++){
        if(__builtin_popcount(i)>(n-1)/2)continue;
        for(int j=0;j<n;j++){
            if(!(i&(1<<j)))continue;
            for(int k = 0;k<(1<<7);k++){
                if(dp[i][j][k]){
                    
                    for(int l=0;l<n;l++){
                        if(!(i&(1<<l))){
                            if(g[j][l])dp[i+(1<<l)][l][k*2+1]+=dp[i][j][k];
                            else dp[i+(1<<l)][l][k*2]+=dp[i][j][k];
                        }
                    }
                }
            }
        }
    }
    LL ans[1<<14];
    MEM(ans);
    for(int i = 0;i<(1<<n);i++){
        if(__builtin_popcount(i)==n/2){
            int other=(1<<n)-i-1;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    int numa=n/2,numb=n-n/2;
                    int vala[1<<6],valb0[1<<6],valb1[1<<6];
                    MEM(valb0);
                    MEM(valb1);
                    for(int a=0;a<(1<<(numa-1));a++)vala[a]=dp[i][j][a];
                    for(int k=0;k<n;k++){
                        if(other&(1<<k)){
                            //int vala[1<<6],valb[1<<6];
                            int val=g[j][k];
                            for(int a=0;a<(1<<(numb-1));a++){
                                int tmp=a;
                                int sum=0;
                                for(int b=0;b<numb-1;b++){
                                    sum=(sum<<1)+(tmp&1);
                                    tmp>>=1;
                                }
                                if(val)
                                valb1[sum]+=dp[other][k][a];
                                else
                                valb0[sum]+=dp[other][k][a];
                            }
                        }
                    }
                    for(int a=0;a<(1<<(numa-1));a++){
                        for(int b=0;b<(1<<(numb-1));b++){
                            ans[(((a<<1)+1)<<(numb-1))+b]+=(LL)vala[a]*valb1[b];
                            ans[(((a<<1))<<(numb-1))+b]+=(LL)vala[a]*valb0[b];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i<(1<<(n-1));i++){
        printf("%lld ",ans[i]);
    }

}
/*

5
AACCMMAA
A
AA
MM
ACA
ACMAA


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

/*
 

*/