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
    int n;
    scanf("%d",&n);
    pii p[100005];
    int degree[100005];
    MEM(degree);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        degree[x]++;
        degree[y]++;
    //    MEM(degree);
    }
    int a=0;
    for(int i = 1;i<=n;i++){
        if(degree[i]>=3){
            a=i;
            break;
        }
    }
    if(a==0){
        for(int i = 0;i<n-1;i++){
                printf("%d\n",i);
        }
    }
    else{
        int ans[100005];
        int now=0;
        MEMS(ans);
        for(int i = 1;i<n;i++){
            if(p[i].x==a||p[i].y==a)ans[i]=now++;
            if(now==3)break;
        }
        for(int i = 1;i<n;i++){
            if(ans[i]==-1)ans[i]=now++;
        }
        for(int i = 1;i<n;i++){
            printf("%d\n",ans[i]);
        }
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