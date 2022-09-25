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

int n,m;
int n1,n2,n3;
vector<int> al[5005];

bool visited[5005];
int state[5005];

vector<int> bp[2][5005];

bool memo[5005][5005];

bool ans[5005];

void rage(){
	cout<<"NO"<<endl;
	exit(0);
}

void dfs(int i,int id,int flag){
	visited[i]=true;
	state[i]=flag;
	bp[flag][id].push_back(i);
	
	for (auto &it:al[i]){
		if (!visited[it]) dfs(it,id,flag^1);
		else if (state[it]==state[i]) rage();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	cin>>n1>>n2>>n3;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	int INDEX=0;
	
	rep(x,1,n+1){
		if (!visited[x]) dfs(x,INDEX++,0);
		//cout<<sz(bp[0][INDEX-1])<<" "<<sz(bp[1][INDEX-1])<<endl;
	}
	
	memo[0][0]=1;
	rep(x,0,INDEX){
		rep(y,0,5005){
			if (memo[x][y]){
				memo[x+1][y+sz(bp[0][x])]=true;
				memo[x+1][y+sz(bp[1][x])]=true;
			}
		}
	}
	
	if (!memo[INDEX][n2]) rage();
	
	int curr=n2;
	rep(x,INDEX,0){
		if (curr-sz(bp[0][x])>=0 && memo[x][curr-sz(bp[0][x])]){
			for (auto &it:bp[0][x]) ans[it]=true;
			curr-=sz(bp[0][x]);
		}
		else{
			for (auto &it:bp[1][x]) ans[it]=true;
			curr-=sz(bp[1][x]);
		}
	}
	
	cout<<"YES"<<endl;
	rep(x,1,n+1){
		if (ans[x]) cout<<2;
		else{
			if (n1){
				cout<<1;
				n1--;
			}
			else{
				cout<<3;
			}
		}
	}
}