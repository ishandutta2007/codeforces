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
LL dp[2505][5005];
int val[5005];
const int mod=998244353;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[3];
    printf("SCAN 1 1\n");
    fflush(stdout);
    scanf("%d",&a[0]);
    printf("SCAN %d 1\n",n);
    fflush(stdout);
    scanf("%d",&a[1]);
    int l=1,r=n;
    int ll=a[0],rl=a[1];
    while(ll<rl)rl-=2,r--;
    while(rl<ll)ll-=2,l++;
    printf("SCAN %d 1\n",(l+r)/2);
    int xx;
    fflush(stdout);
    scanf("%d",&xx);
    while(ll>xx)ll-=2,l++;
    while(rl>xx)rl-=2,r--;
    int x1=l,x2=r;
    int d=xx-(x2-x1);
    printf("SCAN %d %d\n",(l+r)/2,d/2+1);
    fflush(stdout);
    int xxx;
    scanf("%d",&xxx);
    xxx-=(x2-x1);

    int y1=1+(d-xxx)/2;
    int y2=y1+xxx;
   // printf("%d %d %d %d\n",x1,x2,y1,y2);
    printf("DIG %d %d\n",x1,y1);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    if(x==1){
        printf("DIG %d %d\n",x2,y2);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        assert(x);
    }
    else{
        printf("DIG %d %d\n",x2,y1);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        assert(x);
        printf("DIG %d %d\n",x1,y2);
        fflush(stdout);
        scanf("%d",&x);
        assert(x);
    }
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/