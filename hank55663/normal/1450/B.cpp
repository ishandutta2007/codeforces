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
using namespace std;
#define MXN 100005
int g[105][105];
bool solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    pii p[105];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    int ok=0;
    for(int i = 0;i<n;i++){
        int ook=1;
        for(int j = 0;j<n;j++){
            if(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)<=k){
                g[i][j]=1;
            }
            else{
                ook=0;
                g[i][j]=1e9;
            }
        }
        ok|=ook;
    }
    if(ok==0)ok=-1;
    printf("%d\n",ok);
    /*
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
            }
        }
    }
*/
    return true;
}
int main(){
    int t=1;   scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}
/*

2 3
1 3
4 2
2 5
3 5
1 2
5 4
*/