#include<bits/stdc++.h>
#define maxn 200005

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],t,n,ans;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) a[i]++,b[i]=a[i];
    for (int i=n-1;i>=1;i--) a[i]=max(a[i],a[i+1]-1);
    for (int i=2;i<=n;i++) a[i]=max(a[i],a[i-1]);
    for (int i=1;i<=n;i++) ans+=(a[i]-b[i]);
    cout << ans << endl;
}