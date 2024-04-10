#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=5e5+10;
int f[maxn],nf[maxn],inv[maxn],_,n,m,p[maxn],a[maxn],b[maxn];
int A[maxn],B[maxn];
set<int> s;
const int M=998244353;
int C(int x,int y){
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
int F(int x,int y){//a1+...+ax = y
    return C(x-1+y,y);
}
void m1(int x,int y){
    while (x<maxn) A[x]+=y,x+=x&(-x);
}
int q0(int x){
    int ret=0;
    while (x) ret+=A[x],x-=x&(-x);
    return ret;
}
int q1(int x){
    int t=18,r=0;
    while (t>0&&A[1<<t]>x) t--;
    for (int i=t;i>=0;i--){
        if (A[r+(1<<i)]<=x){
            r|=1<<i;
            x-=A[r];
        }
    }
    return r;
}
void m2(int x,int y){
    while (x<maxn) B[x]+=y,x+=x&(-x);
}
int q2(int x){
    int t=18,r=0;
    while (t>0&&B[1<<t]>x) t--;
    for (int i=t;i>=0;i--){
        if (B[r+(1<<i)]<=x){
            r|=1<<i;
            x-=B[r];
        }
    }
    return r;
}
int qry(int x){
    if (p[x]) return p[x];
    int c=q0(x);
    return q2(c-1)+1;
}
void init(){
    for (int i=1;i<maxn;i++) m1(i,1),m2(i,1);
    f[0]=nf[0]=1; inv[1]=1;
    for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
int main(){
    init();
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
        for (int i=m;i;i--){
            int x=q1(b[i]-1)+1;
            b[i]=x;
            p[b[i]]=a[i];
            m1(b[i],-1); m2(a[i],-1);
        }
        int t=n-1;
        for (int i=1;i<=m;i++) if (qry(b[i])>qry(b[i]+1)) t--;
        //for (int i=1;i<=n;i++)cout<<qry(i)<<' ';cout<<endl;
        printf("%d\n",F(n+1,t));
        for (int i=1;i<=m;i++) {
            s.insert(b[i]);
            p[b[i]]=0;
            m1(b[i],1); m2(a[i],1);
        }
    }
}