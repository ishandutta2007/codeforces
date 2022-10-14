/**
 *    author:  gary
 *    created: 16.07.2022 22:28:21
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
int cnt0;
map<int,int> M;
map<int,int> nw;
int solve(int n){
    if(M.empty()) return 0;
    if(n==1){
        for(auto it:M) return it.first;
    }
    int x=cnt0!=0;
    int pre=(cnt0==0? -1:0);
    for(auto it:M) cnt0+=it.second-1;
    cnt0-=x;
    nw.clear();
    for(auto it:M){
        if(pre!=-1) nw[it.first-pre]++;
        pre=it.first;
    }
    M.swap(nw);
    return solve(n-1);
}
void solve(){
    int n;
    cin>>n;
    M.clear();
    cnt0=0;
    rb(i,1,n) {
        int ai;
        cin>>ai;
        if(ai==0) cnt0++;
        else    
        M[ai]++;
    }
    cout<<solve(n)<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}