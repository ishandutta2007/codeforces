/**
 *    author:  gary
 *    created: 19.05.2022 23:04:05
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
    cin>>n>>k;
    map<int,int> cnt;
    map<int,int> id;
    rep(i,n){
        int ai;
        cin>>ai;
        cnt[ai]++;
    }
    int tmp=0;
    int c=0;
    rb(x,0,n){
        if(x>=1){
            c+=cnt.find(x-1)==cnt.end();
            if(c>k) break;
        }
        tmp=x;
    }
    vector<int> v;
    for(auto it:cnt) if(it.first>=tmp) v.PB(it.second);
    sort(ALL(v));
    reverse(ALL(v));
    while (v.size()&&v.back()<=k)
    {
        k-=v.back();
        v.pop_back();
    }
    cout<<v.size()<<endl;
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