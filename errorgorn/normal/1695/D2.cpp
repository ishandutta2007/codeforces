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
vector<int> al[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		rep(x,1,n+1) al[x].clear();
		
		cin>>n;
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			al[a].pub(b);
			al[b].pub(a);
		}
		
		int leaves=0;
		rep(x,1,n+1) if (sz(al[x])<=1) leaves++;
		
		if (leaves<=2) cout<<leaves-1<<endl;
		else{
			set<int> s;
			rep(x,1,n+1) if (sz(al[x])==1){
				int curr=x,currp=-1;
				while (sz(al[curr])<=2){
					for (auto it:al[curr]){
						if (it==currp) continue;
						currp=curr;
						curr=it;
						break;
					}
				}
				
				if (!s.count(curr)){
					s.insert(curr);
					leaves--;
				}
			}
			
			cout<<leaves<<endl;
		}
	}
}