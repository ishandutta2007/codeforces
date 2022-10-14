/**
 *    author:  gary
 *    created: 31.05.2022 22:34:12
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
    int n,k;
    string s;
    cin>>n>>k>>s;
    int f1=-1,f2=-1;
    int ans=0;
    rep(i,s.length()){
        if(s[i]=='1'){
            if(i==0) ans+=10;
            else
            if(i==n-1) ans+=1;
            else ans+=11;
            if(f1==-1) f1=i;
            f2=i;
        }
    }
    if(!ans) cout<<ans<<endl;
    else{
        if(f2!=n-1&&n-1-f2<=k){
            k-=n-1-f2;
            ans-=10;
            if(f2==0) ans++;
            if(f1==f2) f1=n-1;
        }
        if(f1!=n-1&&f1!=0&&f1<=k){
            k-=f1;
            ans-=1;
        }
        cout<<ans<<endl;
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