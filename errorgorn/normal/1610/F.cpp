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
#define ii pair<int,int>
#define iii pair<ii,int>
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
multiset<ii> al[2][100005];
map<ii,vector<int> > id[2];

set<int> alive;
deque<ii> v[100005];

int join(int i,int j){
	if (sz(v[i])<sz(v[j])) swap(i,j);
	
	if (v[i].back().fi==v[j].front().fi){
		for (auto &it:v[j]) v[i].pub(it);
	}
	else if (v[i].back().fi==v[j].back().fi){
		reverse(all(v[j]));
		for (auto &it:v[j]) v[i].pub(it);
	}
	else if (v[i].front().fi==v[j].front().fi){
		for (auto &it:v[j]) v[i].puf(it);
	}
	else{
		reverse(all(v[j]));
		for (auto &it:v[j]) v[i].puf(it);
	}
	
	alive.erase(j);
	return i;
}

int rev[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	assert(n<=100000 && m<=100000);
	
	int a,b,c;
	rep(x,1,m+1){
		cin>>a>>b>>c;
		c--;
		
		al[c][a].insert(ii(b,x));
		al[c][b].insert(ii(a,x));
		
		alive.insert(x);
		v[x].pub(ii(a,c));
		v[x].pub(ii(b,c));
		
		if (a<b) id[c][ii(a,b)].pub(x);
		else id[c][ii(b,a)].pub(-x);
	}
	
	//join with same weight
	rep(z,0,2){
		rep(x,1,n+1) while (sz(al[z][x])>=2){
			auto it=(*al[z][x].begin()).se;
			al[z][x].erase(al[z][x].begin());
			auto it2=(*al[z][x].begin()).se;
			al[z][x].erase(al[z][x].begin());
			
			al[z][v[it].front().fi].erase({v[it].back().fi,it});
			al[z][v[it].back().fi].erase({v[it].front().fi,it});
			
			al[z][v[it2].front().fi].erase({v[it2].back().fi,it2});
			al[z][v[it2].back().fi].erase({v[it2].front().fi,it2});
			
			int idx=join(it,it2);
			
			if (v[idx].front().fi!=v[idx].back().fi){
				al[z][v[idx].front().fi].insert({v[idx].back().fi,idx});
				al[z][v[idx].back().fi].insert({v[idx].front().fi,idx});
			}
		}
	}
	
	//merge edges into same adj list
	int ans=0;
	rep(x,1,n+1){
		if (sz(al[0][x])) ans++;
		for (auto &it:al[1][x]) al[0][x].insert(it);
	}
	
	//join with diff weight
	rep(z,0,1){
		rep(x,1,n+1) while (sz(al[z][x])>=2){
			auto it=(*al[z][x].begin()).se;
			al[z][x].erase(al[z][x].begin());
			auto it2=(*al[z][x].begin()).se;
			al[z][x].erase(al[z][x].begin());
			
			al[z][v[it].front().fi].erase({v[it].back().fi,it});
			al[z][v[it].back().fi].erase({v[it].front().fi,it});
			
			al[z][v[it2].front().fi].erase({v[it2].back().fi,it2});
			al[z][v[it2].back().fi].erase({v[it2].front().fi,it2});
			
			int idx=join(it,it2);
			
			if (v[idx].front().fi!=v[idx].back().fi){
				al[z][v[idx].front().fi].insert({v[idx].back().fi,idx});
				al[z][v[idx].back().fi].insert({v[idx].front().fi,idx});
			}
		}
	}
	
	for (auto &it:alive){
		rep(x,0,sz(v[it])/2){
			int a=v[it][x*2].fi,b=v[it][x*2+1].fi,c=v[it][x*2].se;
			
			bool dir=(a>b);
			if (a>b) swap(a,b);
			
			int pos=id[c][ii(a,b)].back();
			id[c][ii(a,b)].pob();
			
			if (pos<0){
				dir^=true;
				pos=-pos;
			}
			
			rev[pos]=dir;
		}
	}
	
	cout<<ans<<endl;
	rep(x,1,m+1) cout<<rev[x]+1; cout<<endl;
}