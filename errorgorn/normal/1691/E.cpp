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

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct UFDS{
	int p[100005];
	
	void reset(int n){
		rep(x,0,n) p[x]=x;
	}
	
	int par(int i){
		if (p[i]==i) return i;
		else return p[i]=par(p[i]);
	}
	
	void unions(int i,int j){
		i=par(i),j=par(j);
		p[i]=j;
	}
} ufds;

int n;
int c[100005],l[100005],r[100005];

struct U{
	int typ; //0=add, 1=remove
	int id,t;
	int col;
};

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>c[x]>>l[x]>>r[x];
		ufds.reset(n);
		
		vector<U> upd;
		rep(x,0,n){
			upd.pub({0,x,l[x],c[x]});
			upd.pub({1,x,r[x],c[x]});
		}
		
		sort(all(upd),[](U i,U j){
			return ii(i.t,i.typ)<ii(j.t,j.typ);
		});
		
		set<int> s[2];
		for (auto it:upd){
			if (it.typ==0) s[it.col].insert(it.id);
			else s[it.col].erase(it.id);
			
			if (sz(s[0]) && sz(s[1])){
				ufds.unions(*s[0].begin(),*s[1].begin());
				rep(x,0,2){
					while (sz(s[x])>=2){
						int t1=*s[x].begin(); s[x].erase(s[x].begin());
						int t2=*s[x].begin(); s[x].erase(s[x].begin());
						ufds.unions(t1,t2);
						if (r[t1]<r[t2]) swap(t1,t2);
						s[x].insert(t1);
					}
				}
			}
		}
		
		int ans=0;
		rep(x,0,n) if (ufds.p[x]==x) ans++;
		cout<<ans<<endl;
	}
}