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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 300005
#define index Index
int main(){
    char c[100005];
    scanf("%s",c);
    int len=strlen(c)-1;
    int ok=1;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]!='0')ok=0;
    }
    if(len%2!=0)
    ok=0;
    printf("%d\n",len/2-ok+1);
} 
/*
7
A B son of C
A C son of D
A D son of B
A E son of B
A F son of C
A G son of D
A H son of E
*/