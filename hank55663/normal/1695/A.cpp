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
#define index Index
#define MXN 1000000
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[55][55];
    int Max=-1e9-7;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&a[i][j]);
            Max=max(Max,a[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j  =0;j<m;j++){
            if(a[i][j]==Max){
                printf("%d\n",max(i+1,n-i)*max(j+1,m-j));
                return;
            }
        }
    }
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}