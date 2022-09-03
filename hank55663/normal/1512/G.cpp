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
static const double INF = 2147483647;
LL ans[30000005];
LL res[30000005];
void solve(){
    int n;
    scanf("%d",&n);
    if(res[n]==0)printf("-1\n");
    else printf("%lld\n",res[n]);
}
int main(){
    for(int i = 1;i<=5000;i++){
        for(int j = i*i;j<=10000000;j+=i){
            ans[j]+=i;
            if(j!=i*i){
                ans[j]+=j/i;
            }
        }
    }
    for(int i = 1;i<=10000000;i++){
        if(ans[i]<=10000000&&!res[ans[i]])
        res[ans[i]]=i;
    }
    
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/