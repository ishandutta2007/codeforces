#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000009;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-10;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double dp[1100][1100];
int p[1100];
double L[1100];
double R[1100];
int main(){
    int a,b;scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",p+i);p[i]--;
    }
    for(int i=0;i<a;i++)for(int j=0;j<a;j++){
        if(p[i]>p[j])dp[i][j]=1;
    }
    for(int i=0;i<b;i++){
        int s,t;scanf("%d%d",&s,&t);s--;t--;
        for(int j=0;j<a;j++)L[j]=R[j]=0;
        for(int j=0;j<a;j++){
            if(j!=s&&j!=t){
                L[j]=(dp[s][j]+dp[t][j])/2;
                R[j]=(dp[j][s]+dp[j][t])/2;
            }
        }
        dp[s][t]=dp[t][s]=0.5;
        for(int j=0;j<a;j++){
            if(j!=s&&j!=t){
                dp[s][j]=dp[t][j]=L[j];
                dp[j][s]=dp[j][t]=R[j];
            }
        }
    }
    double ret=0;
    for(int i=0;i<a;i++)for(int j=i+1;j<a;j++)ret+=dp[i][j];
    printf("%.12f\n",ret);
}