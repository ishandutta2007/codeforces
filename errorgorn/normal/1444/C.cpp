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

struct E{
	ii id;
	ii e;
	
	E(ii a,ii b){
		id=a;
		e=b;
		
		if (id.fi>id.se) swap(id.fi,id.se);
	}
};

struct UFDS{
	int p[500005];
	int s[500005];
	bool par[500005];
	
	vector<ii> upds;
	
	UFDS(){
		rep(x,0,500005){
			p[x]=x;
			s[x]=1;
			par[x]=false;
		}
	}
	
	ii parent(int i){
		if (p[i]==i) return ii(i,false);
		else{
			ii temp=parent(p[i]);
			return ii(temp.fi,temp.se^par[i]);
		}
	}
	
	bool unions(int i,int j){
		ii temp1=parent(i),temp2=parent(j);
		if (temp1.fi==temp2.fi) return temp1.se!=temp2.se;
		
		if (s[temp1.fi]<s[temp2.fi]) swap(temp1,temp2);
		
		p[temp2.fi]=temp1.fi;
		s[temp1.fi]+=s[temp2.fi];
		par[temp2.fi]=true^temp1.se^temp2.se;
		
		upds.push_back(ii(temp1.fi,temp2.fi));
		
		return true;
	}
	
	void roll(int i){
		while (sz(upds)>i){
			int u=upds.back().fi,v=upds.back().se;
			upds.pop_back();
			
			p[v]=v;
			s[u]-=s[v];
		}
	}
} dsu;

int n,m,k;
int arr[500005];
vector<E> v;
bool bad[500005];

int rollb;
ll ans;

bool proc(vector<ii> v){
	dsu.roll(rollb);
	//cout<<"testing"<<endl;
	//for (auto &it:v) cout<<it.fi<<" "<<it.se<<endl;
	for (auto &it:v){
		if (!dsu.unions(it.fi,it.se)) return 1;
	}
	
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		v.push_back(E(ii(arr[a],arr[b]),ii(a,b)));
	}
	
	sort(all(v),[](E &i,E &j){
		return i.id<j.id;
	});
	
	
	ans=k;
	for (auto &it:v) if (it.id.fi==it.id.se){
		if (!dsu.unions(it.e.fi,it.e.se)){
			//cout<<it.e.fi<<" "<<it.e.se<<endl;
			if (!bad[it.id.fi]) ans--;
			bad[it.id.fi]=true;
		}
	}
	ans=ans*(ans-1)/2;
	rollb=sz(dsu.upds);
	
	vector<ii> temp;
	ii curr=ii(-1,-1);
	for (auto &it:v) if (it.id.fi!=it.id.se && !bad[it.id.fi] && !bad[it.id.se]){
		if (curr!=it.id){
			ans-=proc(temp);
			temp.clear();
			curr=it.id;
		}
		temp.push_back(it.e);
	}
	ans-=proc(temp);
	
	cout<<ans<<endl;
}