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

int n;
bool has[205][205];
bool used[205];
int cnt[205];

int l[205];
bool inside[205];

bool can(int i,bool flag){
	//debug(i);
	
	memset(l,0,sizeof(l));
	memset(used,false,sizeof(used));
	memset(inside,false,sizeof(inside));
	
	rep(x,0,205) l[x]=cnt[x];
	
	vector<int> ans;
	int curr=i;
	while (curr){
		//debug(curr);
		rep(x,0,n-1) if (!used[x] && has[x][curr]){
			ans.push_back(curr);
			inside[curr]=true;
			
			used[x]=true;
			
			vector<int> temp;
			
			rep(y,0,205) if (has[x][y]){
				l[y]--;
				if (l[y]==1) temp.push_back(y);
			}
			
			if (temp.empty()) curr=0;
			else{
				if (sz(temp)==1) curr=temp[0];
				else{
					if (flag) swap(temp[0],temp[1]);
					curr=temp[0];
					rep(x,0,n-1) if (used[x]){
						if (has[x][temp[1]] && !has[x][temp[0]]){
							return false;
						}
					}
				}
			}
			
			break;
		}
	}
	
	if (sz(ans)==n-1){
		rep(x,1,n+1) if (!inside[x]) ans.push_back(x);
		reverse(all(ans));
		
		for (auto &it:ans) cout<<it<<" ";
		cout<<endl;
		
		return true;
	}
	else{
		return false;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		memset(has,false,sizeof(has));
		memset(cnt,0,sizeof(cnt));
	
		cin>>n;
		
		int a,b;
		rep(x,0,n-1){
			cin>>a;
			rep(y,0,a){
				cin>>b;
				has[x][b]=true;
				cnt[b]++;
			}
		}
		
		rep(x,1,n+1){
			if (cnt[x]==1){
				if (can(x,true)) break;
				if (can(x,false)) break;
			}
		}
	}
}