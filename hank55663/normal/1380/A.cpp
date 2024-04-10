#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
void solve(){
      int n;
    scanf("%d",&n);
    int p[1005];
    for(int i = 1;i<=n;i++)scanf("%d",&p[i]);
    for(int i = 2;i<n;i++){
        if(p[i]>p[i-1]&&p[i]>p[i+1]){
            printf("YES\n%d %d %d\n",i-1,i,i+1);
            return ;
        }
    }
    printf("NO\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}