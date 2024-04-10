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

#define indexed_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct upd{
	ll d;
	ll l,r;
	ll t;
};

ll n,m,k;
vector<ii> v;

bool can(int i){
	vector<upd> u;
	multiset<ii> s;
	
	int mn1,mn2,mx1,mx2;
	for (auto &it:v){
		u.push_back({max(1LL,it.fi-i),max(1LL,it.se-i),min(m,it.se+i),1});
		u.push_back({min(n,it.fi+i)+1,max(1LL,it.se-i),min(m,it.se+i),2});
	}
	
	stable_sort(all(u),[](upd i,upd j){
		return i.d<j.d;
	});
	
	bool used=false;
	if (u.front().d!=1){
		if (m>i*2+1) return false;
		u.push_back({1,1,m,1});
		u.push_back({min(n,i*2+1LL)+1,1,m,2});
		stable_sort(all(u),[](upd i,upd j){
			return i.d<j.d;
		});
		used=true;
	}
	if (u.back().d!=n+1){
		//cout<<"debug: "<<i<<" "<<used<<endl;
		if (used) return false;
		if (m>i*2+1) return false;
		u.push_back({max(1LL,n-(i*2)),1,m,1});
		u.push_back({n+1,1,m,2});
		stable_sort(all(u),[](upd i,upd j){
			return i.d<j.d;
		});
		used=false;
	}
	
	//cout<<"hello"<<" "<<i<<endl;
	
	rep(x,0,sz(u)-1){
		if (u[x].t==1){
			s.insert(ii(u[x].l,1));
			s.insert(ii(u[x].r+1,-1));
		}
		else{
			s.erase(s.find(ii(u[x].l,1)));
			s.erase(s.find(ii(u[x].r+1,-1)));
		}
		
		
		restart:;
		
		if (u[x].d!=u[x+1].d){
			//cout<<i<<endl;
			//for (auto &it:s) cout<<it.fi<<"_"<<it.se<<" "; cout<<endl;
			
			if ((*s.begin()).fi!=1){
				if (used) return false;
				used=true;
				s.insert(ii(1,1));
				s.insert(ii(min(m,1LL+i*2)+1,-1));
				u.push_back({min(n,u[x].d+i*2)+1,1,min(m,1LL+i*2),2});
				stable_sort(all(u),[](upd i,upd j){
					return i.d<j.d;
				});
				goto restart;
			}
			if ((*s.rbegin()).fi!=m+1){
				if (used) return false;
				used=true;
				s.insert(ii(max(1LL,m-i*2),1));
				s.insert(ii(m+1,-1));
				u.push_back({min(n,u[x].d+i*2)+1,max(1LL,m-i*2),m,2});
				stable_sort(all(u),[](upd i,upd j){
					return i.d<j.d;
				});
				goto restart;
			}
			
			int curr=0;
			ll pp=-1;
			
			for (auto &it:s){
				if (pp!=-1 && pp!=it.fi && curr==0){
					if (used) return false;
					used=true;
					s.insert(ii(pp,1));
					s.insert(ii(min(m,pp+i*2)+1,-1));
					u.push_back({min(n,u[x].d+i*2)+1,pp,min(m,pp+i*2),2});
					stable_sort(all(u),[](upd i,upd j){
						return i.d<j.d;
					});
					goto restart;
				}
				
				curr+=it.se;
				pp=it.fi;
			}
		}
	}
	
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	
	int a,b;
	rep(x,0,k){
		cin>>a>>b;
		v.push_back(ii(a,b));
	}
	
	int lo=-1,hi=1e9+100,mi;
	while (hi-lo>1){
		mi=lo+hi>>1;
		
		if (can(mi)) hi=mi;
		else lo=mi;
	}
	
	cout<<hi<<endl;
}