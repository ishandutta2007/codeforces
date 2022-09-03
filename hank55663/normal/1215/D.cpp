




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
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    int cntl=0,suml=0;
    int cntr=0,sumr=0;
    for(int i = 0;c[i]!=0;i++){
        if(i<n/2){
            if(c[i]=='?')cntl++;
            else suml+=c[i]-'0';
        }
        else{
            if(c[i]=='?')cntr++;
            else sumr+=c[i]-'0';
        }
    }
    if((cntl+cntr)&1){
        printf("Monocarp\n");
    }
    else{
        cntl-=cntr;
        suml-=sumr;
        if(cntl==0){
            if(suml==0){
                printf("Bicarp\n");
            }
            else{
                printf("Monocarp\n");
            }
        }
        if(cntl<0){
            if(suml<0){
                printf("Monocarp\n");
            }
            else{
                if(-cntl/2*9==suml){
                    printf("Bicarp\n");
                }
                else{
                    printf("Monocarp\n");
                }
            }
        }
        if(cntl>0){
            if(suml>0){
                printf("Monocarp\n");
            }
            else{
               // printf("%d %d\n",cntl,suml);
                if(-cntl/2*9==suml){
                    printf("Bicarp\n");
                }
                else{
                    printf("Monocarp\n");
                }
            }
        }
    }
    return 0;
}