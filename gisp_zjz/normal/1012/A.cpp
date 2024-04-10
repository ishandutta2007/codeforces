#include<bits/stdc++.h>
#define maxn 2304939

using namespace std;
typedef long long ll;
int n,a[maxn];
ll ans;
int main(){
    cin >> n;
    for (int i=0;i<n*2;i++) scanf("%d",&a[i]);
    sort(a,a+n+n);
    ans=1ll*(a[n-1]-a[0])*(a[n*2-1]-a[n]);
    for (int i=1;i<n;i++) ans=min(ans,1ll*(a[n*2-1]-a[0])*(a[i+n-1]-a[i]));
    cout << ans << endl;
}