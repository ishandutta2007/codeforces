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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int vis[100005];
    fill(vis,vis+4*n+1,0);
    for(int i = 1;i<=m;i++)vis[i]=1;
    for(int i = 0;i<4*n;i++){
        if(i%2==1){
            if(vis[i/2+1])
            printf("%d ",i/2+1);
        }
        if(i%2==0){
            if(vis[i/2+1+2*n])
            printf("%d ",i/2+1+2*n);
        }
        /*if(i%4==2){
            printf("%d ",i/2+1+2*n);
        }
        if(i%4==3){
            printf("%d ",i/2+1);
        }*/
    }
    printf("\n");
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/