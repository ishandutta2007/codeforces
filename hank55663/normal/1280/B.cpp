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
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
int mod=1e9+7;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int r,c;
        scanf("%d %d",&r,&c);
        char g[70][70];
        int cnt=0;
        for(int i = 1;i<=r;i++){
            scanf("%s",g[i]+1);
            for(int j=1;j<=c;j++){
                if(g[i][j]=='A'){
                    cnt++;
                }
            }
        }
        if(cnt==0){
            printf("MORTAL\n");
        }
        else if(cnt==r*c){
            printf("0\n");
        }
        else{
            int ook[4]={1,1,1,1};
            for(int i = 1;i<=c;i++){
                if(g[1][i]=='P')ook[0]=0;
                if(g[r][i]=='P')ook[1]=0;
            }
            for(int i = 1;i<=r;i++){
                if(g[i][1]=='P')ook[2]=0;
                if(g[i][c]=='P')ook[3]=0;
            }
            if(ook[0]||ook[1]||ook[2]||ook[3]){
                printf("1\n");
            }
            else{
                if(g[1][1]=='A'||g[r][c]=='A'||g[1][c]=='A'||g[r][1]=='A'){
                    printf("2\n");
                }
                else{
                    int ok=0;
                    for(int i = 1;i<=r;i++){
                        int ook=1;
                        for(int j=1;j<=c;j++){
                            if(g[i][j]=='P')ook=0;
                        }
                        if(ook)ok=1;
                    }
                    for(int i = 1;i<=c;i++){
                        int ook=1;
                        for(int j=1;j<=r;j++){
                            if(g[j][i]=='P')ook=0;
                        }
                        if(ook)ok=1;
                    }
                    if(ok){
                        printf("2\n");
                    }
                    else{
                        int ok=0;
                        for(int i = 1;i<=r;i++){
                            if(g[i][1]=='A'||g[i][c]=='A')ok=1;
                        }
                        for(int i = 1;i<=c;i++){
                            if(g[1][i]=='A'||g[r][i]=='A')ok=1;
                        }
                        if(ok){
                            printf("3\n");
                        }
                        else{
                            printf("4\n");
                        }
                    }
                }
            }
        }
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/