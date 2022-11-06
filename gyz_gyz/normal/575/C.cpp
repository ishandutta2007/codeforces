#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define CH (ch=getchar())
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,V)     for(__typeof(*V.begin()) i:  V)
#define For(i,a,b)   for(int i=(int)a;i<=(int)b;i++)
#define Rep(i,a,b)   for(int i=(int)a;i< (int)b;i++)
#define Forn(i,a,b)  for(int i=(int)a;i>=(int)b;i--)
#define pend(x)      ((x)=='\n'||(x)=='\r'||(x)=='\t'||(x)==' ')
using namespace std;
typedef double      db;
typedef long long   ll;
const   int N=25;
const   int mo=1000000007;
const   int inf=(int)1e9;

inline int IN(){
    char ch;CH; int f=0,x=0;
    for(;pend(ch);CH); if(ch=='-')f=1,CH;
    for(;!pend(ch);CH) x=x*10+ch-'0';
    return (f)?(-x):(x);
}

int Pow(int x,int y,int p){
    int A=1;
    for(;y;y>>=1,x=(ll)x*x%p) if(y&1) A=(ll)A*x%p;
    return A;
}

int n,m,laba[N],labb[N],visa[N],visb[N],tim,mat[N],ans;
int w[N][N],a[N][N],b[N][N],c[N][N],tot_done;

bool extend(int x){
    if(!x) return 1;
    visa[x]=tim;
    For(i,1,n){
        if(visb[i]!=tim&&laba[x]+labb[i]==w[x][i]){
            visb[i]=tim;
            if(extend(mat[i])){
                mat[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

void change(){
    int delta=inf;
    For(i,1,n) if(visa[i]==tim)
    For(j,1,n) if(visb[j]!=tim){
        delta=min(delta,laba[i]+labb[j]-w[i][j]);
    }
    
    For(i,1,n) if(visa[i]==tim) laba[i]-=delta;
    For(i,1,n) if(visb[i]==tim) labb[i]+=delta;
}

int KM(){
    For(i,1,n) visa[i]=visb[i]=mat[i]=0;
    For(i,1,n) laba[i]=w[i][0],labb[i]=0;
    tim=0;
    For(i,1,n){
        for(;;){
            ++tim;
            if(extend(i))break;
            change();
        }
    }
    
    int re=0;
    For(i,1,n) re+=w[mat[i]][i];
    return re;
}

void dfs(int x,int cnt){
    int now=KM();
    if(now<=ans) return;
    if(x==n){
        ans=now;
        return;
    }
    ++tot_done;
    if(tot_done>=1e5)return;
    ++x;
    if(m-cnt<n-x+1){
        For(i,0,n) w[x][i]=a[x][i];
        dfs(x,cnt);
    }
    if(cnt<m){
        For(i,0,n) w[x][i]=b[x][i];
        dfs(x,cnt+1);
    }
    For(i,0,n) w[x][i]=c[x][i];
}

int main(){
    scanf("%d",&n); m=n>>1;
    For(i,1,n) For(j,1,n){
        a[i][j]=IN();
        a[i][0]=max(a[i][0],a[i][j]);
    }
    For(i,1,n) For(j,1,n){
        b[i][j]=IN();
        b[i][0]=max(b[i][0],b[i][j]);
    }
    For(i,1,n) For(j,1,n){
        w[i][j]=c[i][j]=max(a[i][j],b[i][j]);
        w[i][0]=c[i][0]=max(w[i][0],c[i][j]);
    }
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}