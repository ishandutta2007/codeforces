#include<bits/stdc++.h>
#define maxn 523456
#define M 1000000007

using namespace std;
typedef long long ll;
ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}
ll a[maxn],ans,n,k,m;

int main(){
    cin >> n >> k; m=(n+1)/2;
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    sort(a+1,a+1+n); ans=abs(a[m]-k);
    for (int i=1;i<m;i++) ans+=max(0ll,a[i]-k);
    for (int i=m+1;i<=n;i++) ans+=max(0ll,k-a[i]);
    cout << ans << endl;
}