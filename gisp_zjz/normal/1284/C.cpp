#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=3e5+3;
int n,M,f[maxn],inv[maxn],nf[maxn],ans;
void add(int &x,int y){x+=y;if (x>=M)x-=M;}

int main(){
    cin >> n >> M;
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    for (int i=1;i<=n;i++) add(ans,1ll*(n-i+1)*(n-i+1)%M*f[i]%M*f[n-i]%M);
    cout << ans << endl;
}