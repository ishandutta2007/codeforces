#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int maxn=2000005;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void sub(int &x,int y){x-=y;if(x<0) x+=M;}
int f[maxn],nf[maxn],inv[maxn],n,ans,os[maxn],ls[maxn],rs[maxn],p2[maxn];
char s[maxn];
int C(int x,int y){
    if (y<0||y>x) return 0;
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    nf[0]=f[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    for (int i=1;i<=n;i++) {
        ls[i]=ls[i-1]+(s[i]=='(');
        rs[i]=rs[i-1]+(s[i]==')');
        os[i]=os[i-1]+(s[i]=='?');
    }
    for (int i=1;i<n;i++){
        int a,b,x,y;
        x=ls[i]; y=rs[n]-rs[i];
        a=os[i]; b=os[n]-os[i];
        add(ans,1ll*x*C(a+b,y-x+b)%M);
        add(ans,1ll*a*C(a+b-1,y-x+b-1)%M);
    }
    printf("%d\n",ans);
    return 0;
}