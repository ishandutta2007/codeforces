/**
 *    author:  gary
 *    created: 12.02.2022 22:26:33
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
const int MAXN=1e5+10;
int n,a[MAXN];
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    if(n==3){
        if(a[2]%2==0) cout<<a[2]/2<<endl;
        else cout<<"-1"<<endl;
        return ;
    }
    if(*max_element(a+2,a+n)==1){
        cout<<"-1\n";
        return ;
    }
    LL answer=0;
    rb(i,2,n-1) answer+=(a[i]+1)/2;
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