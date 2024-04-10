/**
 *    author:  gary
 *    created: 17.02.2022 14:59:34
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
const int MAXN=500000+20;
int n;
struct BIT{
    int tree[MAXN];
    void clear(){memset(tree,0,sizeof(tree));}
    void add(int pos,int val){
        while(pos<MAXN){tree[pos]+=val;pos+=pos&-pos;}
    }
    int query(int pos){
        int s=0;
        while(pos){
            s+=tree[pos];
            pos-=pos&-pos;
        }
        return s;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
    BIT(){clear();}
};
BIT tree;
int a[MAXN],val[MAXN];
void solve(){
    cin>>n;
    rb(i,1,n) tree.tree[i]=0;
    LL cnt=0;
    rb(i,1,n) cin>>a[i],cnt+=tree.query(a[i]),tree.add(a[i],1);
    cnt=1ll*n*(n-1)/2-cnt;
    rb(i,1,n) tree.tree[i]=0;
    rb(i,1,n) val[i]=-(i-1-2*tree.query(a[i])),tree.add(a[i],1);
    // rb(i,1,n) cout<<val[i]<<" ";
    // cout<<endl;
    rb(i,1,n) tree.tree[i]=0;
    rl(i,n,1) val[i]+=2*tree.query(a[i]),tree.add(a[i],1);
    sort(val+1,val+1+n);
    cout<<cnt<<' ';
    rep(T,n){
        cnt+=val[T+1]-T;
        cout<<cnt<<' ';
    }
    cout<<endl;
}
int main(){
    // cout<<sizeof(tr)/1024/1024<<endl;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}