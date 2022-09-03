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
#define MXN 300000
const int mod=998244353;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[105];
    int ans=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    printf("%d\n",max(ans-m,0));
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