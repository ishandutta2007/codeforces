#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int b,p,f;
        int h,c;
        scanf("%d %d %d %d %d",&b,&p,&f,&h,&c);
        int ans=0;
        for(int i = 0;i<=p;i++){
            for(int j = 0;j<=f;j++){
                if(i*2+j*2<=b){
                    ans=max(h*i+c*j,ans);
                }
            }
        }
        printf("%d\n",ans);
    }
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000

 */