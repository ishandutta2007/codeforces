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
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll n,m,k;
vector<int> al[100005];
priority_queue<ii,vector<ii>,greater<ii> > pq;

vector<ii> edges;
bool used[100005];
int deg[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m>>k;
		
		rep(x,1,n+1) al[x].clear();
		rep(x,1,n+1) used[x]=false;
		
		edges.clear();
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			al[a].push_back(b);
			al[b].push_back(a);
			if (b<a) swap(a,b);
			edges.push_back(ii(a,b));
		}
		
		sort(all(edges));
		
		if (m<k*(k-1)/2){
			cout<<"-1"<<endl;
			goto die;
		}
		
		while (!pq.empty()) pq.pop();
		rep(x,1,n+1){
			deg[x]=sz(al[x]);
			pq.push(ii(deg[x],x));
		}
		
		ll size,node;
		while (!pq.empty()){
			tie(size,node)=pq.top();
			//cout<<"d: "<<size<<" "<<node<<endl;
			
			if (deg[node]!=size){
				pq.pop();
				continue;
			}
			
			if (size<k-1){
				pq.pop();
				for (auto &it:al[node]) if (!used[it]){
					deg[it]--;
					pq.push(ii(deg[it],it));
				}
				
				used[node]=true;
			}
			else if (size==k-1){
				vector<ll> clique={node};
				for (auto &it:al[node]) if (!used[it]){
					clique.push_back(it);
				}
				
				sort(all(clique));
				
				rep(x,0,k){
					rep(y,x+1,k){
						if (!binary_search(all(edges),ii(clique[x],clique[y]))) goto bruh;
					}
				}
				
				cout<<2<<endl;
				for (auto &it:clique) cout<<it<<" "; cout<<endl;
				goto die;
				
				bruh:;
				
				pq.pop();
				for (auto &it:al[node]) if (!used[it]){
					deg[it]--;
					pq.push(ii(deg[it],it));
				}
				
				used[node]=true;
			}
			else{
				break;
			}
		}
		
		if (pq.empty()){
			cout<<"-1"<<endl;
		}
		else{
			vector<int> temp;
			while (!pq.empty()){
				if (deg[pq.top().se]==pq.top().fi) temp.push_back(pq.top().se);
				pq.pop();
			}
			
			cout<<1<<" "<<sz(temp)<<endl;
			for (auto &it:temp) cout<<it<<" "; cout<<endl;
		}
		
		die:;
	}
}