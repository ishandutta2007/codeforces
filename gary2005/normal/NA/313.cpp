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
void solve(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    if(k==n-1){ 
        if(n==4){ cout<<-1<<endl;return;}
        else{
            k--;
            vector<mp> ans;
            ans.PB(II(k,n-1));
            int val=(n-1)^k;
            rep(i,n/2){
                if(i==val) continue;
                if(i==k) continue;
                if(i==0) ans.PB(II(i,val));
                else ans.PB(II(i,(n-1)^i));
            }
            int x,y;
            rep(i,ans.size()) if(i>0){
                if(ans[i].first&1) x=i;
                else y=i;
            }
            swap(ans[x].second,ans[y].second);
            int rest=0;
            for(auto it:ans) cout<<it.first<<" "<<it.second<<endl,rest+=(it.first&it.second);
            assert(rest==n-1);
            return ;
        }
    }
    else if(k==0){
        rep(i,n/2) cout<<i<<" "<<((n-1)^i)<<endl,ans+=(i)&((n-1)^i);
    }
    else{
        cout<<k<<" "<<n-1<<endl;
        ans+=k&(n-1);
        int val=(n-1)^k;
        rep(i,n/2){
            if(i==val) continue;
            if(i==k) continue;
            if(i==0) cout<<i<<' '<<val<<endl,ans+=i&val;
            else cout<<i<<" "<<((n-1)^i)<<endl,ans+=(i)&((n-1)^i);
        }
    }
    assert(ans==k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}