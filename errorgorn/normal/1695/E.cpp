// Super Idol
//    
//  
//    
//  105C
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
bool vis1[600005];
bool vis2[300005];
vector<ii> al[600005];

vector<int> v;

void dfs(int i){
	if (!vis1[i]){
		vis1[i]=true;
		
		for (auto [it,id]:al[i]){
			if (!vis2[id]){
				v.pub(it);
				vis2[id]=true;
				dfs(it);
				v.pub(i);
			}
		}
	}
}

vector<int> ans[2];
string s[2][2];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	rep(x,0,n){
		cin>>a>>b;
		al[a].pub({b,x});
		al[b].pub({a,x});
	}
	
	rep(x,1,2*n+1) if (!vis1[x]){
		v.clear();
		dfs(x);
		
		if (sz(v)==2){
			cout<<"-1"<<endl;
			return 0;
		}
		if (sz(v)>2){
			int ss=sz(v)/2;
			rep(x,0,ss) ans[0].pub(v[x]);
			rep(x,2*ss,ss) ans[1].pub(v[x]);
			
			if (ss%2==0){
				rep(x,0,ss/2) s[0][0]+="LR",s[0][1]+="LR";
				
				s[1][0]+="U";
				s[1][1]+="D";
				rep(x,0,ss/2-1) s[1][0]+="LR",s[1][1]+="LR";
				s[1][0]+="U";
				s[1][1]+="D";
			}
			else{
				s[0][0]+="U";
				s[0][1]+="D";
				rep(x,0,ss/2) s[0][0]+="LR",s[0][1]+="LR";
				rep(x,0,ss/2) s[1][0]+="LR",s[1][1]+="LR";
				s[1][0]+="U";
				s[1][1]+="D";
			}
		}
	}
	
	cout<<2<<" "<<sz(ans[0])<<endl<<endl;
	for (auto it:ans[0]) cout<<it<<" "; cout<<endl;
	for (auto it:ans[1]) cout<<it<<" "; cout<<endl;
	
	cout<<s[0][0]<<endl<<s[0][1]<<endl<<endl;
	cout<<s[1][0]<<endl<<s[1][1]<<endl<<endl;
}