/**
 *    author:  gary
 *    created: 28.06.2022 12:01:42
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
const int N=1<<18;
int n,q;
struct node
{
    double dp[3][3];
    node(){
        rep(i,3) rep(j,3) dp[i][j]=-1e18;
    }
};
node merge(node A,node B){
    node C;
    rep(i,3) rep(j,3) {
        if(i==2&&j) continue;
        if(j==2&&i) continue;
        rep(k,3) rep(l,3){
            check_max(C.dp[k][l],A.dp[k][i]+B.dp[j][l]);
        }
    }
    return C;
}
node tree[N+N];
node query(int a,int b,int now=1,int l=1,int r=N+1){
    if(r<=b&&l>=a) return tree[now];
    int mid=(l+r)>>1;
    if(mid>=b) return query(a,b,now<<1,l,mid);
    if(mid<=a) return query(a,b,now<<1|1,mid,r);
    return merge(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    double x,y;
    cin>>x>>y;
    if(x>y) swap(x,y);
    double val[3]={0,1.0/(x+y),1.0/y};
    rb(i,1,n){
        int ai;
        cin>>ai;
        int now=i+N-1;
        tree[now]=node();
        rep(j,3) tree[now].dp[j][j]=val[j]*ai;
    }
    rl(now,N-1,1) tree[now]=merge(tree[now<<1],tree[now<<1|1]);
    while (q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            b+=N-1;
            tree[b]=node();
            rep(j,3) tree[b].dp[j][j]=val[j]*c;
            b>>=1;
            while (b)
            {
                tree[b]=merge(tree[b<<1],tree[b<<1|1]);
                b>>=1;
            }
        }        
        else{
            auto rest=query(b,c+1);
            double ans=-1e18;
            rep(j,3) rep(k,3) check_max(ans,rest.dp[j][k]);
            cout<<fixed<<setprecision(16)<<ans<<'\n';
        }
    }
    
    return 0;
}