#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
const ll INF=2e9;
ll n,a[maxn],d;

int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n%2==1){
        for (int i=1;i<=n;i++) d+=a[i];
        if (d&1) for (int i=1;i<=n;i++) a[i]--;
    }
    for (int i=1;i<=n;i++) a[i]=INF-a[i]; d=0;
    for (int i=1;i<=n;i++) if (i&1) d+=(a[i]&1); else d-=(a[i]&1);
    if (d) puts("NO"); else puts("YES");
    return 0;
}