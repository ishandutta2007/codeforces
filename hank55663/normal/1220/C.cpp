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
#define MXN 15000
int main(){
    char c[500005];
    scanf("%s",c);
    char Min='z';
    for(int i = 0;c[i]!=0;i++){
        if(Min<c[i]){
            printf("Ann\n");
        }
        else{
            printf("Mike\n");
        }
        Min=min(Min,c[i]);
    }
    
    return 0;
}