/**
 *    author:  gary
 *    created: 22.02.2022 22:34:31
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
const int MOD=998244353;
int n,m,k,q;
void solve(){
    cin>>n>>m>>k>>q;
    vector<mp> v;
    rb(i,1,q){
        int x,y;
        cin>>x>>y;
        v.PB(II(x,y));
    }
    reverse(ALL(v));
    set<mp> se;
    set<int> col,row;
    int cnt=0;
    for(auto it:v){
        if(se.find(it)!=se.end()) continue;
        if(col.find(it.second)!=col.end()&&row.find(it.first)!=row.end()) continue;
        if(row.size()==n||col.size()==m) continue;
        col.insert(it.second);
        row.insert(it.first);
        se.insert(it);
        cnt++;
    }
    if(n==1||m==1) cnt=1;
    int answer=1;
    rb(i,1,cnt) answer=1ll*k*answer%MOD;
    cout<<answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}