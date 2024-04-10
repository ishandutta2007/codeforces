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
#define MXN 200005
double dp[100][100];
double c,m,p,v;
double Ans(double a,double b){

    if(a<0)return 1;
    return b+a*(Ans(a-v,b+v)+1);
}
double DP(int a,int b){
   // printf("%d %d\n",a,b);
    if(dp[a][b]>-0.5)return dp[a][b];
    double cc=c-a*v+b*v/2;
    double mm=m-b*v+a*v/2;
    double pp = 1-cc-mm;
    double ans=pp;
    if(cc>v+1e-6)ans+=cc*(DP(a+1,b)+1);
    else{
        ans+=cc*(Ans(mm+cc/2,pp+cc/2)+1);
    }
    if(mm>v+1e-6)ans+=mm*(DP(a,b+1)+1);
    else{
        ans+=mm*(Ans(cc+mm/2,pp+mm/2)+1);
    }
    //printf("%.12f %.12f %.12f %.12f %d %d\n",cc,mm,pp,ans,a,b);
    return dp[a][b]=ans;
}
void solve(){
    MEMS(dp);
    scanf("%lf %lf %lf %lf",&c,&m,&p,&v);
    printf("%.12f\n",DP(0,0));
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}