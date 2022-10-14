/**
 *    author:  gary
 *    created: 25.07.2022 15:51:44
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e3+10;
vector<int> tor[MAXN],tol[MAXN];
int n;
vector<mp> ans;
void construct(int l,int r){
    if(l==r) return;
    int z=tor[l][lower_bound(ALL(tor[l]),r)-tor[l].begin()-1];
    int x=tol[r][upper_bound(ALL(tol[r]),z)-tol[r].begin()-1];
    vector<mp> segs;
    segs.emplace_back(l,z);
    while (z<r){
        ++z;
        int newz=tor[z][upper_bound(ALL(tor[z]),r)-tor[z].begin()-1];
        segs.emplace_back(z,newz);
        z=newz;
    }
    for(auto it:segs) construct(it.first,it.second);
    rb(i,1,segs.size()-2){
        if(i!=segs.size()-2){
            ans.emplace_back(r,segs[i].second);
        }
        else{
            ans.emplace_back(x,segs[i].second);
        }
    }
    ans.emplace_back(x,r);
}
void solve(){
    cin>>n;
    rb(i,1,n) tol[i].clear(),tor[i].clear();
    rb(l,1,n) rb(r,l,n) {
        char c;
        cin>>c;
        if(c=='1') tor[l].push_back(r),tol[r].push_back(l);
    }
    ans.clear();
    construct(1,n);
    for(auto &[u,v]:ans) cout<<u<<" "<<v<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}