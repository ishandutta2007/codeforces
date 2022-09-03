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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[505][505];
    int Max[505][505];
    for(int i = 0;i<=n+1;i++){
        for(int j =0;j<=m+1;j++){
            c[i][j]=0;
            Max[i][j]=0;
        }
    }
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
    }
    int ans=0;
    for(int i = n;i>=1;i--){
        for(int j = 1;j<=m;j++){
            if(c[i][j]=='*'){
                Max[i][j]=min(min(Max[i+1][j],Max[i+1][j-1]),Max[i+1][j+1])+1;
                ans+=Max[i][j];  
            }
            else{
                Max[i][j]=0;
            }
           //  printf("%d",Max[i][j]);
        }
       // printf("\n");
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;   scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}