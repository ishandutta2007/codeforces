#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=1000000007;
int inv[maxn],_,n,k,ans,f[maxn],nf[maxn];
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
int C(int x,int y){return 1ll*f[x]*nf[y]%M*nf[x-y]%M;}
int solve(int x,int y){if (x<0||y<0) return 0;return C(x+y,y);}
int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    cin >> _;
    while (_--){
        cin >> n >> k; ans=0;
        for (int i=0;k*(i-1)<n;i++){
            add(ans,1ll*nf[n]%M*f[i]%M*f[n-i]%M*solve(n-k*(i-1)-1,i)%M);
        }
        cout << ans << endl;
    }
    return 0;
}