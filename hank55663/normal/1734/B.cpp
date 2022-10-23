#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 1000005
const int mod=1e9+7;
void solve(int T){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=i;j++){
            printf("%d ",j==0||j==i);
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
}

/*
100
3
0 4 4 
4
0 4 4 8 
5
0 8 8 8 8 
6
0 12 12 16 8 16 
7
0 24 24 32 16 16 16 
8
0 44 44 56 32 32 16 32 
9
0 88 88 112 64 64 32 32 32 
10
0 168 168 216 120 128 64 64 32 64 
11
0 336 336 432 240 256 128 128 64 64 64 
12
0 660 660 848 472 496 256 256 128 128 64 128 
*/