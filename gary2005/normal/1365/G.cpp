/**
 *    author:  gary
 *    created: 08.08.2022 14:04:22
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
LL query(vector<int> p){
    if(p.empty()) return 0;
    cout<<"? "<<p.size()<<' ';
    for(auto it:p) cout<<it+1<<" ";
    cout<<endl;
    fflush(stdout);
    LL x;
    cin>>x;
    return x;
}
int n;
int main(){
    cin>>n;
    SRAND;
    vector<bitset<1000> > ask(13);
    int now=0;
    rep(mask,1<<13) if(__builtin_popcount(mask)==6){
        if(now==n) break;
        rep(j,13) if((mask>>j)&1) ask[j][now]=1;
        now++;
    }
    vector<LL> x;
    for(auto it:ask){
        vector<int> v;
        rep(j,n) if(it[j]) v.push_back(j);
        x.push_back(query(v));
    }
    cout<<"! ";
    rep(i,n){
        LL val=0;
        rep(j,ask.size()) if(!ask[j][i]) val|=x[j];
        cout<<val<<" ";
    }
    cout<<endl;
    fflush(stdout);
    return 0;
}