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
#define N 2000005
int main(){
    int n,K;
    scanf("%d %d",&n,&K);
    int a[85][85];
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
          //  a[i][j]=rand()%100000000;
        }
    }
    srand(time(NULL));
    int ans=1e9;
    for(int t=0;t<10000;t++){
        int bit[85];
        for(int i=0;i<n;i++){
            bit[i]=rand()%2;
        }
        int val[85][15];
        MEMS(val);
        val[0][0]=0;
        for(int k=0;k<K;k++){
            for(int i = 0;i<n;i++){
                if(val[i][k]!=-1){
                    for(int j=0;j<n;j++){
                        if(bit[i]!=bit[j]){
                            if(val[j][k+1]==-1)
                            val[j][k+1]=val[i][k]+a[i][j];
                            else
                            val[j][k+1]=min(val[i][k]+a[i][j],val[j][k+1]);
                        }
                    }
                }
            }
        }
        if(val[0][K]==-1){
         /*   for(int i = 0;i<n;i++){
                assert(bit[i]==bit[0]);
            }*/
        }
        else{
        //printf("%d\n",val[0][K]);
            ans=min(ans,val[0][K]);
        }
    }
    printf("%d\n",ans);
    return 0;
}