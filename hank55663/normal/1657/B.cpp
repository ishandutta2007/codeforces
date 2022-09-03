#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
void solve(){
    int n,b,x,y;
    scanf("%d %d %d %d",&n,&b,&x,&y);
    LL now=0;
    LL ans=0;
    for(int i = 1;i<=n;i++){
        if(now+x<=b)now+=x;
        else now-=y;
        ans+=now;
    }
    printf("%lld\n",ans);
}


int main(){
    int t=1;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/