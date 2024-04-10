/**
 *    author:  gary
 *    created: 20.06.2022 16:15:07
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
const int MAXN=2e5+20;
int a[MAXN],pre[MAXN],last[MAXN];
void solve(){
    int n;
    cin>>n;
    rb(i,1,n){
        char c;
        cin>>c;
        a[i]=c-'0';
        a[i]^=1;
    }
    bool Sorted=true;
    rb(i,2,n) Sorted&=a[i-1]>=a[i];
    if(Sorted) {cout<<"0\n";return;}
    rb(i,1,n) pre[i]=pre[i-1]+(a[i]==1? 1:-1);
    if(pre[n]==pre[0]) {
        cout<<"1\n";
        return ;
    }
    if(pre[n]<pre[0]){
        reverse(a+1,a+1+n);
        rb(i,1,n) a[i]^=1;
        rb(i,1,n) pre[i]=pre[i-1]+(a[i]==1? 1:-1);
    }
    int D=pre[n]-pre[0];
    int Alr=0;
    rb(i,1,n) if(a[i]==1) Alr++;else break;
    if(Alr>=D){
        cout<<"1\n";
        return ;
    }
    int Ans=1;
    rb(i,0,n) if(pre[i]>=0) last[pre[i]]=i;
    int pre=Alr;
    while (Alr<D){
        Ans++;
        int P=last[Alr];
        rb(i,pre+1,P){
            if(a[i]==1) Alr++;
        }
        pre=P;
    }
    cout<<Ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}