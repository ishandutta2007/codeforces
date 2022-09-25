/*













*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const double PI=acos(-1);

int n;
vector<int> al[1505];
vector<int> points[1505];
int ss[1505];

complex<double> coord[1505];

double memo[1505][1505];

int ans[1505];

double angle(double i,double j){
	double res=j-i;
	while (res<0) res+=2*PI;
	
	return res;
}

void dfss(int i,int p){
	ss[i]=1;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfss(it,i);
		ss[i]+=ss[it];
	}
}

void dfs(int i,int p,int root){
	sort(all(points[i]),[root](int x,int y){
		return memo[x][root]<memo[y][root];
	});
	
	//cout<<i<<endl;
	//for (auto &it:points[i]) cout<<it<<" ";cout<<endl;
	
	int curr=0;
	for (auto &it:al[i]){
		if (it==p) continue;
		
		int leftmost=points[i][curr];
		rep(x,curr,curr+ss[it]){
			if (coord[points[i][x]].real()<coord[leftmost].real()) leftmost=points[i][x];
		}
		rep(x,curr,curr+ss[it]){
			if (points[i][x]!=leftmost) points[it].push_back(points[i][x]);
		}
		dfs(it,i,leftmost);
		
		curr+=ss[it];	
	}
	
	//cout<<root<<" "<<i<<endl;
	ans[root]=i;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	dfss(1,-1);
	
	rep(x,1,n+1){
		cin>>a>>b;
		coord[x]={a,b};
	}
	rep(x,1,n+1){
		rep(y,1,n+1){
			memo[x][y]=arg(coord[x]-coord[y]);
		}
	}
	
	int leftmost=1;
	rep(x,1,n+1){
		if (coord[x].real()<coord[leftmost].real()) leftmost=x;
	}
	
	rep(x,1,n+1){
		if (x!=leftmost) points[1].push_back(x);
	}
	
	
	dfs(1,-1,leftmost);
	
	rep(x,1,n+1) cout<<ans[x]<<" ";
}