/**
 *    author:  gary
 *    created: 22.02.2022 22:49:17
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x=1,y=1;
    int l=s.length();
    if(s[0]=='D'){
        rep(i,l){
            if(s[i]=='R') s[i]='D';
            else s[i]='R';
        }
    }
    rep(i,l){
        if(s[i]=='R') y++;
        else x++;
    }
    int cnt=0;
    rep(i,l){
        if(s[i]=='D') break;
        cnt++;
    }
    if(x==1){
        cout<<n<<endl;
    }
    else{
        if(y==1){
            cout<<n<<endl;
        }
        else{
            LL ban=(1ll*x*y-l-1ll*(x-1)*cnt)-1;
            cout<<1ll*n*n-ban-1ll*(n-1)*cnt<<endl;
        }
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