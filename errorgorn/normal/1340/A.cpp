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
int pos[100005];
set<int> s;

int cnt[100005];
multiset<int> cval;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		s.clear();
		cval.clear();
		
		cin>>n;
		
		int t;
		rep(x,0,n){
			cin>>t;
			pos[t]=x;
			s.insert(x);
			
			cnt[x]=1;
			cval.insert(1);
		}
		
		rep(x,1,n+1){
			//cout<<pos[x]<<endl;
			
			if (cnt[pos[x]]!=*cval.rbegin()){
				cout<<"No"<<endl;
				goto _end;
			}
			
			set<int>::iterator it=s.find(pos[x]);
			
			if (it!=--s.end()){
				it++;
				
				cval.erase(cval.find(cnt[*it]));
				cnt[*it]+=cnt[pos[x]];
				cval.insert(cnt[*it]);
			}
			
			cval.erase(cval.find(cnt[pos[x]]));
			s.erase(pos[x]);
		}
		
		cout<<"Yes"<<endl;
		_end:;
		
	}
}