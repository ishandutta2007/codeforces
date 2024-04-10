
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
#define KK 500
#define N 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,s;
        scanf("%d %d",&n,&s);
        LL tot[2]={0,0};
        int skip=0;
        int needskip=0;
        int ans=0;
        for(int i = 1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(tot[0]<tot[1]+x){
                tot[1]=tot[0];
                skip=i;
            }
            else{
                tot[1]=tot[1]+x;
            }
        //  tot[1]=min(tot[0],tot[1]+x);
            tot[0]+=x;
            if(tot[1]<=s){
                if(ans<i-1){
                    ans=i-1;
                    needskip=skip;
                }
               // ans=max(ans,i-1);
            }
            if(tot[0]<=s){
                //ans=max(ans,i);
                if(ans<i){
                    ans=i;
                    needskip=0;
                }                
            }
        }
        printf("%d\n",needskip);
    }
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/