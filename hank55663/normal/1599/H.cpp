#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
int Max=1e9;
void solve(){
    int res[4];
    pii q[4]={mp(1,1),mp(1,Max),mp(Max,1),mp(Max,Max)};
    for(int i = 0;i<4;i++){
        printf("? %d %d\n",q[i].x,q[i].y);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        res[i]=x;
    }
    int mid=(Max+(res[0]-res[1])+1)/2;
    printf("? 1 %d\n",mid);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    x++;
    int y=res[0]-(x-1)+1;
    int x2=Max-(res[2]-(y-1));
    int y2=Max-(res[1]-(x-1));
    printf("! %d %d %d %d\n",x,y,x2,y2);
}
int main(){

    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
60.0 0.0 50.0 170.0 
3
40.0 0.0 0.0 0.0
5.0 20.0 5.0 170.0
95.0 0.0 95.0 80.0


0.0 1.0 4.0 1.0 
1
0.0 0.0 4.0 0.0
*/