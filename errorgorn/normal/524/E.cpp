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

const int SQRTN=450;
int n,m,k,q;
vector<ii> v;

struct Q{
	int x1,y1,x2,y2;
	int idx;
	int l,r;
};
vector<Q> queries;

const int B=320;
int has[200005];
int block[320];

bool ans[200005];

void update(int i,int k){
	if (!has[i]) block[i/B]++;
	has[i]+=k;
	if (!has[i]) block[i/B]--;
}

int count(int i,int j){
	int res=0;
	while (i<=j){
		if (i%B==0 && i+B-1<=j){
			res+=block[i/B];
			i+=B-1;
		}
		else{
			res+=(has[i]?1:0);
		}
		i++;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k>>q;
	
	int a,b,c,d;
	rep(x,0,k){
		cin>>a>>b;
		v.push_back(ii(a,b));
	}
	
	rep(x,0,q){
		cin>>a>>b>>c>>d;
		
		queries.push_back(Q({a,b,c,d,x}));
	}
	
	rep(zzz,0,2){
		memset(has,0,sizeof(has));
		memset(block,0,sizeof(block));
	
		sort(all(v));
		
		for (auto &it:queries){
			it.l=lower_bound(all(v),ii(it.x1,-1))-v.begin();
			it.r=upper_bound(all(v),ii(it.x2+1,-1))-v.begin()-1;
		}
		
		sort(all(queries),[](Q i,Q j){
			if (i.l/SQRTN!=j.l/SQRTN) return i.l<j.l;
			else if (i.l/SQRTN%2==0) return i.r<j.r;
			else return i.r>j.r;
		});
		
		int l=0,r=-1;
		
		for (auto &it:queries){
			while (r<it.r) update(v[++r].se,1);
			while (l<it.l) update(v[l++].se,-1);
			while (it.l<l) update(v[--l].se,1);
			while (it.r<r) update(v[r--].se,-1);
			
			//cout<<it.l<<" "<<it.r<<" "<<it.y1<<" "<<it.y2<<" "<<count(it.y1,it.y2)<<endl;
			ans[it.idx]|=count(it.y1,it.y2)==it.y2-it.y1+1;
		}
		
		for (auto &it:v) swap(it.fi,it.se);
		for (auto &it:queries) swap(it.x1,it.y1),swap(it.x2,it.y2);
	}
	
	rep(x,0,q){
		if (ans[x]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}