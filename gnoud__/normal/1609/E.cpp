#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define timer 1.0*clock()/CLOCKS_PER_SEC
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=100010;
int n,q,res,sa,sb,sc;
char a[N];
struct oo {
    int T,L,R,mL,mR;
} t[4*N];
void tran(int s) {
    if(t[s].mL) {
        int x=t[s].mL;
        t[2*s].T+=x;
        t[2*s].L+=x;
        t[2*s].mL+=x;
        t[2*s+1].T+=x;
        t[2*s+1].L+=x;
        t[2*s+1].mL+=x;
        t[s].mL=0;
    }
    if(t[s].mR) {
        int x=t[s].mR;
        t[2*s].T+=x;
        t[2*s].R+=x;
        t[2*s].mR+=x;
        t[2*s+1].T+=x;
        t[2*s+1].R+=x;
        t[2*s+1].mR+=x;
        t[s].mR=0;
    }
}
void compe(int s) {
    t[s].T=max({t[2*s].T,t[2*s+1].T,t[2*s].L+t[2*s+1].R});
    t[s].L=max(t[2*s].L,t[2*s+1].L);
    t[s].R=max(t[2*s].R,t[2*s+1].R);
}
void upL(int s,int l,int r,int u,int v,int x) {
    if(l>v||r<u||u>v) return;
    if(l>=u&&r<=v) {
        t[s].T+=x;
        t[s].L+=x;
        t[s].mL+=x;
        return;
    }
    int m=(l+r)/2;
    tran(s);
    upL(2*s,l,m,u,v,x);
    upL(2*s+1,m+1,r,u,v,x);
    compe(s);
}
void upR(int s,int l,int r,int u,int v,int x) {
    if(l>v||r<u||u>v) return;
    if(l>=u&&r<=v) {
        t[s].T+=x;
        t[s].R+=x;
        t[s].mR+=x;
        return;
    }
    int m=(l+r)/2;
    tran(s);
    upR(2*s,l,m,u,v,x);
    upR(2*s+1,m+1,r,u,v,x);
    compe(s);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("1609E.inp","r",stdin);
    cin>>n>>q;
    forinc(i,1,n) {
        cin>>a[i];
        if(a[i]=='a') {
            sa++;
            upL(1,1,n,1,i,1);
        }
        else if(a[i]=='b') {
            sb++;
            upL(1,1,n,i+1,n,1);
            upR(1,1,n,1,i-1,1);
        }
        else if(a[i]=='c') {
            sc++;
            upR(1,1,n,i,n,1);
        }
    }
    while(q--) {
        int i;
        char x;
        cin>>i>>x;
        if(a[i]=='a') {
            sa--;
            upL(1,1,n,1,i,-1);
        }
        else if(a[i]=='b') {
            sb--;
            upL(1,1,n,i+1,n,-1);
            upR(1,1,n,1,i-1,-1);
        }
        else if(a[i]=='c') {
            sc--;
            upR(1,1,n,i,n,-1);
        }
        a[i]=x;
        if(a[i]=='a') {
            sa++;
            upL(1,1,n,1,i,1);
        }
        else if(a[i]=='b') {
            sb++;
            upL(1,1,n,i+1,n,1);
            upR(1,1,n,1,i-1,1);
        }
        else if(a[i]=='c') {
            sc++;
            upR(1,1,n,i,n,1);
        }
        cout<<min({sa,sb,sc,n-t[1].T})<<"\n";
    }
}