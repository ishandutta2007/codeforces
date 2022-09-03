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
int ans[505][505];
void solve(){
    int n=10;
    scanf("%d",&n);
    int a[505];
    for(int i = 1;i<=n;i++){
    scanf("%d",&a[i]);
    //    a[i]=i;
    }
    //random_shuffle(a+1,a+n+1);
    //for(int i = 1;i<=n;i++){
    //    printf("%d ",a[i]);
    //}
    //printf("\n");
    for(int i = 1;i<=n;i++){
        int cnt = a[i];
        int x=i,y=i;
        while(cnt--){
            ans[x][y]=a[i];
            if(y>1&&ans[x][y-1]==0){
                y--;
            }
            else{
                x++;
            }
        }  
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            printf("%d ",ans[i][j]);
            assert(ans[i][j]!=0);
        }
        printf("\n");
    }
}
int main(){
    int t=1;00000;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/