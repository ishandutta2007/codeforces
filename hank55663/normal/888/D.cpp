#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
LL C[1005][1005];
LL fra[1005];
void build(){
    for(int i = 0;i<1005;i++){
        C[i][0]=C[i][i]=1;
        for(int j  =1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    fra[0]=1;
    fra[1]=0;
    fra[2]=1;
    fra[3]=2;
    fra[4]=9;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    build();
    LL cnt[5];
    cnt[0]=1;
    for(int i = 1;i<=4;i++){
        cnt[i]=C[n][i]*fra[i];
    }
  
    cnt[1]+=cnt[0];
    cnt[2]+=cnt[1];
    cnt[3]+=cnt[2];
    cnt[4]+=cnt[3];
   // printf("%lld %lld %lld %lld\n",cnt[1],cnt[2],cnt[3],cnt[4]);
    printf("%lld\n",cnt[k]);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/