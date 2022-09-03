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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
int main(){
    char c[300005];
    scanf("%s",c);
    int l=0,r=strlen(c)-1;
    while(true){
        int cntl=0,cntr=0;
        while(c[l]==c[r]&&l!=r)l++,cntl++;
        if(l==r){
            if(cntl>=1)
            printf("%d\n",cntl+2);
            else
            printf("0\n");
            return 0;
        }
        if(cntl==0){
            printf("0\n");
            return 0;
        }
        while(c[r]==c[l-1])r--,cntr++;
      //  printf("%d %d\n",cntl,cntr);
        if(cntl&&cntr&&cntl+cntr>=3);
        else{
            printf("0\n");
            return 0;
        }
    }
}
/*
2 -2000000000 2 -20000000000 1 1
*/