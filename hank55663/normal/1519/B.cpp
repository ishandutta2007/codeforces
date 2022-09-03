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
#define last Last
#define MAXK 2500
int a[105][105];
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    if(a[n][m]==k+1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<=100;j++){
            if(i==1)a[i][j]=a[i][j-1]+i;
            else if(j==1) a[i][j]=a[i-1][j]+j;
            else{
                a[i][j]=a[i-1][j]+j;
                assert(a[i][j-1]+i==a[i-1][j]+j);
            }
        }
    }
    while(t--){
        solve();
    }
}
/*
*/