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
    int n,q;
    scanf("%d %d",&n,&q);
    int p[200005];
    LL pre[200005];
    for(int i = 1;i<=n;i++)scanf("%d",&p[i]);
    pre[0]=0;
    sort(p+1,p+1+n);
    reverse(p+1,p+n+1);
    for(int i = 1;i<=n;i++)pre[i]=pre[i-1]+p[i];
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%lld\n",pre[x]-pre[x-y]);
    }
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}