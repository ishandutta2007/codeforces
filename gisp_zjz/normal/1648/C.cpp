#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=998244353;
const int maxn=1e6+10;
int s[maxn],t[maxn],n,m,a[maxn],cnt[maxn];
int inv[maxn],f[maxn],nf[maxn],ans;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
int qry(int x){
    int ret=0; 
    while (x) ret+=a[x],x-=x&(-x);
    return ret;
}
void modify(int x,int y){
    while (x<maxn) a[x]+=y,x+=x&(-x);
}
void init(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    nf[0]=f[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
int main(){
    scanf("%d%d",&n,&m); init();
    for (int i=1;i<=n;i++) scanf("%d",&s[i]);
    for (int i=1;i<=m;i++) scanf("%d",&t[i]);
    for (int i=1;i<=n;i++) cnt[s[i]]++,modify(s[i],1);
    int ncnt=f[n];
    for (int i=1;i<=200000;i++) ncnt=1ll*ncnt*nf[cnt[i]]%M;
    bool flag=1;
    for (int i=1;i<=min(n,m);i++){
        ncnt=1ll*ncnt*inv[n-i+1]%M;
        add(ans,1ll*ncnt*qry(t[i]-1)%M);
        if (cnt[t[i]]){
            ncnt=1ll*ncnt*cnt[t[i]]%M;
            cnt[t[i]]--;
            modify(t[i],-1);
        } else {
            flag=0;
            break;
        }
    }
    if (flag&&n<m) add(ans,1);
    printf("%d\n",ans);
    return 0;
}