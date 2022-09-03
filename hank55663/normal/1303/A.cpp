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
#define MXN 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       // int n;
       // scanf("%d",&n);
        char c[105];
        scanf("%s",c+1);
        int cnt[105];
        cnt[0]=0;
        int Min=1e9,Max=0;
        for(int i = 1;c[i]!=0;i++){
            cnt[i]=cnt[i-1]+(c[i]=='0');
            if(c[i]=='1'){
                Min=min(Min,i);
                Max=max(Max,i);
            }
        }
        if(Max==0)printf("0\n");
        else{
            printf("%d\n",cnt[Max]-cnt[Min]);
        }
    }
}