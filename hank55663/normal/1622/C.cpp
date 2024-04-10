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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
const int mod=1e9+7;
void solve(){
    int n;
    LL k;
    scanf("%d %lld",&n,&k);
    LL a[200005];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    LL ans=1e18;
    sort(a,a+n);
    LL tot=0;
    for(int i=1;i<n;i++){
        LL need=(k-tot)/(n-i+1);
        if(need*(n-i+1)+tot>k)need--;
        ans=min(ans,max(a[0]-need,0ll)+n-i);
        tot+=a[i];
    }
    ans=min(ans,a[0]-(k-tot));
    if(tot+a[0]<=k){
        printf("0\n");
    }
    else
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/