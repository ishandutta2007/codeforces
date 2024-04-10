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
string s; 
int f[26];
void solve(){
    cin>>s;
    rep(i,0,26) f[i]=hell;
    rep(i,0,sz(s)){
    	if(f[s[i]-'a']==hell) f[s[i]-'a']=i;
    }
    rep(i,0,sz(s)){
    	bool win=0;
    	rep(j,0,s[i]-'a'){
    		if(f[j]<i) win=1;
    	}
    	if(win) cout<<"Ann"<<endl;
    	else cout<<"Mike"<<endl;
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