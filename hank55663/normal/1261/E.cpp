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
#define MXN 200005
int main(){
    int n;
    scanf("%d",&n);
    pii p[1005];
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i);
    }
    sort(p,p+n);
    int ans[1005][1005];
    MEM(ans);
    for(int i = 0;i<n;i++){
        for(int j=i;j>=0;j--){
            ans[j][p[i].y]=1;
            p[i].x--;
            if(!p[i].x)break;
        }
        for(int j=i+2;p[i].x;j++){
            ans[j][p[i].y]=1;
            p[i].x--;
        }
    }
    printf("%d\n",n+1);
    for(int i = 0;i<=n;i++){
        for(int j=0;j<n;j++){
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/