/**
 *    author:  gary
 *    created: 20.09.2021 22:34:38
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
void solve(){
    LL a,b,c,m;
    cin>>a>>b>>c>>m;
    LL l,r;
    r=a-1+b-1+c-1;
    LL A[3]={a,b,c};
    sort(A,A+3);
    l=max(0ll,A[2]-A[0]-A[1]-1);
    if(m<=r&&m>=l){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}