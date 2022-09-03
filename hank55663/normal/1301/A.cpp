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
        char a[105],b[105],c[105];
        scanf("%s %s %s",a,b,c);
        int ok=1;
        for(int i = 0;a[i]!=0;i++){
            if(a[i]==c[i]||b[i]==c[i]){

            }
            else{
                ok=0;
            }
        }
        if(!ok){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
}