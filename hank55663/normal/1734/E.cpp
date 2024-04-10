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
#define MXN 1000005
const int mod=1e9+7;
int val[1000005];
void solve(int T){
    int n;
    scanf("%d",&n);
    int a[355][355];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i][i]);
        for(int j = i+1;j<n;j++){
            a[i][j]=(a[i][j-1]+i)%n;
        }
        for(int j = i-1;j>=0;j--){
            a[i][j]=(a[i][j+1]-i+n)%n;
        }
        for(int j = 0;j<n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
}