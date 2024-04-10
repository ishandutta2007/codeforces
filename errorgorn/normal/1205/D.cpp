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
vector<int> al[1005];

int ss[1005];

void dfs_ss(int i,int p){
	ss[i]=1;
	for (auto it:al[i]) if (it!=p){
		dfs_ss(it,i);
		ss[i]+=ss[it];
	}
}

bool has[1005];
void dfs_mark(int i,int p){
	has[i]=true;
	for (auto it:al[i]) if (it!=p){
		dfs_mark(it,i);
	}
}

vector<int> v1,v2;

int val[1005];
void dfs(int i,int p){
	if (has[i]){
		val[i]=v1.back(); v1.pob();
	}
	else{
		val[i]=v2.back(); v2.pob();
	}
	cout<<i<<" "<<p<<" "<<val[i]-val[p]<<endl;
	
	for (auto it:al[i]) if (it!=p) dfs(it,i);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	dfs_ss(1,-1);
	int curr=1,currp=-1;
	
	while (true){
		bool done=true;
		for (auto it:al[curr]) if (it!=currp && ss[it]>=(n+1)/2){
			currp=curr;
			curr=it;
			done=false;
			break;
		}
		if (done) break;
	}
	
	dfs_ss(curr,-1);
	int lim=2*n/3,cs=0;
	
	for (auto it:al[curr]) if (cs+ss[it]<=lim){
		dfs_mark(it,curr);
		cs+=ss[it];
	}
	
	rep(x,cs+1,1) v1.pub(x);
	rep(x,n+1,1) v2.pub(x*(cs+1));
	
	for (auto it:al[curr]) dfs(it,curr);
}