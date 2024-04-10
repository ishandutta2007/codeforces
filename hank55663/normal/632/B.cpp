#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL pre[500005];
LL preb[500005];
LL sufb[500005];
LL prea[500005];
LL sufa[500005];
LL suf[500005];
int c[500005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&c[i]);
        pre[i]=pre[i-1]+c[i];
    }
    char cc[500005];
    scanf("%s",cc+1);
    for(int i = 1 ; i<=n ; i++){
        preb[i]=preb[i-1];
        prea[i]=prea[i-1];
        if(cc[i]=='B')preb[i]+=c[i];
        else prea[i]+=c[i];
    }
    for(int i = 1;i<=n;i++){
        sufb[i]=preb[n]-preb[i-1];
        suf[i]=pre[n]-pre[i-1];
        sufa[i]=prea[n]-prea[i-1];
    }
    LL ans=preb[n];
    for(int i = 1;i<=n;i++){
        ans=max(ans,preb[i]+sufa[i+1]);
        ans=max(ans,prea[i]+sufb[i+1]);
       // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
}