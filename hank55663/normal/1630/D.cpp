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
vector<int> v[1000005];
int cnt[1000005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[1000005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    int gcd = 0;
    for(int i = 0;i<m;i++){
        int x;
        scanf("%d",&x);
        gcd=__gcd(x,gcd);
    };
    int mod=gcd;
    LL sum=0;
    for(int i = 0;i<n;i++){
        v[i%mod].pb(abs(a[i]));
        if(a[i]<0)cnt[i%mod]^=1;
        sum+=abs(a[i]);
    }
    LL add=0;
    LL ans=-1e18;
    for(int t=0;t<2;t++){
        add=0;
        for(int i = 0;i<mod;i++){
            if(cnt[i]){
                sort(v[i].begin(),v[i].end());
                add+=v[i][0];
            }
            cnt[i]^=1;
        }
        ans=max(ans,sum-2*add);
    }
    for(int i = 0;i<mod;i++)cnt[i]=0,v[i].clear();
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567
*/