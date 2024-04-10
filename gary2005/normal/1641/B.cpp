/**
 *    author:  gary
 *    created: 09.03.2022 13:08:12
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
const int MAXN=505;
int n,a[MAXN];
vector<mp> ans1;
deque<int> ans2;
deque<int> ans3;
void reverse(int l,int r){
    rl(i,r,l){
        ans1.PB(II(l-1+(r-i),a[i]));
    }
    ans3.push_front((r-l+1)*2);
    reverse(a+l,a+r+1);
}
void solve(int l,int r){
    if(l==r-1){
        ans2.PB(2);
        return ;
    }
    int p=-1;
    rb(i,l+1,r){
        if(a[i]==a[l]){
            p=i;
            break;
        }
    }
    reverse(p,r);
    reverse(l+1,r);
    ans2.PB(2);
    solve(l+2,r);
}
void solve(){
    ans1.clear();
    ans2.clear();
    ans3.clear();
    cin>>n;
    map<int,int> app;
    rb(i,1,n) cin>>a[i],app[a[i]]++;
    for(auto ite=app.begin();ite!=app.end();ite++) if(ite->second%2==1){
        cout<<-1<<endl;
        return ;
    }
    solve(1,n);
    cout<<ans1.size()<<endl;
    for(auto it:ans1) {cout<<it.first<<' '<<it.second<<endl;
    // for(auto it:v){
    //     cout<<it<<' ';
    // }
    // cout<<endl;
    }
    cout<<ans2.size()+ans3.size()<<endl;
    for(auto it:ans2) cout<<it<<' ';
    for(auto it:ans3) cout<<it<<' ';
    cout<<endl;
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