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
int n,q;
map<string,int> mp;
map<string,string> dp;
void solve(){
    cin>>n;
    rep(i,0,n){
        string s;
        cin>>s;
        int l=sz(s);
        set<string> st;
        rep(j,0,l){
            string cur;
            rep(k,j,l){
                cur+=s[k];
                st.insert(cur);
            }
        }
        for(auto j:st){
            mp[j]++;
            if(dp.count(j)==0) dp[j]=s; 
        }
    }
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(mp.count(s)){
            cout<<mp[s]<<" "<<dp[s]<<endl;
        }
        else cout<<0<<" "<<'-'<<endl;
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