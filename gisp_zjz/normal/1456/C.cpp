#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+200;
const int M=1000000007;
ll a[maxn],ans,suf[maxn];
int n,k;
int main(){
    scanf("%d%d",&n,&k); ++k;
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a,a+n);
    for (int i=n-1;i>=0;i--) suf[i]=suf[i+1]+a[i];
    for (int i=0;i<n;i++) ans+=a[i]*(i/k);
    for (int i=0;i<n;i++) if (i%k) ans+=max(0ll,suf[i]);
    cout << ans << endl;
    return 0;
}