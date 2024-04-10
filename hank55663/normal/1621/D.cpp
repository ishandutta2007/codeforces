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
#define index Index
void solve(){
    int n;
    scanf("%d",&n);
    int c[505][505];
    LL sum=0;
    for(int i = 0;i<2*n;i++){
        for(int j = 0;j<2*n;j++){
            scanf("%d",&c[i][j]);
            if(i>=n&&j>=n)sum+=c[i][j];
        }
    }
    int Min=1e9+7;
    Min=min(Min,c[n][0]);
    Min=min(Min,c[2*n-1][0]);
    Min=min(Min,c[n][n-1]);
    Min=min(Min,c[2*n-1][n-1]);
    Min=min(Min,c[0][n]);
    Min=min(Min,c[0][2*n-1]);
    Min=min(Min,c[n-1][n]);
    Min=min(Min,c[n-1][2*n-1]);
    printf("%lld\n",sum+Min);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
8876666554222188 
*/