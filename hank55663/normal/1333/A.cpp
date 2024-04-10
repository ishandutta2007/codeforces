#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        if(n*m%2==0)
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    printf("B");
                }
                else if((i+j)%2==1){
                    printf("B");
                }
                else{
                    printf("W");
                }
            }
            printf("\n");
        }
        else{
            for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i+j)%2==1){
                    printf("W");
                }
                else{
                    printf("B");
                }
            }
            printf("\n");
        }
        }
    }
}
/*

*/