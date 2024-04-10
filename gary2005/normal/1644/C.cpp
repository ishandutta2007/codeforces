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
int a[5005];
int mx[5005];
void solve(){
    int n,x;
    cin>>n>>x;
    rb(i,1,n) cin>>a[i];
    rb(i,1,n) a[i]+=a[i-1];
    rb(i,0,n) mx[i]=-2e9;
    mx[0]=0;
    rb(i,1,n) rb(j,i,n) check_max(mx[j-i+1],a[j]-a[i-1]);
    rb(k,0,n){
        int answer=-2e9;
        rb(j,0,n){
            check_max(answer,x*min(j,k)+mx[j]);
        }
        cout<<answer<<" ";
    }
    cout<<endl;
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