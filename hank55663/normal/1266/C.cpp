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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    if(r==1&&c==1){
        printf("0\n");
    }
    else{
        if(r==1){
            for(int i=0;i<c;i++){
                printf("%d ",i+2);
            }
            printf("\n");
        }
        else if(c==1){
            for(int i = 0;i<r;i++){
                printf("%d\n",i+2);
            }
            //printf("\n");
        }
        else{
            for(int i = 1;i<=r;i++){
                for(int j=1;j<=c;j++){
                    printf("%d ",i*(j+r));
                }
                printf("\n");
            }
        }
    }
}
/*
510510

255255
170170
102102
72930
46410
39270
30030

5 3
3 -1 
4 2 
1 1 
5 3 
2 2 
4 1 
3 2 
5 3 

*/