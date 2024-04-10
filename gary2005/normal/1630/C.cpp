/**
 *    author:  gary
 *    created: 27.01.2022 22:29:17
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
int a[200000+50],l[200000+20],r[200000+20],to[200000+20];
int answer=0;
    int n;
void solve(int i){
    if(i>n) return ;
    // cout<<i<<' '<<to[i]<<endl;
    assert(to[i]);
    if(to[i]==i){
        answer++;
        solve(i+1);
    }
    else{
        answer+=2;
        int p=to[i];
        while(true){
            if(to[p-1]>p){
                p=to[p-1];
                answer++;
            }
            else break;
        }
        solve(p+1);
    }
}
void solve(){
    cin>>n;
    rb(i,1,n) l[i]=r[i]=-1;
    rb(i,1,n) cin>>a[i];
    rb(i,1,n){
        if(l[a[i]]==-1) l[a[i]]=i;
        r[a[i]]=i;
    }
    rb(i,1,n) if(l[a[i]]==i) to[i]=r[a[i]];
    // int answer=0;
    vector<mp> seg;
    rb(i,1,n) to[i]=max(to[i],to[i-1]);
    // cout<<to[4]<<" "<<endl;
    // int j=0;
    // rep(i,seg.size()){

    // }
    solve(1);
    cout<<n-answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--) solve();
    return 0;
}