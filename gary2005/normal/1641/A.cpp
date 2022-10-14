/**
 *    author:  gary
 *    created: 23.02.2022 18:08:45
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
int n,x;
int a[MAXN];
void solve(){
    cin>>n>>x;
    rb(i,1,n) cin>>a[i];
    map<LL,int,greater<LL> > M;
    rb(i,1,n) M[a[i]]++;
    for(auto ite=M.begin();ite!=M.end();ite++){
        int now=ite->first;
        LL nx=1ll*now*x;
        int mn=min(M[nx],ite->second);
        M[nx]-=mn;
        ite->second-=mn;
    }
    int answer=0;
    for(auto ite=M.begin();ite!=M.end();ite++) answer+=ite->second;
    cout<<answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}