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
void solve(){
	vii v;
	cin>>s;
	int zeros=0;
	rep(i,0,sz(s)){
		int num=0;
		rep(j,i,min(sz(s),i+20)){
			num=num*2+s[j]-'0';
			if(j-i+1<=num and num<=j-i+1+zeros) v.pb({j-num+1,j});
		}
		if(s[i]=='0') zeros++;
		else zeros=0;
	}
	sort(all(v));
	cout<<unique(all(v))-v.begin()<<endl;
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