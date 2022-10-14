/**
 *    author:  gary
 *    created: 24.11.2021 20:18:56
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
int n,a[MAXN];
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    int answer=0;
    rb(i,1,n){
        if(a[i]==a[i-1]) continue;
        int cnt=1;
        LL tmp=a[i];
        int pre=i;
        while(tmp<=a[n]&&pre<n){
            // cout<<tmp<<endl;
            auto ite=lower_bound(a+pre+1,a+n+1,tmp);
            pre=ite-a;
            tmp=*ite;
            cnt++;
            // cout<<i<<' '<<cnt<<" "<<tmp<<" "<<pre<<endl;
            tmp=tmp-a[i]+tmp;
        }
        check_max(answer,cnt);
    }
    cout<<n-answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}