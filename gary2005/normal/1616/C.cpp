/**
 *    author:  gary
 *    created: 31.12.2021 21:05:37
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
int a[77];
int n;
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    int ans=n-1;
    rb(i,1,n){
        rb(j,i+1,n){
            double d=((double)(a[j]-a[i]));
            int tmp=0;
            rb(k,1,n){
                tmp+=(a[k]*(j-i)==(d*(k-i)+a[i]*(j-i)));
            }
            tmp=n-tmp;
            check_min(ans,tmp);
        }
    }
    // cout<<"(";
    cout<<ans;
    // cout<<")";
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