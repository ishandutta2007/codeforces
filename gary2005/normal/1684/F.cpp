/**
 *    author:  gary
 *    created: 19.05.2022 23:21:29
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
const int MAXN=2e5+10;
int n,m;
int bit[MAXN];
void modify(int pos,int val){
    while (pos<=n)
    {
        check_max(bit[pos],val);
        pos+=pos&-pos;
    }
}
int query(int pos){
    int s=0;
    while (pos)
    {
        check_max(s,bit[pos]);
        pos-=pos&-pos;
    }
    return s;
}
vector<int> pos[MAXN];
int a[MAXN];
bool check(int L,int R){
    return query(L)<R;
}
bool check(int i,int l,int r){
    if(i==l-1){
        bool ans=1;
        if(pos[a[i]][0]!=i){
            int t=lower_bound(ALL(pos[a[i]]),i)-pos[a[i]].begin()-1;
            ans&=check(pos[a[i]][t],i);
        }
        int t=upper_bound(ALL(pos[a[i]]),r)-pos[a[i]].begin();
        if(t!=pos[a[i]].size()){
            ans&=check(i,pos[a[i]][t]);
        }
        return ans;
    }
    else{
        bool ans=1;
        if(pos[a[i]][0]<l){
            int t=lower_bound(ALL(pos[a[i]]),l)-pos[a[i]].begin()-1;
            ans&=check(pos[a[i]][t],i);
        }
        int t=upper_bound(ALL(pos[a[i]]),i)-pos[a[i]].begin();
        if(t!=pos[a[i]].size()){
            ans&=check(i,pos[a[i]][t]);
        }
        return ans;
    }
}
void solve(){
    cin>>n>>m;
    rb(i,1,n) bit[i]=0;
    vector<int> lsh;
    rb(i,1,n){
        cin>>a[i];
        lsh.PB(a[i]);
    }
    rb(i,1,m){
        int l,r;
        cin>>l>>r;
        modify(l,r);
    }
    sort(ALL(lsh));
    lsh.erase(unique(ALL(lsh)),lsh.end());
    rep(i,lsh.size()) pos[i].clear();
    rb(i,1,n) a[i]=lower_bound(ALL(lsh),a[i])-lsh.begin(),pos[a[i]].PB(i);
    int L,R;
    L=1,R=n;
    while (L<=R&&check(L,L+1,R)){
        L++;
    }
    if(L>R){
        cout<<0<<endl;
        return ;
    }
    int ans=INF;
    while (L>=1){
        while (R>=L&&check(R,L,R-1)){
            R--;
        }
        check_min(ans,R-L+1);
        L--;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}