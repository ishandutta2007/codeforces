#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int M=998244353;
const int maxn=4e5+3;
int n,m,f[maxn],nf[maxn],inv[maxn],ans;
int C(int x,int y){
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
void add(int &x,int y){
    x+=y; if (x>=M) x-=M;
}
int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    nf[0]=f[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    cin >> n >> m;
    for (int i=2;i<=n-1;i++) add(ans,1ll*(n-2)*C(n-3,i-2)%M);
    cout << 1ll*ans*C(m,n-1)%M << endl;
}