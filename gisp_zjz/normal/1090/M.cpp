#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
int a[maxn],b[maxn],cnt,n,ans;
int main(){
    cin >> n >> ans; ans=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++) if (a[i]==a[i+1]) b[++cnt]=i;
    b[++cnt]=n;
    for (int i=1;i<=cnt;i++) ans=max(ans,b[i]-b[i-1]);
    cout << ans << endl;
}