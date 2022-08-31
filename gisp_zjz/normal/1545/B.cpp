#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int f[maxn],nf[maxn],inv[maxn];
int _,n,a[maxn],t,d,b;
char s[maxn];
void init(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
int C(int x,int y){return 1ll*f[x]*nf[y]%M*nf[x-y]%M;}
void solve(){
    scanf("%d%s",&n,s);
    t=0; d=0; b=0;
    for (int i=0;i<n;i++){
        a[++t]=s[i]-'0';
        if (t>=2&&a[t]==1&&a[t-1]==1) t-=2,d++;
    }
    a[t+1]=0;
    for (int i=0;i<=t;i++) if (!a[i]&&!a[i+1]) b++;
    for (int i=1;i<=t;i++) if (a[i]) b++;
    printf("%d\n",C(b-1+d,d));
}
int main(){
    init();
    scanf("%d",&_);
    while (_--) solve();
    return 0;
}