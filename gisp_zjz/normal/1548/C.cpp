#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=3e6+10;
const int M=1000000007;
int n,inv[maxn],f[maxn],nf[maxn],a[maxn][3],q;
int C(int x,int y){
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
void init(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
void sub(int &x,int y){x-=y;if(x<0)x+=M;}
int main(){
    init();
    scanf("%d%d",&n,&q);
    a[0][0]=n; a[0][1]=n; a[0][2]=n+1;
    for (int i=1;i<=n*3;i++){
        int res=C(n*3+1,i+1);
        sub(res,a[i-1][0]);
        sub(res,a[i-1][0]);
        sub(res,a[i-1][1]);
        a[i][0]=1ll*res*inv[3]%M;
        a[i][1]=(a[i][0]+a[i-1][0])%M;
        a[i][2]=(a[i][1]+a[i-1][1])%M;
    }
    while (q--){
        int x; scanf("%d",&x);
        printf("%d\n",a[x][2]);
    }
    return 0;
}