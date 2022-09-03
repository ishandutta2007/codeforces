#include<bits/stdc++.h>
#pragma optimizer(O2)
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
    int n;
    scanf("%d",&n);
    pii p[1005];
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int num=y/x;
        int sm=x-y%x,b=y%x;
        printf("%d\n",num*num*sm+(num+1)*(num+1)*b);
    }
}