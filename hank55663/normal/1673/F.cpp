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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int a[50][50];
pii p[2505];
#define index Index
int index=-1;
void go(int x,int y,int xx,int yy){
    if(x==xx&&y==yy){
        a[x][y]=++index;
        p[index]=mp(x,y);
    return;
    }
    //if(x<=xx&&y<=yy){
        int midx=(x+xx)/2,midy=(y+yy)/2;
        int nextx=midx+1,nexty=midy+1;
        if(x>xx)swap(midx,nextx);
        if(y>yy)swap(midy,nexty);
        go(x,y,midx,midy);
        go(xx,y,nextx,midy);
        go(x,yy,midx,nexty);
        go(xx,yy,nextx,nexty);
   // }

}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    go(1,1,32,32);

//    vector<int> v;
    
   /* for(int j = 1;j<=n;j++){
        for(int k = 1;k<=n;k++){
            a[j][k]=++index;
            p[index]=mp(j,k);
        }
    }*/
  /*  for(int j = 1;j<=n;j++){
        for(int k = 1;k<=n;k++){
            printf("%d ",a[j][k]);
        }
        printf("\n");
    }*/
    int sum=0;
    for(int j = 1;j<=n;j++){
        for(int k = 1;k<n;k++){
            printf("%d ",a[j][k]^a[j][k+1]);
            sum+=a[j][k]^a[j][k+1];
        }
        printf("\n");
    }
    for(int j= 1;j<n;j++){
        for(int k = 1;k<=n;k++){
            printf("%d ",a[j][k]^a[j+1][k]);
            sum+=a[j][k]^a[j+1][k];
        }
        printf("\n");
    }
   // printf("%d\n",sum);
    fflush(stdout);
    int last=0;
    while(k--){
        int x;
        scanf("%d",&x);
        last^=x;
        printf("%d %d\n",p[last].x,p[last].y);
        fflush(stdout);
    }
}
int main(){
    srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/