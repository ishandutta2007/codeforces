#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+3;
int n,k,cnt[maxn],last,f[maxn],l[maxn],r[maxn];
ll ans;
int main(){
    scanf("%d",&n); ans=1ll*n*n;
    for (int i=1;i<=n;i++){
        scanf("%d",&k);
        for (int j=1;j<=k;j++) scanf("%d",&f[j]);
        bool flag=0;
        for (int j=1;j<k;j++) flag|=f[j]<f[j+1];
        if (flag) continue;
        l[f[k]]++; r[f[1]]++;
    }
    for (int i=0;i<maxn;i++) {
        if (i) r[i]+=r[i-1];
        ans-=1ll*l[i]*r[i];
    }
    printf("%lld\n",ans);
    return 0;
}