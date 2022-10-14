/**
 *    author:  gary
 *    created: 14.11.2021 14:01:23
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
const int MAXN=1<<19;
struct SEG{
    int N;
    LL tree[MAXN<<1][2];
    LL tag[MAXN<<1][2];
    void clear(int n){
        N=1;
        while(N<n) N<<=1;
        rb(i,1,N){
            bool p=i&1;
            tree[i+N-1][p]=0;
            tree[i+N-1][p^1]=1e18;
        }
        rep(i,N+N) tag[i][0]=tag[i][1]=0;
        rl(i,N-1,1) tree[i][0]=min(tree[i<<1][0],tree[i<<1|1][0]),tree[i][1]=min(tree[i<<1][1],tree[i<<1|1][1]);
    }
    void pd(int now){
        tree[now][0]+=tag[now][0];
        tree[now][1]+=tag[now][1];
        if(now<N) tag[now<<1][0]+=tag[now][0],tag[now<<1][1]+=tag[now][1],tag[now<<1|1][0]+=tag[now][0],tag[now<<1|1][1]+=tag[now][1];
        tag[now][0]=tag[now][1]=0;
    }
    void add(int from,int p,int val,int now,int l,int r){
        pd(now);
        if(r<=from) return ;
        if(l>=from){
            tag[now][p]+=val;
            pd(now);
            return ;
        }
        int mid=(l+r)>>1;
        add(from,p,val,now<<1,l,mid);
        add(from,p,val,now<<1|1,mid,r);
        tree[now][0]=min(tree[now<<1][0],tree[now<<1|1][0]);
        tree[now][1]=min(tree[now<<1][1],tree[now<<1|1][1]);
    }
    int lower_bound(int now,int l,int r){
        pd(now);
        if(l==r-1){
            if(tree[now][l&1]<0) return l-1;
            else return l;
        }
        int mid=(l+r)>>1;
        pd(now<<1);
        pd(now<<1|1);
        if(min(tree[now<<1][0],tree[now<<1][1])>=0) return lower_bound(now<<1|1,mid,r);
        return lower_bound(now<<1,l,mid);
    }
}sgt;
int n,a[MAXN];
LL pre[MAXN][2];
void solve(){
    scanf("%d",&n);
    sgt.clear(n);
    rb(i,1,n) scanf("%d",&a[i]);
    vector<deque<int> > ve;
    map<LL,int> vv[2];
    rb(i,1,n){
        pre[i][0]=pre[i-1][0];
        pre[i][1]=pre[i-1][1];
        pre[i][i&1]+=a[i];
    }
    LL answer=0;
    rl(i,n,1){
        if(vv[i&1].find(pre[i][i&1]-pre[i][(i&1)^1])==vv[i&1].end()){
            vv[i&1][pre[i][i&1]-pre[i][(i&1)^1]]=ve.size();
            ve.PB(deque<int> (0));
        }
        ve[vv[i&1][pre[i][i&1]-pre[i][(i&1)^1]]].push_front(i);
        sgt.add(i,i&1,a[i],1,1,sgt.N+1);
        sgt.add(i,(i&1)^1,-a[i],1,1,sgt.N+1);
        int p=sgt.lower_bound(1,1,sgt.N+1);
        check_min(p,n);
        auto ite=vv[0].find(pre[i-1][0]-pre[i-1][1]);
        if(ite!=vv[0].end()){
            answer+=upper_bound(ALL(ve[ite->SEC]),p)-(ve[ite->SEC]).begin();
        }
        ite=vv[1].find(pre[i-1][1]-pre[i-1][0]);
        if(ite!=vv[1].end()){
            answer+=upper_bound(ALL(ve[ite->SEC]),p)-(ve[ite->SEC]).begin();
        }
    }
    printf("%lld\n",answer);
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}