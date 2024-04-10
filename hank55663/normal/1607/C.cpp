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
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    LL a[200005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    LL tmp=0;
    LL ans=a[0];
    for(int i = 0;i<n-1;i++){
       // if(a[i]+tmp>0)break;
        tmp+=-(a[i]+tmp);
        ans=max(ans,a[i+1]+tmp);
    }
    printf("%lld\n",ans);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/