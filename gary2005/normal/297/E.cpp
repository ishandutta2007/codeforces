/**
 *    author:  gary
 *    created: 21.01.2022 10:02:35
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
vector<mp> seg;
int n;
const int MAXN=(1<<18)+1;
int cnt[MAXN],cnt2[MAXN];
map<mp,int> id;
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
bool cmp(mp A,mp B){
    return A.SEC>B.SEC;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    BIT tree;
    cin>>n;
    seg.resize(n);
    rep(i,n) cin>>seg[i].FIR>>seg[i].SEC,seg[i]=II(min(seg[i].FIR,seg[i].SEC),max(seg[i].FIR,seg[i].SEC)),id[seg[i]]=i+1;
    sort(ALL(seg));
    rep(i,n){
        cnt[id[seg[i]]]+=tree.query(seg[i].FIR,seg[i].SEC);
        tree.add(seg[i].SEC,1);
    }
    tree.clear();
    reverse(ALL(seg));
    rep(i,n){
        cnt2[id[seg[i]]]+=tree.query(seg[i].FIR,seg[i].SEC);
        tree.add(seg[i].SEC,1);
    }
    tree.clear();
    sort(ALL(seg),cmp);
    rep(i,n){
        cnt[id[seg[i]]]+=tree.query(seg[i].FIR,seg[i].SEC);
        tree.add(seg[i].FIR,1);
    }
    LL answer=1ll*n*(n-1)*(n-2)/6;
    LL cnt1=0,cnt3=0;
    rb(i,1,n) cnt1+=1ll*(n-1-cnt[i]-cnt2[i])*cnt2[i];
    rb(i,1,n) cnt3+=1ll*cnt[i]*(n-1-cnt[i]);
    cout<<answer-cnt1-cnt3/2<<endl;
    return 0;
}