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
#define MXN 10000
const int mod=998244353;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[200005];
    LL ans=0;
    vector<int> v;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        ans+=a[i];
        v.pb((n-i)-a[i]);
    }
    ans-=(k)*1ll*(k-1)/2;
    sort(v.begin(),v.end());
    for(int i = 0;i<k;i++){
        ans+=v[i];
    }
    printf("%lld\n",ans);
}
int main(){
   // srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}