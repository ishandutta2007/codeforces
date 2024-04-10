/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int N=1<<18;
struct segmenttree{
    int sum[N+N];
    int mx[N+N];
    void pu(int now){
        sum[now]=sum[now<<1]+sum[now<<1|1];
        mx[now]=max(mx[now<<1],mx[now<<1|1]+sum[now<<1]);
    }
    segmenttree(){
        rb(i,1,N) sum[i+N-1]=-1,mx[i+N-1]=0;
        rl(i,N-1,1) pu(i);
    }
    void modify(int pos){
        pos+=N-1;
        sum[pos]=mx[pos]=1;
        pos>>=1;
        while(pos){
            pu(pos);
            pos>>=1;
        }
    }
    void clr(int pos){
        pos+=N-1;
        sum[pos]=-1;
        mx[pos]=0;
        pos>>=1;
        while(pos){
            pu(pos);
            pos>>=1;
        }
    }
    mp merge(mp A,mp B){
        mp C;
        C.FIR=A.FIR+B.FIR;
        C.SEC=max(A.SEC,B.SEC+A.FIR);
        return C;
    }
    mp query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return II(0,-INF);
        if(r<=b&&l>=a) return II(sum[now],mx[now]);
        int mid=(l+r)>>1;
        return merge(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
}tree;
const int MAXN=2e5+1;
int n,a[MAXN];
bool vis[MAXN];
void solve(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]),vis[i]=0;
    rb(i,1,n) tree.clr(i);
    vector<mp> v;
    rb(i,1,n) v.PB(II(a[i],i));
    sort(ALL(v));reverse(ALL(v));
    int mn=INF;
    int rest=0;
    int B=n+1;
    rb(i,1,n){
        int pos=v[i-1].SEC;
        vis[pos]=1;
        while(vis[B-1]) --B;
        check_min(mn,pos);
        tree.modify(pos);
        if(mn==n-i+1) continue;
        int Start=tree.query(mn,B).SEC;
        check_max(Start,1);
        if(Start%2!=mn%2) Start++;
        Start--;
        check_max(rest,Start+n-i+1-mn);
    }
    printf("%d\n",rest);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();    
    return 0;
}