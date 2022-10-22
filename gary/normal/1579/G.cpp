/**
 *    author:  gary
 *    created: 01.10.2021 13:27:53
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
const int MAXN=1e4+1;
int a[MAXN];
int n;
bitset<2002> dp,nex,tmp;
bool check(int len){
    dp.reset();
    rep(i,len+1) dp.set(i);
    tmp.reset();
    rep(i,len+1) tmp.set(i);
    rb(i,1,n){
        nex=dp<<a[i];
        nex|=dp>>a[i];
        dp=nex&tmp;
        if(dp.count()==0) return false;
    }
    return true;
}
void solve(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    int l=1,r=2e3;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}