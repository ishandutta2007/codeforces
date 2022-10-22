/**
 *    author:  gary
 *    created: 12.09.2021 22:33:05
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
const int MAXN=2e5+1;
const int N=1<<19;
struct SGT{
    int tree[N+N];
    SGT(){
        memset(tree,0,sizeof(tree));
    }
    void modify(int pos,int val){
        pos+=N-1;
        tree[pos]=val;
        pos>>=1;
        while(pos){
            tree[pos]=min(tree[pos<<1],tree[pos<<1|1]);
            pos>>=1;
        }
    }
    int query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return INF;
        if(r<=b&&l>=a) return tree[now];
        int mid=(l+r)>>1;
        return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
}sgt;
int n,m,a[MAXN],l[MAXN],r[MAXN];
LL dp[MAXN][2];
int id[MAXN];
vector<int> ls;
int gt(int x){
    return lower_bound(ALL(ls),x)-ls.begin()+1;
}
bool cmp(int x,int y){
    return r[x]-l[x]<r[y]-l[y];
}
int pt=0;
vector<mp> can;
vector<mp> get(int x){
    vector<mp> rest;
    while(pt<can.size()&&can[pt].SEC<x){
        rest.PB(can[pt++]);
    }
    return rest;
}
void solve(){
    can.clear();
    pt=0;
    ls.clear();
    scanf("%d%d",&n,&m);
    rb(i,0,n) dp[i][0]=dp[i][1]=1e18;
    rb(i,1,n){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    rb(i,1,m){
        scanf("%d%d",&l[i],&r[i]);
        ls.PB(l[i]);
        ls.PB(r[i]);
    }
    sort(ALL(ls));
    ls.erase(unique(ALL(ls)),ls.end());
    rb(i,1,ls.size()){
        sgt.modify(i,INF);
    }
    rb(i,1,m) id[i]=i;
    sort(id+1,id+1+m,cmp);
    rb(i_,1,m){
        int i=id[i_];
        if(a[n]>=l[i]){
            int x=a[lower_bound(a+1,a+1+n,l[i])-a];
            if(x<=r[i]) continue;
        }
        int L,R;
        L=gt(l[i]);
        R=gt(r[i]);
        if(sgt.query(L,R+1)<=r[i]){
            continue;
        }
        can.PB(II(l[i],r[i]));
        sgt.modify(L,r[i]);
    }
    sort(ALL(can));
    vector<mp> st=get(a[1]);
    if(st.empty()){
        dp[1][0]=dp[1][1]=0;
    }
    else{
        dp[1][0]=a[1]-st[0].SEC;
        dp[1][1]=2ll*(a[1]-st[0].SEC);
    }
    rb(i,2,n){
        vector<mp> Tmp=get(a[i]);
        vector<int> AA,BB;
        AA.PB(a[i-1]);
        BB.PB(a[i]);
        for(auto it:Tmp) AA.PB(it.FIR),BB.PB(it.SEC);
        AA.PB(a[i-1]);
        BB.PB(a[i]);
        rep(j,AA.size()-1){
            check_min(dp[i][0],dp[i-1][0]+2ll*(AA[j]-a[i-1])+1ll*(a[i]-BB[j+1]));
            check_min(dp[i][0],dp[i-1][1]+1ll*(AA[j]-a[i-1])+1ll*(a[i]-BB[j+1]));
            check_min(dp[i][1],dp[i-1][0]+2ll*(AA[j]-a[i-1])+2ll*(a[i]-BB[j+1]));
            check_min(dp[i][1],dp[i-1][1]+1ll*(AA[j]-a[i-1])+2ll*(a[i]-BB[j+1]));
        }
    }
    st=get(INF);
    LL answer=1e18;
    if(st.empty()) answer=dp[n][0];
    else{
        answer=min(answer,dp[n][0]+2ll*(st.back().FIR-a[n]));
        answer=min(answer,dp[n][1]+1ll*(st.back().FIR-a[n]));   
    }
    cout<<answer<<endl;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();    
    return 0;
}