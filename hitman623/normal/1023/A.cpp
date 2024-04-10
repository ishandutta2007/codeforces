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
int n,m;
string s,t;
void solve(){
	cin>>n>>m;
	cin>>s>>t;
	if(sz(s)>sz(t)+1){
		cout<<"NO"<<endl;
		return;
	}
	string g=s;
	if(g.back()=='*')
	g.pop_back();
	if(s==t || t==g){
		cout<<"YES"<<endl;
		return;
	}
	int cur1=-1;
	rep(i,0,min(sz(s),sz(t))){
		if(s[i]!=t[i]){
			cur1=i;
			break;
		}
	}
	if(cur1==-1){
	    cout<<"NO"<<endl;
	    return;
	}
	int cur2=sz(s)-1;
	for(int i=sz(t)-1;i>=0 and cur2>=0;i--){
		if(s[cur2]!=t[i]){
			break;
		}
		else cur2--;
	}
	if(cur1>cur2){
		cout<<"YES"<<endl;
	}
	else if(cur1==cur2){
		if(s[cur1]=='*'){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	else cout<<"NO"<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}