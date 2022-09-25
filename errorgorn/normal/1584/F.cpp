//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

map<char,int> asc;
char dsc[52];

int n;
vector<int> pos[10][52];

ii p[1040][55];
int memo[1040][55];
queue<ii> q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,26){
		asc['a'+x]=x;
		dsc[x]='a'+x;
	}
	rep(x,0,26){
		asc['A'+x]=x+26;
		dsc[x+26]='A'+x;
	}
	
	int TC;
	cin>>TC;
	while (TC--){
		rep(x,0,10) rep(y,0,52) pos[x][y].clear();
		
		cin>>n;
		
		rep(x,0,n){
			string s;
			cin>>s;
			
			rep(y,0,sz(s)){
				pos[x][asc[s[y]]].pub(y);
			}
		}
		
		memset(memo,128,sizeof(memo));
		memset(p,-1,sizeof(p));
		
		rep(y,0,52){
			bool has=true;
			rep(x,0,n) if (pos[x][y].empty()) has=false;
			if (has){
				memo[0][y]=1;
				q.push(ii(0,y));
			}
		}
		
		int best=0;
		int px=-1,py=-1;
		
		while (!q.empty()){
			int x,y;
			tie(x,y)=q.front(),q.pop();
			
			if (memo[x][y]>best){
				best=memo[x][y];
				px=x,py=y;
			}
			
			rep(z,0,52){
				int mask=0;
				
				rep(bit,0,n){
					int i=!!(x&(1<<bit));
					int j=-1;
					rep(w,sz(pos[bit][z]),0) if (pos[bit][y][i]<pos[bit][z][w]){
						j=w;
					}
					
					if (j==-1){
						mask=-1;
						break;
					}
					mask|=(j<<bit);
				}
				
				if (mask==-1) continue;
				
				if (memo[mask][z]<memo[x][y]+1){
					memo[mask][z]=memo[x][y]+1;
					p[mask][z]=ii(x,y);
					q.push(ii(mask,z));
				}
			}
		}
		
		cout<<best<<endl;
		string ans;
		while (px!=-1){
			ans+=dsc[py];
			tie(px,py)=p[px][py];
		}
		
		reverse(all(ans));
		cout<<ans<<endl;
	}
}