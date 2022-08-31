#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1e6+100;
const int M=998244353;
int n,m,f[maxn],nf[maxn],inv[maxn],tot,q,ans;
char s[maxn];
int C(int x,int y){
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void init(){
    f[0]=nf[0]=1; inv[1]=1;
    for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
int main(){
    init();
    scanf("%d%d",&n,&m); q=0;
    scanf("%s",s);
    for (int i=1;i<n;i+=2) {
        if (s[i]=='w') s[i]='b';
        else if (s[i]=='b') s[i]='w';
    }
    for (int i=0;i<n;i++){
        if (s[i]=='w') ++tot;
        else if (s[i]=='b') --tot;
        else q++;
    }
    for (int i=0;i<=q;i++){
        int sum=tot+i-(q-i);
        if (sum%4) continue;
        add(ans,1ll*C(q,i)*abs(sum/4)%M);
    }
    for (int i=0;i<q-1;i++) ans=1ll*ans*inv[2]%M;
    printf("%d\n",ans);
    return 0;
}