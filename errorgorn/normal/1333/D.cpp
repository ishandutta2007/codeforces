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

int n,k;
vector<int> moves[3005];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	cin>>s;
	
	int num=0;
	int sz=0;
	while (true){
		for (int x=0;x<n-1;x++){
			if (s[x]=='R' && s[x+1]=='L'){
				moves[num].push_back(x+1);
				swap(s[x],s[x+1]);
				x++;
			}
		}
		sz+=moves[num].size();
		if (moves[num].empty()) break;
		num++;
	}
	
	if (k<num || sz<k){
		cout<<"-1"<<endl;
	}
	else{
		int curr=num;
		
		for (int x=0;x<num;){
			if (curr==k || moves[x].size()==1){
				cout<<moves[x].size()<<" ";
				for (auto &it:moves[x]) cout<<it<<" ";
				cout<<endl;
				x++;
			}
			else{
				cout<<"1 "<<moves[x].back()<<endl;
				moves[x].pop_back();
				curr++;
			}
		}
	}
}