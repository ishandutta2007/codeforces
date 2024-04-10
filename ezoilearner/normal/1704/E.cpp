#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}

const int Mod=998244353;
namespace modular{
    int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
    int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
}using namespace modular;

int n,m;
#define Maxn 1005
int in[Maxn],a[Maxn];
int head[Maxn],v[Maxn],nxt[Maxn],tot=0;
inline void add_edge(int s,int e){
    in[e]++;
    tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
}

int Q[Maxn],hd,tl;
void topsort(){
    hd=tl=0;
    rep(u,1,n)
        if(!in[u])Q[tl++]=u;
    while(hd<tl){
        int u=Q[hd++];
        for(int i=head[u];i;i=nxt[i]){
            in[v[i]]--;
            if(!in[v[i]])Q[tl++]=v[i];
        }
    }
}

bool Judge(){
    rep(i,1,n)
        if(a[i])return true;
    return false;
}

void Move(){
    per(i,n-1,0){
        int u=Q[i];
        if(a[u]){
            a[u]--;
            for(int j=head[u];j;j=nxt[j])a[v[j]]++;
        }
    }
}

int main(){
    int t;rd(t);
    while(t--){
        rd(n);rd(m);
        rep(i,1,n)rd(a[i]);
        tot=0;memset(head,0,sizeof(int)*(n+1));
        memset(in,0,sizeof(int)*(n+1));
        while(m--){
            int s,e;rd(s);rd(e);
            add_edge(s,e);
        }
        topsort();
        bool fl=true;
        rep(T,1,n){
            if(!Judge()){
                printf("%d\n",T-1);
                fl=false;
                break;
            }
            Move();
        }
        if(!fl)continue;
        if(!Judge()){
            printf("%d\n",n);
            continue;
        }
        rep(i,1,n)a[i]%=Mod;
        rep(i,0,n-1){
            int u=Q[i];
            for(int j=head[u];j;j=nxt[j])a[v[j]]=add(a[v[j]],a[u]);
        }
        printf("%d\n",add(n,a[Q[n-1]]));
    }
    return 0;
}