#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k;
string s,ss;
void solve(){
    cin>>n>>k>>s;
    for(auto i:s){
        if(i=='R') ss+='1';
        else ss+='0';
    }
    swap(s,ss);
    int ones=0,invs=0;
    for(auto i:s){
        if(i=='1') ones++;
        else invs+=ones;
    }
    if(k>invs){
        cout<<-1<<endl;
        return;
    }
    vector<vi> ans;
    while(invs){
        vi candids;
        rep(i,0,n-1){
            if(s[i]=='1' and s[i+1]=='0'){
                candids.pb(i);
            }
        }
        if(invs-sz(candids)+1+sz(ans)<k){
            int del=invs+1+sz(ans)-k;
            if(del>0 and del<sz(candids)) candids.resize(del);
            else{
                cout<<-1<<endl;
                return;
            }
            ans.pb(candids);
            for(auto i:candids) swap(s[i],s[i+1]);
            rep(i,0,n){
                if(s[i]=='0'){
                    for(int j=i;j>0;j--){
                        if(s[j-1]=='1'){
                            swap(s[j],s[j-1]);
                            ans.pb({j-1});
                        }
                        else break;
                    }
                }
            }
            break;
        }
        else{
            ans.pb(candids);
            for(auto i:candids) swap(s[i],s[i+1]);
        }
        invs-=sz(ans.back());
    }
    if(sz(ans)!=k) cout<<-1<<endl;
    else{
        for(auto i:ans){
            cout<<sz(i)<<" ";
            assert(sz(i));
            for(auto j:i) cout<<j+1<<" ";
            cout<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}