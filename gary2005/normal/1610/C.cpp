/**
 *    author:  gary
 *    created: 24.11.2021 19:18:55
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
int n,a[200000+20],b[200000+20];
bool cmp(mp A,mp B){
    return A.SEC<B.SEC;
}
bool check(int x){
    vector<mp> seg;
    rb(i,1,n){
        int l=max(1,x-b[i]);
        if(l>a[i]+1) continue;
        seg.PB(II(l,a[i]+1));
    }
    int p=1;
    int cnt=0;
    for(auto it:seg){
        if(it.SEC>=p&&it.FIR<=p){
            p++;
            cnt++;
        }
    }
    return cnt>=x;
}
void solve(){
    cin>>n;
    rb(i,1,n) cin>>b[i]>>a[i];
    // cout<<check(3)<<endl;
    // exit(0);
    int l=1,r=n+1;
    while (l<r-1)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
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