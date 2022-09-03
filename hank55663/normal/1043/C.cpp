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
    char c[1005];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        if(c[i+1]==0){
            if(c[i]=='a')printf("1");
            else printf("0");
        }
        else if(c[i]!=c[i+1])
        printf("1");
        else
        printf("0");
        printf(" ");
    }
    printf("\n");
}

/*

23847657 
23458792534

102334155
111111111 
111111111
*/