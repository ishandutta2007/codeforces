/**
 *    author:  gary
 *    created: 26.05.2022 01:33:04
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
int pre[200000+20];
int tor[200000+20],tol[200000+20];
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    pre[0]=0;
    rep(i,2*n) pre[i+1]=pre[i]+(s[i]=='('? 1:-1);
    if(*min_element(pre,pre+2*n+1)>=0){
        cout<<0<<endl;
        return;
    }
    int L=INF,R=-INF;
    rb(i,0,2*n) if(pre[i]<0) check_min(L,i),check_max(R,i);
    L--;R++;
    // cout<<L<<" "<<R<<endl;
    int L_,R_;
    L_=max_element(pre,pre+L+1)-pre;
    R_=max_element(pre+R,pre+2*n+1)-pre;
    if(pre[L_]+pre[R_]>=*max_element(pre+L_,pre+R_+1)){
        cout<<1<<endl;
        cout<<L_+1<<" "<<R_<<endl;
        return ;
    }
    int mx=max_element(pre,pre+2*n+1)-pre;
    cout<<2<<endl;
    cout<<1<<' '<<mx<<endl;
    cout<<mx+1<<' '<<2*n<<endl;
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