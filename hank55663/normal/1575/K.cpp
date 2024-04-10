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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    LL n,m,k,r,c;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&r,&c);
    LL ax,ay,bx,by;
    scanf("%lld %lld %lld %lld",&ax,&ay,&bx,&by);
    if(ax==bx&&ay==by){
          printf("%lld\n",f_pow(k,n*m));
          return;
    }
    LL x1=max(ax,bx),x2=min(ax+r-1,bx+r-1);
    LL y1=max(ay,by),y2=min(ay+c-1,by+r-1); 
    printf("%lld\n",f_pow(k,n*m-r*c));

}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/