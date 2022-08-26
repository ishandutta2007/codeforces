#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int M=998244353;
int n,ans,p[maxn],a[maxn];
int main(){
    cin >> n;
    p[0]=1; for (int i=1;i<=n;i++) p[i]=p[i-1]*2%M;
    for (int i=1;i<=n;i++)
        for (int j=1;j*i<=n;j++)
            a[i*j]++;
    ans=0;
    for (int i=1;i<n;i++) ans=(1ll*a[i]*p[n-1-i]+ans)%M;
    ans=(ans+a[n])%M;
    cout << ans << endl;
}