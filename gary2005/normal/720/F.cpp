/**
 *    author:  gary
 *    created: 11.02.2022 13:18:12
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
const int MAXN=1e5+10;
int n;
LL k;
int a[MAXN],id[MAXN],cc[MAXN];
LL pre[MAXN];
vector<LL> ls;
template <class T>
struct RMQ { // 0-based
  vector<vector<T>> rmq;
  T kInf = numeric_limits<T>::max();
  void build(const vector<T>& V) {
    int n = V.size(), on = 1, dep = 1;
    while (on < n) on *= 2, ++dep;
    rmq.assign(dep, V);
 
    for (int i = 0; i < dep - 1; ++i)
      for (int j = 0; j < n; ++j) {
        rmq[i + 1][j] = max(rmq[i][j], rmq[i][min(n - 1, j + (1 << i))]);
      }
  }
  T query(int a, int b) { // [a, b)
    if (b <= a) return kInf;
    int dep = 31 - __builtin_clz(b - a); // log(b - a)
    return max(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};
struct BIT_ADD{
    int tree[MAXN];
    BIT_ADD(){memset(tree,0,sizeof(tree));}
    void add(int pos){
        while(pos<MAXN) tree[pos]++,pos+=pos&-pos;
    }
    int query(int pos){
        int s=0;
        while(pos) s+=tree[pos],pos-=pos&-pos;
        return s;
    }
};
struct BIT_MAX{
    int tree[MAXN];
    BIT_MAX(){memset(tree,-63,sizeof(tree));}
    void chk(int pos,int val){
        while(pos<MAXN) check_max(tree[pos],val),pos+=pos&-pos;
    }
    int query(int pos){
        int s=-INF;
        while(pos) check_max(s,tree[pos]),pos-=pos&-pos;
        return s;
    }
};
struct BIT_SUM{
    LL tree[MAXN];
    BIT_SUM(){memset(tree,0,sizeof(tree));}
    void add(int pos,LL val){
        while(pos<MAXN) tree[pos]+=val,pos+=pos&-pos;
    }
    LL query(int pos){
        LL s=0;
        while(pos) s+=tree[pos],pos-=pos&-pos;
        return s;
    }
};
RMQ<LL> preneg,prepos;
pair<LL,LL> chk(LL x){
    memset(cc,0,sizeof(cc));
    BIT_ADD t1;
    BIT_MAX t2;
    BIT_SUM t3;
    pair<LL,LL> rest;
    rest=II(0,0);
    rl(i,n,1){
        t1.add(ls.size()-id[i]+1);
        t2.chk(ls.size()-id[i]+1,i);
        t3.add(ls.size()-id[i]+1,pre[i]);
        int j=lower_bound(ALL(ls),pre[i-1]-x)-ls.begin()+1;
        int c=t1.query(ls.size()-j+1);
        LL v=t3.query(ls.size()-j+1);
        int mx=t2.query(ls.size()-j+1);
        rest.second+=c;
        rest.first+=(v-pre[i-1]*c)+x*c;
        if(mx>=0) cc[i]++,cc[mx+1]--;
        // cout<<i<<' '<<mx<<' '<<c<<" "<<rest.first<<" "<<v<<endl;
    }
    vector<int> p;
    rb(i,1,n) cc[i]+=cc[i-1];
    rb(i,1,n) if(!cc[i]) p.PB(i);
    if(p.size()){
        int l,r;
        l=p[0];
        r=p.back();
        rest.second++;
        rest.first+=preneg.query(0,l);
        rest.first+=prepos.query(r,n+1)+x;
        rep(i,p.size()-1){
            l=p[i],r=p[i+1];
            LL tmp=prepos.query(l,r)+preneg.query(l,r)+x;
            if(tmp>=0) rest.second++,rest.first+=tmp;
        }
    }
    return rest;
}
int main(){
    // freopen("test.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    rb(i,1,n) cin>>a[i],pre[i]=pre[i-1]+a[i];
    vector<LL> posi(n+1,0),neg(n+1,0);
    rb(i,0,n) posi[i]=pre[i],neg[i]=-pre[i];
    preneg.build(neg);
    prepos.build(posi);
    rb(i,0,n) ls.PB(pre[i]);
    sort(ALL(ls));
    ls.erase(unique(ALL(ls)),ls.end());
    rb(i,0,n) id[i]=lower_bound(ALL(ls),pre[i])-ls.begin()+1;
    // cout<<chk(1).first<<endl;
    // return 0;
    LL l=-6e9,r=6e9;
    while(l<r){
        LL mid=l+(r-l+1)/2-1;
        if(chk(mid).second<k) l=mid+1;
        else r=mid;
    }
    // cout<<l<<endl;
    cout<<chk(l).first-k*l<<endl;
    return 0;
}