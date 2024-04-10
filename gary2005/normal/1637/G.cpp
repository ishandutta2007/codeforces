/**
 *    author:  gary
 *    created: 12.02.2022 22:26:50
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
vector<int> solve(int n,vector<mp> &ans){
    if(n<=2){
        vector<int> v;
        rb(i,1,n) v.PB(i);
        return v;
    }
    int x=1;
    while(__builtin_popcount(x+n)!=1) x++;
    int y=n;
    int z=x;
    vector<int> v;
    while(x<y){
        v.PB(x+y);
        ans.PB(II(x,y));
        x++,y--;
    }
    if(x==y) v.PB(x);
    x=z;
    vector<mp> tmp;
    vector<int> A,B;
    A=solve((n-x)/2,tmp);
    for(auto &it:tmp) it.first<<=1,it.second<<=1;
    for(auto it:tmp) ans.PB(it);
    B=solve(x-1,ans);
    for(auto it:A) v.PB(it*2);
    for(auto it:B) v.PB(it);
    return v;
}
void solve2(vector<int> v,vector<mp> &ans,int n){
    sort(ALL(v));
    if(v[0]){
        rep(i,v.size()-1){
            if(v[i]==v[i+1]&&v[i]<n){
                ans.PB(II(v[i],v[i+1]));
                v[i]<<=1;
                v[i+1]=0;
            }
        }
    }
    for(auto it:v){
        if(it){
            while(it<n){
                ans.PB(II(it,0));
                ans.PB(II(it,it));
                it*=2;
            }
        }
    }
    while(__builtin_popcount(n)!=1) n++;
    for(auto it:v){
        if(!it){
            ans.PB(II(it,n));
        }
    }
}
void solve(){
    int n;
    cin>>n;
    if(n==2){
        cout<<-1<<endl;
        return ;
    }
    vector<mp> ans;
    auto tmp=solve(n,ans);
    // for(auto it:tmp) cout<<it<<",";
    // cout<<endl;
    solve2(tmp,ans,n);
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
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