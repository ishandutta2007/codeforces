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
LL Max[1000005];
void solve(){
    int n,c;
    map<int,LL> m;
    scanf("%d %d",&n,&c);
    for(int i = 0;i<n;i++){
        int c,d,h;
        scanf("%d %d %d",&c,&d,&h);
     //   v.pb(mp(c,d*1ll*h));
        m[c]=max(m[c],d*1ll*h);
    }
    for(auto it:m){
        LL ans=0;
        for(int j = 0;j<=c;j+=it.x){
            Max[j]=max(Max[j],ans);
            ans+=it.y;
        }
    }
    for(int i = 1;i<=c;i++)Max[i]=max(Max[i],Max[i-1]);
    int q;
    scanf("%d",&q);
    while(q--){
        LL d,h;
        scanf("%lld %lld",&d,&h);
        LL val=d*h;
        if(Max[c]<=val){
            printf("-1 ");
        }
        else printf("%d ",upper_bound(Max,Max+c+1,val)-Max);
    }
    printf("\n");
}


int main(){
    int t=1;
  //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/