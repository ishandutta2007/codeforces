/**
 *    author:  gary
 *    created: 27.03.2022 22:29:41
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
unsigned LL ran[1<<17];
unsigned LL Hash[1<<17][18];
int lg[(1<<17)+1];
unsigned LL query2k(int x,int l,int r){
    return Hash[x^l][lg[(r-l)]];
}
void getseg(int a,int b,int l,int r,vector<mp> &seg){
    if(r<=a||l>=b) return;
    if(r<=b&&l>=a){
        seg.PB(II(l,r));
        return;
    }
    int mid=(l+r)>>1;
    getseg(a,b,l,mid,seg);
    getseg(a,b,mid,r,seg);
}
unsigned LL query(int x,int l,int r,bool debug=0){
    vector<mp> tmp;
    getseg(l,r,0,1<<17,tmp);
    unsigned LL val=0;
    // if(debug) for(auto it:tmp) cout<<it.first<<" "<<it.second<<" "<<lg[(it.second^it.first)]<<endl;
    for(auto it:tmp) val^=query2k(x,it.first,it.second);
    return val;
}
void solve(){
    int l,r;
    cin>>l>>r;
    unsigned LL tmp=0;
    vector<int> a(r-l+1);
    vector<int> can;
    rb(i,l,r) cin>>a[i-l],tmp^=ran[a[i-l]],can.PB(a[i-l]^l);
    for(auto it:can){
        // cout<<it<<' '<<tmp<<' '<<Hash[0][2]<<endl;
        if(query(it,l,r+1,1)==tmp){
            cout<<it<<endl;
            return ;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    SRAND;
    rep(i,18) lg[1<<i]=i;
    rep(mask,1<<17){
        rep(j,70){
            ran[mask]<<=1;
            ran[mask]|=random(2);
        }
    }
    rep(mask,1<<17) Hash[mask][0]=ran[mask];
    rb(j,1,17)
    rep(mask,1<<17) Hash[mask][j]=Hash[mask][j-1]^query(mask,1<<(j-1),1<<j);
    // cout<<(query(0,2,4,1)^Hash[0][1])<<" "<<(Hash[0][1]^Hash[2][1])<<" "<<(ran[0]^ran[1]^ran[2]^ran[3])<<endl;
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}