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
vector<int> al[300005];
int ss[300005];
int memo[300005];

void dfs(int i,int p){
	ss[i]=1;
	memo[i]=0;
	
	vector<int> child;
	for (auto it:al[i]){
		if (it==p) continue;
		child.pub(it);
		dfs(it,i);
		ss[i]+=ss[it];
	}
	
	if (sz(child)==1){
		memo[i]=ss[i]-2;
	}
	else if (sz(child)==2){
		memo[i]=max({
			memo[child[0]]+ss[child[1]]-1,
			memo[child[1]]+ss[child[0]]-1
		});
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
		cin>>n;
		rep(x,1,n+1) al[x].clear();
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			al[a].pub(b);
			al[b].pub(a);
		}
		
		dfs(1,-1);
		cout<<memo[1]<<endl;
	}
}