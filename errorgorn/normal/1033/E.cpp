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
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int query(set<int> s){
	if (sz(s)==1) return 0;
	
	cout<<"? "<<sz(s)<<endl;
	for (auto &it:s) cout<<it<<" "; cout<<endl;
	int temp;
	cin>>temp;
	return temp;
}

bool check(set<int> i,set<int> j){
	int temp=query(j);
	
	j.insert(all(i));
	return query(j)-temp>0;
}

ii search(set<int> i,set<int> j){
	while (sz(j)!=1){
		set<int> l,r;
		bool f=false;
		for (auto &it:j){
			if (f) l.insert(it);
			else r.insert(it);
			f^=true;
		}
		
		if (check(i,l)) j=l;
		else j=r;
	}
	
	while (sz(i)!=1){
		set<int> l,r;
		bool f=false;
		for (auto &it:i){
			if (f) l.insert(it);
			else r.insert(it);
			f^=true;
		}
		
		if (check(l,j)) i=l;
		else i=r;
	}
	
	return ii(*i.begin(),*j.begin());
}

int n;

set<int> l,r,rem;
vector<int> al[605];

vector<int> trav;
vector<int> stk;

void dfs(int i,int p,int goal){
	stk.pub(i);
	
	if (i==goal) trav=stk;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		dfs(it,i,goal);
	}
	
	stk.pob();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	l={1};
	rep(x,2,n+1) rem.insert(x);
	
	while (!rem.empty()){
		if (check(l,rem)){
			ii temp=search(l,rem);
			
			r.insert(temp.se);
			rem.erase(temp.se);
			
			al[temp.fi].pub(temp.se);
			al[temp.se].pub(temp.fi);
			
			//cout<<"add: "<<temp.fi<<" "<<temp.se<<endl;
			
			if (check(r,{(int)temp.se})){
				//cout<<"odd cycle detected"<<endl;
				ii temp2=search(r,{(int)temp.se});
				//cout<<"odd: "<<temp2.fi<<" "<<temp2.se<<endl;
				dfs(temp2.fi,-1,temp2.se);
				
				cout<<"N "<<sz(trav)<<endl;
				for (auto &it:trav) cout<<it<<" "; cout<<endl;
				
				return 0;
			}
		}
		else{ //since graph is connect ri is true here
			ii temp=search(r,rem);
			
			l.insert(temp.se);
			rem.erase(temp.se);
			
			al[temp.fi].pub(temp.se);
			al[temp.se].pub(temp.fi);
			
			//cout<<"add: "<<temp.fi<<" "<<temp.se<<endl;
		}
	}
	
	cout<<"Y "<<sz(l)<<endl;
	for (auto &it:l) cout<<it<<" "; cout<<endl;
}