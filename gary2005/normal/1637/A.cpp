/**
 *    author:  gary
 *    created: 12.02.2022 22:26:26
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
int n,a[10000+10],x[10000+10],y[10000+10];
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    x[1]=a[1];
    rb(i,2,n) x[i]=max(x[i-1],a[i]);
    y[n]=a[n];
    rl(i,n-1,1) y[i]=min(y[i+1],a[i]);
    rb(i,1,n-1){
        if(x[i]>y[i+1]){
            cout<<"YES\n";
            return ;
        }
    }
    cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}