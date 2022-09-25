/*













*/

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
using namespace std;
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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct custom_hash {
    typedef unsigned long long ull;
    const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static ull splitmix64(ull x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ll x) const {
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(const pair<int,int> &i)const{
        return splitmix64((((ll)i.first)^(((ll)i.second)<<32))+FIXED_RANDOM);
    }
};


struct node{
	int s,e,m;
	int val=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int k){
		if (s==e) val^=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			
			val=l->val^r->val;
		}
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)^r->query(m+1,j);
	}
}*root=new node(0,1000005),*dist=new node(0,1000005);

struct Q{
	int l,r;
	int idx;
	
	Q(int a,int b,int c){
		l=a,r=b,idx=c;
	}
};

int n,q;
int arr[1000005];
int ans[1000005];
vector<Q> queries;
unordered_map<int,int,custom_hash> occ;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n){
		cin>>arr[x];
		root->update(x,arr[x]);	
	}
	
	cin>>q;
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		a--,b--;
		queries.push_back(Q(a,b,x));
	}
	
	sort(all(queries),[](Q &i,Q &j){
		return i.l>j.l;
	});
	
	int curr=n;
	for (auto &it:queries){
		while (curr>it.l){
			curr--;
			
			if (occ.count(arr[curr])){
				//cout<<occ[arr[curr]]<<" "<<arr[curr]<<endl;
				dist->update(occ[arr[curr]],arr[curr]);
			}
			//cout<<curr<<" "<<arr[curr]<<endl;
			dist->update(curr,arr[curr]);
			occ[arr[curr]]=curr;
		}
		
		//cout<<dist->query(it.l,it.r)<<endl;
		ans[it.idx]=root->query(it.l,it.r)^dist->query(it.l,it.r);
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}