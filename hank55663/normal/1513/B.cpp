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
    int a[200005];
    int x=(1<<30)-1;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        x&=a[i];
    }
    LL cnt=0;
    for(int i = 0;i<n;i++){
        if(a[i]==x)cnt++;
    }
    LL ans=cnt*(cnt-1)%mod;
    for(int i = 1;i<=n-2;i++)ans=ans*i%mod;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}