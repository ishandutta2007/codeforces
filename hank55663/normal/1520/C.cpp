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
#define MXN 200005
void solve(){
    int n;
    scanf("%d",&n);
    if(n==2){
        printf("-1\n");
        return;
    }
    int ans[105][105];
    int now=1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            ans[i][j]=now;
            now+=2;
            if(now>n*n)now=2;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36
6x+s=ty
x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/