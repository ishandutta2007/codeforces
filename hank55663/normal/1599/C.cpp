#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
LL C(int a,int b){
    LL res=1;
    for(int i = 0;i<b;i++)res=res*(a-i);
    for(int i = 1;i<=b;i++)res/=i;
    return res;
}
void solve(){
    int n;
    double p;
    scanf("%d %lf",&n,&p);
    p-=1e-9;
    for(int i = 0;i<=n;i++){
        int a=n-i,b=i;
        double pp=0;
        pp+=C(a,2)*1.0*C(b,1)/C(n,3)*0.5;
         pp+=C(a,1)*1.0*C(b,2)/C(n,3);
          pp+=1.0*C(b,3)/C(n,3);
         // printf("%.12f\n",pp);
        if(pp>p){
            printf("%d\n",i);
            return;
        }
    }
}
int main(){

    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
60.0 0.0 50.0 170.0 
3
40.0 0.0 0.0 0.0
5.0 20.0 5.0 170.0
95.0 0.0 95.0 80.0


0.0 1.0 4.0 1.0 
1
0.0 0.0 4.0 0.0
*/