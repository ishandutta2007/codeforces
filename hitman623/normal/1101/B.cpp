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
int ans;
void solve(){
	cin>>s;
	int openb=0,openc=0,closeb=sz(s)-1,closec=sz(s)-1;
	while(openb<sz(s) and s[openb]!='[') openb++;
	openc=openb;
	while(openc<sz(s) and s[openc]!=':') openc++;
	while(closeb>=0 and s[closeb]!=']') closeb--;
	closec=closeb;
	while(closec>=0 and s[closec]!=':') closec--;
	if(openb<openc and openc<closec and closec<closeb){
		ans=4;
		rep(i,openc,closec+1){
			if(s[i]=='|') ans++;
		}
		cout<<ans<<endl;
	}	
	else cout<<-1<<endl;
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