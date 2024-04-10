#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){   
    int n;
    scanf("%d",&n);
    int last=1;
    int a[10005];
    int vis[10005];
    fill(vis,vis+10005,0);
    for(int i  = 2;i<=n;i++){
        printf("? %d %d\n",last,i);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        printf("? %d %d\n",i,last);
        fflush(stdout);
        int y;
        scanf("%d",&y);
        if(x>y){
            a[last]=x;
            last=i;
            vis[x]=1;
        }
        else{
            a[i]=y;
            vis[y]=1;
        }
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i])a[last]=i;
    }
    printf("! ");
    for(int i = 1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    fflush(stdout);
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*
11 4 12
1 1 1 1
AABB
.AB.
CCDD
.CD.
EEFF
.EF.
GGHH
.GH.
IIJJ
.IJ.
KKLL

12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/