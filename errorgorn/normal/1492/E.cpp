//
//

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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
vector<int> v[250005];

int check(vector<int> vv){
	rep(x,0,n){
		int cnt=0;
		rep(y,0,m) if (vv[y]!=v[x][y]) cnt++;
		if (cnt>2) return x;
	}
	return -1;
}

int check2(vector<int> &vv){
	rep(x,0,n){
		int cnt=0;
		rep(y,0,m) if (vv[y]!=v[x][y]) cnt++;
		if (cnt>3) return x;
		
		if (cnt==3){
			bool bad=true;
			rep(y,0,m){
				if (vv[y]==-1) vv[y]=v[x][y],bad=false;
			}
			if (bad) return x;
		}
	}
	
	rep(y,0,m) if (vv[y]==-1) vv[y]=69;
	
	return -1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n){
		rep(y,0,m){
			int t;
			cin>>t;
			
			v[x].pub(t);
		}
	}
	
	int temp=check(v[0]);
	
	if (temp==-1){
		cout<<"Yes"<<endl;
		for (auto &it:v[0]) cout<<it<<" "; cout<<endl;
	}
	else{
		vector<int> a=v[0],b=v[temp];
		vector<int> idx;
		
		rep(x,0,m) if (a[x]!=b[x]) idx.pub(x);
		
		if (sz(idx)>4){
			cout<<"No"<<endl;
			return 0;
		}
		
		rep(x,0,1<<sz(idx)){
			vector<int> st=a;
			rep(y,0,sz(idx)) if (x&(1<<y)) st[idx[y]]=b[idx[y]];
			
			if (sz(idx)==3){
				for (auto &i:idx){
					vector<int> st2=st;
					st2[i]=-1;
					
					if (check2(st2)==-1){
						cout<<"Yes"<<endl;
						for (auto &it:st2) cout<<it<<" "; cout<<endl;
						return 0;
					}
				}
			}
			
			if (check(st)==-1){
				cout<<"Yes"<<endl;
				for (auto &it:st) cout<<it<<" "; cout<<endl;
				return 0;
			}
		}
		
		cout<<"No"<<endl;
	}
}