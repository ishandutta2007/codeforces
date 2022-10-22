/**
 *    author:  gary
 *    created: 31.07.2022 21:47:45
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<LL> > mat(n,vector<LL> (m,0));
    vector<LL> s(n,0);
    rep(i,n) rep(j,m) cin>>mat[i][j],s[i]+=mat[i][j]*j;
    LL z=s[0]+s[1]+s[2]-max(max(s[0],s[1]),s[2])-min(min(s[0],s[1]),s[2]);
    rep(i,n){
        if(s[i]!=z){
            cout<<i+1<<" "<<s[i]-z<<'\n';
            return ;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}