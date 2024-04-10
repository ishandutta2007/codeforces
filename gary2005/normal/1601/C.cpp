/**
 *    author:  gary
 *    created: 25.10.2021 14:32:28
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
const int MAXN=1e6+10;
int N;
struct seg
{
    int tree[1<<21],tag[1<<21];
    void buildtree(int n){
        N=1;
        while(N<n) N<<=1;
        rep(i,N+N) tree[i]=tag[i]=0;
    }
    void pd(int now){
        if(now<N) tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now],tree[now<<1]+=tag[now],tree[now<<1|1]+=tag[now];
        tag[now]=0;
    }
    void add(int a,int b,int val,int now,int l,int r){
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a) {
            tree[now]+=val;
            tag[now]+=val;
            return ;
        }
        pd(now);
        int mid=(l+r)>>1;
        add(a,b,val,now<<1,l,mid);
        add(a,b,val,now<<1|1,mid,r);
        tree[now]=min(tree[now<<1],tree[now<<1|1]);
    }
    int query(int a,int b,int now,int l,int r){
        if(r<=a||l>=b) return INF;
        if(r<=b&&l>=a) {
            return tree[now];
        }
        int mid=(l+r)>>1;
        pd(now);
        return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
}sgt;
int n,m,a[MAXN],b[MAXN];
int bit[MAXN];
void add(int pos){
    while(pos<=n){
        bit[pos]++;
        pos+=pos&-pos;
    }
}
int query(int pos){
    int s=0;
    while(pos){
        s+=bit[pos];
        pos-=pos&-pos;
    }
    return s;
}
LL solve2(){
    rb(i,1,n) bit[i]=0,assert(a[i]<=n&&a[i]);
    LL ans=0;
    rb(i,1,n) ans+=i-1-query(a[i]),add(a[i]);
    return ans;
}
inline int read(){
   int x=0;
   char ch=getchar();
   while(ch<'0'||ch>'9'){
       ch=getchar();
   }
   while(ch>='0'&&ch<='9'){
       x=(x<<1)+(x<<3)+(ch^48);
       ch=getchar();
   }
   return x;
}
void solve(){
    scanf("%d%d",&n,&m);
    rb(i,1,n) a[i]=read();
    rb(i,1,m) b[i]=read();
    sgt.buildtree(n+1);
    sort(b+1,b+1+m);
    rb(i,1,n+1){
        sgt.add(i,i+1,i-1,1,1,N+1);
    }
    vector<mp> AA,BB;
    rb(i,1,n) AA.PB(II(a[i],i));
    rb(i,1,n) BB.PB(II(a[i],i));
    sort(ALL(BB));
    reverse(ALL(BB));
    AA=BB;
    LL ans=0;
    rb(i,1,m){
        while(!BB.empty()&&BB.back().FIR<b[i]){
            auto Tmp=BB.back();
            BB.POB();
            sgt.add(1,Tmp.SEC+1,1,1,1,N+1);
        }
        while(!AA.empty()&&AA.back().FIR<=b[i]){
            auto Tmp=AA.back();
            AA.POB();
            sgt.add(Tmp.SEC+1,n+2,-1,1,1,N+1);
        }
        ans+=sgt.query(1,n+2,1,1,N+1);
    }
    vector<int> VV;
    rb(i,1,n) VV.PB(a[i]);
    sort(ALL(VV));
    VV.erase(unique(ALL(VV)),VV.end());
    rb(i,1,n) a[i]=lower_bound(ALL(VV),a[i])-VV.begin()+1;
    printf("%lld\n",ans+solve2());
}
int main(){
//    freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}