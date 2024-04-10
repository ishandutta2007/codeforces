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
const int mod=1e9+7;

void solve(){
    int n;
    scanf("%d",&n);
    pll p[100005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    LL sum=0;
    for(int i = 0;i<n;i++){
        sum+=p[i].y;
    }
    sort(p,p+n);
    LL Max=p[0].x+p[0].y;
    for(int i = 1;i<n;i++){
        sum+=max(0ll,p[i].x-Max);
        Max=max(Max,p[i].x+p[i].y);
    }
    printf("%lld\n",sum);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}