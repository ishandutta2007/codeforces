#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+3;
const ll INF=1e15;
ll TA,TB,n,m,k,p,ans;
ll a[maxn],b[maxn];
int main(){
    cin >> n >> m >> TA >> TB >> k;
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]); sort(a+1,a+n+1);
    for (int i=1;i<=m;i++) scanf("%I64d",&b[i]); sort(b+1,b+m+1); b[m+1]=INF;
    if (k>=min(n,m)) {puts("-1");return 0;}
    p=1; ans=0;
    for (int i=1;i<=k+1;i++){
        while (b[p]<a[i]+TA) ++p;
        if (p+k-i+1>m) {puts("-1");return 0;}
        ans=max(ans,b[p+k-i+1]);
    }
    cout << ans+TB << endl;
    return 0;
}