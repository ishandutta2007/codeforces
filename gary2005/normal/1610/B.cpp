/**
 *    author:  gary
 *    created: 24.11.2021 19:09:02
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
int n,a[200000+20];
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    int l=1,r=n;
    while(l<r&&a[l]==a[r]){
        ++l;
        --r;
    }
    if(l>=r){
        cout<<"YES"<<endl;
        return ;
    }
    vector<int> A,B;
    rb(i,1,n){
        if(a[i]!=a[l]) A.PB(a[i]);
        if(a[i]!=a[r]) B.PB(a[i]);
    }
    bool ok[2]={1,1};
    rep(i,A.size()){
        ok[0]&=A[i]==A[A.size()-1-i];
    }
    rep(i,B.size()){
        ok[1]&=B[i]==B[B.size()-1-i];
    }
    if(ok[0]||ok[1]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}