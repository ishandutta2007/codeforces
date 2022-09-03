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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 10000
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int ans=0;
        for(int i = 0;i<(1<<8);i++){
            int cnt[3]={0,0,0};
            for(int j=1;j<8;j++){
                if(i&(1<<j)){
                    for(int k=0;k<3;k++){
                        if(j&(1<<k))cnt[k]++;
                    }
                }
            }
            if(cnt[0]<=a&&cnt[1]<=b&&cnt[2]<=c){
                //printf("%d %d %d %d %d\n",cnt[0],cnt[1],cnt[2],i,);
                ans=max(ans,(int)__builtin_popcount(i));
            }
        }
        printf("%d\n",ans-1);
    }
    return 0;
}