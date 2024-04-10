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
int a[1005][1005];
int val[1005][1005];
int X[4]={0,0,1,-1},Y[4]={1,-1,0,0};
//bitset<505> b[1005][1005];
void solve(){
    MEM(a);
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&val[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        if(i%2==0){
            if(i/2%2==0){
                for(int j=0;j<4;j++){
                    int x=X[j],y=i+Y[j];
                    if(x>=0&&x<n&&y>=0&&y<n){
                        a[x][y]^=1;
                    }
                }
                ans^=val[0][i];
                ans^=val[n-1][i];
            }
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = i&1;j<n;j+=2){
          //  printf("%d\n",j);
            if(a[i-1][j]==0){
             //   printf("!\n");
                for(int k=0;k<4;k++){
                    int x=i+X[k],y=j+Y[k];
                    if(x>=0&&x<n&&y>=0&&y<n){
                        a[x][y]^=1;
                    }
                }
                ans^=val[i][j];
                ans^=val[n-i-1][j];
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}