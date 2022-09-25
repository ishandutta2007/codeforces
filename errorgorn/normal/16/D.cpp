//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
string s;
vector<int> v;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	getline(cin,s);
	rep(x,0,n){
		getline(cin,s);
		
		int t=0;
		t+=(s[1]-'0')*10*60;
		t+=(s[2]-'0')*60;
		t+=(s[4]-'0')*10;
		t+=(s[5]-'0');
		t%=12*60;
		if (s[7]=='p') t+=12*60;
		
		v.pub(t);
	}
	
	//for (auto it:v) cout<<it<<" "; cout<<endl;
	
	int ans=0;
	int curr=0,currt=1e9;
	for (auto it:v){
		if (currt!=it){
			if (currt>it) ans++;
			curr=1;
			currt=it;
		}
		else{
			curr++;
			if (curr==11) curr=1,ans++;
		}
		
		//cout<<curr<<" "<<currt<<endl;
	}
	
	cout<<ans<<endl;
}