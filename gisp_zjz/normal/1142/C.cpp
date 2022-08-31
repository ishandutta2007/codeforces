#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=1e6+9;
typedef long long ll;
typedef pair<ll,ll> pi;
map <ll,ll> f;
pi st[maxn],a[maxn];
int t,n,m;
bool check(pi u,pi v,pi w){
    return (v.S-u.S)*(u.F-w.F)>=(w.S-u.S)*(u.F-v.F);
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        y-=x*x;
        if (f.find(-x)==f.end()) f[-x]=y; else f[-x]=max(f[-x],y);
    }
    for (auto &x:f) a[++m]=x;
    for (int i=1;i<=m;i++){
        while (t>1&&check(st[t-1],st[t],a[i])) t--;
        st[++t]=a[i];
    }
    printf("%d\n",t-1);
    return 0;
}