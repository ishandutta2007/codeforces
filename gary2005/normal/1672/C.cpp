/**
 *    author:  gary
 *    created: 23.04.2022 22:12:01
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
    int L,R;
    L=R=-1;
    rb(i,1,n-1){
        if(a[i]==a[i+1]){
            if(L==-1) L=i;
            R=i;
        }
    }
    if(L==R){
        cout<<0<<endl;
    }
    else{
        if(L==R-1){
            cout<<1<<endl;
        }
        else{
            cout<<R-L-1<<endl;
        }
    }
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