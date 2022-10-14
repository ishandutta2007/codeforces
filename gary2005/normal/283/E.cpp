/**
 *    author:  gary
 *    created: 18.01.2022 21:53:52
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
const int N=1<<17;
int tree[N+N][2];
bool tag[N+N];
void push_down(int pos){
    if(tag[pos]){
        swap(tree[pos][0],tree[pos][1]);
        if(pos<N){
            tag[pos<<1]^=1;
            tag[pos<<1|1]^=1;
        }
        tag[pos]=0;
    }
}
void push_up(int pos){
    tree[pos][0]=tree[pos<<1][0]+tree[pos<<1|1][0];
    tree[pos][1]=tree[pos<<1][1]+tree[pos<<1|1][1];
}
void upd(int a,int b,int now=1,int l=1,int r=N+1){
    push_down(now);
    if(r<=a||l>=b) return;
    if(r<=b&&l>=a){
        tag[now]^=1;
        push_down(now);
        return;
    }
    int mid=(l+r)>>1;
    upd(a,b,now<<1,l,mid);
    upd(a,b,now<<1|1,mid,r);
    push_up(now);
}
int query(int a,int b,int now=1,int l=1,int r=N+1){
    push_down(now);
    if(r<=a||l>=b) return 0;
    if(r<=b&&l>=a){
        return tree[now][1];
    }
    int mid=(l+r)>>1;
    return query(a,b,now<<1,l,mid)+query(a,b,now<<1|1,mid,r);
}
void build(){
    memset(tree,0,sizeof(tree));
    memset(tag,0,sizeof(tag));
    rb(i,1,N) tree[i+N-1][0]=1;
    rl(i,N-1,1) tree[i][0]=tree[i<<1][0]<<1;
}
const int MAXN=1e5+1;
int n,k;
int a[MAXN],b[MAXN],d[MAXN];
vector<int> gl[MAXN],gr[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    map<int,int> M;
    vector<int> v;
    rb(i,1,n){
        int si;
        cin>>si;
        M[si]=1;
        v.PB(si);
    }
    sort(ALL(v));
    rb(i,1,k){
        cin>>a[i]>>b[i];
        a[i]=lower_bound(ALL(v),a[i])-v.begin()+1;
        b[i]=upper_bound(ALL(v),b[i])-v.begin();
        if(a[i]<b[i]) gl[a[i]].PB(b[i]),gr[b[i]].PB(a[i]);
    }
    rb(i,1,n){
        d[i]=i-1;
    }
    build();
    rb(i,1,n){
        for(auto it:gr[i-1]) upd(it,i);
        for(auto it:gl[i]) upd(i,it+1);
        if(i!=1) d[i]-=query(1,i);
    }
    build();
    rl(i,n,1){
        for(auto it:gr[i]) upd(it,i+1);
        for(auto it:gl[i+1]) upd(i+1,it+1);
        if(i!=n) d[i]+=query(i+1,n+1);
    }
    LL answer=1ll*n*(n-1)*(n-2)/6;
    rb(i,1,n) answer-=1ll*d[i]*(d[i]-1)/2;
    cout<<answer<<endl;
    return 0;
}