#include<bits/stdc++.h>
using namespace std;
const int maxn=505050;
int n,ans,m;
int a[maxn],l[maxn],r[maxn];
int main(){
    cin >> n >> m;
    for (int i=1;i<=m;i++) cin >> a[i];
    for (int i=1;i<=m;i++){
        if (!l[a[i]]) l[a[i]]=i;
        r[a[i]]=i;
    }
    for (int i=1;i<n;i++){
        if (!l[i]||!l[i+1]) ans+=2;
        else if (r[i]<l[i+1]||r[i+1]<l[i]) ans++;
    }
    for (int i=1;i<=n;i++) if (!l[i]) ans++;
    cout << ans << endl;
}