#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int M=998244353;
const int inv6=(M+1)/6;
int f[maxn],g[maxn],s[maxn],t[maxn],n,ans;
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
int main(){
    f[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*(f[i-1]+2)*(f[i-1]+1)/2%M;
    for (int i=1;i<maxn;i++) g[i]=(f[i]-f[i-1]+M)%M;
    cin >> n;
    int res=1ll*f[n-1]*(f[n-1]+1)%M*(f[n-1]+2)%M*inv6%M;
    if (n>1) add(res,M-1ll*f[n-2]*(f[n-2]+1)%M*(f[n-2]+2)%M*inv6%M);
    add(res,1ll*f[n-1]*(f[n-1]+1)/2%M);
    if (n>1) add(res,M-1ll*f[n-2]*(f[n-2]+1)/2%M);
    add(ans,2ll*res%M);
    s[0]=t[0]=1;
    for (int i=1;i<=n;i++){
        s[i]=1ll*f[i-1]*(f[i-1]+1)/2%M;
        if (i>1) add(s[i],M-1ll*f[i-2]*(f[i-2]+1)/2%M);
        t[i]=(s[i]+t[i-1])%M;
    }
    for (int i=0;i<=n-1;i++) add(ans,1ll*s[i]*t[n-1-i]%M);
    cout << ans << endl;
    return 0;
}