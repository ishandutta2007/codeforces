




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
#define cpdd const pdd
#define rank Rank
#define MXN 150
#define KK 500
#define N 100005
int main(){
    int a1,a2,k1,k2;
    int n;
    scanf("%d %d %d %d %d",&a1,&a2,&k1,&k2,&n);
    printf("%d ",max(0,n-a1*(k1-1)-a2*(k2-1)));
    int ans=0;
    for(int i =0;i<=a1;i++)
        for(int j=0;j<=a2;j++){
            //printf("%d %d\n",a1*k1+)
            if(i*k1+j*k2<=n){
                ans=max(ans,i+j);
            }
        }
    printf("%d\n",ans);
    return 0;
}