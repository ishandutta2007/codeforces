/**
 *    author:  gary
 *    created: 27.01.2022 22:29:17
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
int c[200000+20],a[200000+20];
void solve(){
    int n,k;
    cin>>n>>k;
    rb(i,1,n) c[i]=0;
    int l,r;
    l=-INF,r=INF;
    rb(i,1,n){
        cin>>a[i];
        c[a[i]]++;
    }
    int R=0;
    int C=0;
    rb(i,1,n){
        while(R!=n&&C-(n-C)<k){
            R++;
            C+=c[R];
        }
        if(C-(n-C)<k) break;
        if(R-i<r-l) l=i,r=R;
        C-=c[i];
    }
    cout<<l<<" "<<r<<endl;
    vector<mp> ans;
    C=0;
    int pre=0;
    rb(i,1,n){
        if(a[i]<=r&&a[i]>=l){
            C++;
        }
        else{
            C--;
        }
        if(C==ans.size()+1) ans.PB(II(pre+1,i)),pre=i;
        if(ans.size()==k){
            ans.back().second=n;
            break;
        }
    }
    for(auto it:ans) cout<<it.first<<" "<<it.second<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}