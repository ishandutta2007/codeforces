#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=6e5+12;
ull a[maxn],b[maxn];
int n,m;
ll c[maxn];
map <ull,ll> f;
mt19937_64 gen(time(0));
int main(){
    int _; scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&m); f.clear();
        for (int i=1;i<=n;i++) {
            a[i]=gen(); b[i]=0;
            scanf("%lld",&c[i]);
        }
        for (int i=1;i<=m;i++){
            int u,v; scanf("%d%d",&u,&v);
            b[v]^=a[u];
        }
        for (int i=1;i<=n;i++) f[b[i]]+=c[i];
        ll ans=0;
        for (auto x:f) if (x.F) ans=__gcd(ans,x.S);
        printf("%lld\n",ans);
    }
    return 0;
}