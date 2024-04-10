/**
 *    author:  gary
 *    created: 21.02.2022 12:48:10
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MOD=1e9+7;
const int A=998244353;
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
int val[2]={114514,1919810};
const int MAXN=3e5+10;
int pw[MAXN],ipw[MAXN],id[MAXN];
int ha[MAXN],dep[MAXN],fa[MAXN][19],isch[MAXN];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void sub(int &A,int B){
    A-=B;
    if(A<0) A+=MOD;
}
void ADD(int f,int x,bool c){
    isch[x]=c;
    fa[x][0]=f;
    dep[x]=dep[f]+1;
    ha[x]=ha[f]+1ll*pw[dep[x]]*val[isch[x]]%MOD;
    ha[x]%=MOD;
    // cout<<f<<"->"<<x<<' '<<c<<endl;
    rb(i,1,18) fa[x][i]=fa[fa[x][i-1]][i-1];
}
int gethash(int F,int T){
    int HHH=(ha[T]-ha[F]+MOD)%MOD;
    return 1ll*HHH*ipw[dep[F]]%MOD;
}
bool cmp(int x,int y){
    int D=min(dep[x],dep[y]);
    int T=0;
    rl(i,18,0) if((T|(1<<i))<=D){
        int tx,ty;
        tx=fa[x][i];
        ty=fa[y][i];
        if(gethash(tx,x)==gethash(ty,y)){
            x=tx;
            y=ty;
            T|=1<<i;
        }
    }
    if(D==T) return dep[x]<dep[y];
    return isch[x]<isch[y];
}
int to[MAXN];
int sum[MAXN];
bool jump[MAXN];
int n;
string s;
void print(int now){
    if(now==n+1) return ;
    if(jump[now]==0){
        cout<<s[now];
        print(now+1);
    }
    else{
        print(to[now]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    n=s.length();
    s='$'+s;
    pw[0]=ipw[0]=1;
    rb(i,1,n) pw[i]=1ll*pw[i-1]*A%MOD;
    rb(i,1,n) ipw[i]=1ll*ipw[i-1]*inv(A)%MOD;
    id[n+1]=0;
    map<int,int> pre;
    rb(i,1,n) sum[i]=sum[i-1]+(s[i]=='('? 1:-1);
    rl(i,n,1){
        to[i]=-1;
        if(s[i]=='('&&pre.find(sum[i-1])!=pre.end()) to[i]=pre[sum[i-1]]+1;
        pre[sum[i]]=i;
    }
    rl(i,n,1){
        ADD(id[i+1],i,s[i]==')');
        id[i]=i;
        if(to[i]!=-1&&cmp(id[to[i]],id[i])){
            jump[i]=1;
            id[i]=id[to[i]];
        }
    }
    // rb(i,1,n){
    //     cout<<to[i]<<" "<<jump[i]<<endl;
    // }
    print(1);
    return 0;
}