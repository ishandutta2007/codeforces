#include<bits/stdc++.h>
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    LL matrix[50][50];
    MEMS(matrix);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i%2==0)printf("0 "),matrix[i][j]=0;
            else printf("%lld ",1ll<<(i+j-1)),matrix[i][j]=1ll<<(i+j-1);
        }
        printf("\n");
    }
    fflush(stdout);
    int q;
    scanf("%d",&q);
    while(q--){
        LL k;
        scanf("%lld",&k);
        int x=0,y=0;
        int now=0;
        printf("%d %d\n",x+1,y+1);
        while(x!=n-1||y!=n-1){
            if(x==n-1)y++;
            else if(y==n-1)x++;
            else if(k&(1ll<<now)){
               // printf("?\n");
                if(matrix[x+1][y]==(1ll<<now))x++;
                else y++;
            }
            else{
                 //printf("!\n");
                 if(matrix[x+1][y]==(1ll<<now))y++;
                else x++;
            }
            now++;
            printf("%d %d\n",x+1,y+1);
        }
        fflush(stdout);
        //printf("%d\n",ans);
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/