#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
    pll p[400005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        LL x,y;
        scanf("%lld %lld",&x,&y);
        p[i*2]=mp(x,1);
        p[i*2+1]=mp(y+1,-1);
    }
    sort(p,p+2*n);
    LL ans[400005];
    MEM(ans);
    int cnt=0;
    LL last=0;
    for(int i=0;i<2*n;i++){
        ans[cnt]+=p[i].x-last;
    //    printf("%d %d\n",cnt,p[i].x-last);
        last=p[i].x;
        cnt+=p[i].y;
    }
    for(int i=1;i<=n;i++)
    printf("%lld ",ans[i]);
}