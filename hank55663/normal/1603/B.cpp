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
void solve(){
    int x,y;
    scanf("%d %d",&x,&y);
    if(x==y)printf("%d\n",x);
    else if(y<x)printf("%d\n",x+y);
    else{
        LL tx=y*1ll/x*x;
        int res;
        printf("%d\n",res=(y-tx)/2+tx);
        assert(res%x==y%res);
    }
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
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
(k_1x+b)k_2+b=y
*/