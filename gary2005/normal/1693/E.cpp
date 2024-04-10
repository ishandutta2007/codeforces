/**
 *    author:  gary
 *    created: 18.06.2022 14:01:28
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
const int MAXN=2e5+20;
const int N=1<<18;
int n,a[MAXN],cnt[MAXN],cnt2[MAXN];
struct Node{
    int to[3],ans[3];
    Node(){
        rep(i,3) to[i]=i;
        memset(ans,0,sizeof(ans));
    }
};
Node merge(Node A,Node B){
    Node rest;
    rep(i,3) rest.to[i]=A.to[B.to[i]],rest.ans[i]=B.ans[i]+A.ans[B.to[i]];
    return rest;
}
Node tree[N+N];
void upd(int pos,int typ){
    pos+=N-1;
    tree[pos]=Node();
    rep(f,3) if((typ|f)==3){
        tree[pos].to[f]=0;
        tree[pos].ans[f]=1;
    }
    else{
        tree[pos].to[f]=typ|f;
        tree[pos].ans[f]=0;
    }
    pos>>=1;
    while (pos)
    {
        tree[pos]=merge(tree[pos<<1],tree[pos<<1|1]);
        pos>>=1;
    }
}
Node query(int a,int b,int now=1,int l=1,int r=N+1){
    if(r<=b&&l>=a) return tree[now];
    int mid=(l+r)>>1;
    if(mid>=b) return query(a,b,now<<1,l,mid);
    if(mid<=a) return query(a,b,now<<1|1,mid,r);
    return merge(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>a[i],cnt[a[i]]++;
    LL rest=0;
    rb(i,1,n) if(cnt[i]) upd(i,2);
    rb(i,1,n){
        cnt[a[i]]--;
        if(a[i]) upd(a[i],(cnt2[a[i]]>0)|((cnt[a[i]]>0)<<1));
        if(i>1&&a[i-1]>0) cnt2[a[i-1]]++,upd(a[i-1],(cnt2[a[i-1]]>0)|((cnt[a[i-1]]>0)<<1));
        if(a[i]) rest++;
        if(a[i]>1) rest+=query(1,a[i]).ans[0];
    }
    cout<<rest<<endl;
    return 0;
}