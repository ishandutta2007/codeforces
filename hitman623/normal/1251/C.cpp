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
vi f[2];
void solve(){
	string ans;
	cin>>s;
	f[0].clear();
	f[1].clear();
	rep(i,0,sz(s)) f[(s[i]-'0')%2].pb(i);
	int p1=0,p2=0;
	while(p1<sz(f[0]) and p2<sz(f[1])){
		if(s[f[0][p1]]<s[f[1][p2]]) ans+=s[f[0][p1++]];
		else ans+=s[f[1][p2++]];
	}
	while(p1<sz(f[0])) ans+=s[f[0][p1++]];
	while(p2<sz(f[1])) ans+=s[f[1][p2++]];
	cout<<ans<<endl;
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