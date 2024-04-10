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

void solve(){
    string s;
    cin>>s;
    vii v;
    rep(i,0,sz(s)){
    	if(sz(v)==0 or s[i]-'a'!=v.back().x) v.pb({s[i]-'a',1});
    	else v.back().y++;
    }
    set<int> st;
    for(auto i:v) if(i.y%2) st.insert(i.x);
    for(auto i:st) cout<<(char)(i+'a');
	cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}