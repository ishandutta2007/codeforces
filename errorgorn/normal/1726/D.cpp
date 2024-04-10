//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii tuple<int,int,int>
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

int n,m;
vector<ii> al[200005];
bool vis[200005];
int pp[200005];
int d[200005];

vector<iii> v;

void dfs(int i,int p){
	vis[i]=true;
	
	for (auto [it,id]:al[i]){
		if (it==p) continue;
		
		if (!vis[it]){
			d[it]=d[i]+1;
			dfs(it,i);
			pp[it]=id;
		}
		else if (d[i]>d[it]) v.pub({i,it,id});
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		
		rep(x,1,n+1) al[x].clear();
		rep(x,1,n+1) vis[x]=false;
		v.clear();
		
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			al[a].pub({b,x});
			al[b].pub({a,x});
		}
		
		dfs(1,-1);
		
		string ans(m,'0');
		set<int> s;
		for (auto [a,b,c]:v){
			//cout<<a<<" "<<b<<" "<<c<<endl;
			s.insert(a),s.insert(b);
			ans[c]^=1;
		}
		
		if (m==n+2 && sz(s)==3){
			//cout<<"fuck"<<endl;
			
			for (auto [a,b,c]:v){
				if (a!=1){
					ans[pp[a]]^=1;
					ans[c]^=1;
					break;
				}
			}
		}
		
		cout<<ans<<endl;
	}
}