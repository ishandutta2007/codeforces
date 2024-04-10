#include<bits/stdc++.h>
#define M 1000000007
#define maxn 250000

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],p[maxn],q[maxn],c[maxn],n,k,g,f;

ll pow_(ll x,ll y)
{
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    if (n==1) {cout << a[1] << endl; return 0;}
    if (n&1){
        for (int i=1;i<n;i++) b[i]=a[i]+a[i+1]*(i&1?1:-1);
        for (int i=1;i<n;i++) a[i]=(M+b[i]%M)%M;
        n--;
    }
    p[0]=q[0]=1; n=n/2-1;
    for (int i=1;i<=n;i++) p[i]=p[i-1]*i%M,q[i]=pow_(p[i],M-2);
    for (int i=0;i<=n;i++) c[i]=p[n]*q[i]%M *q[n-i]%M;
    for (int i=0;i<=n;i++) (f+=a[i*2+1]*c[i])%=M,(g+=a[i*2+2]*c[i])%=M;
    if (n&1) cout << (f+M-g)%M; else cout << (f+g)%M;
    return 0;
}