//
//

#include <bits/stdc++.h>
using namespace std;
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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const ll INF=1e18;

struct node{
	int s,e,m;
	ll sum;
	ll min1,min2,min_cnt;
	ll lazy_sum,lazy_max,lazy_min;
	node *l,*r;
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			sum=0;
			min1=0,min2=INF,min_cnt=e-s+1;
		}
		else{
			sum=0;
			min1=0,min2=INF,min_cnt=1;
		}
		
		lazy_sum=0;
		lazy_max=-INF;
	}
	
	inline void propo(){ //propogate lazy tags to children (cfm exists)
		if (lazy_sum!=0) l->push_sum(lazy_sum),r->push_sum(lazy_sum);
		if (lazy_max!=-INF) l->push_max(lazy_max),r->push_max(lazy_max);
		lazy_sum=0,lazy_max=-INF;
	}
	
	inline void upd(){ //update details based on children (cfm exists)
		sum=l->sum+r->sum;
		
		if (l->min1==r->min1){
			min1=l->min1;
			min_cnt=l->min_cnt+r->min_cnt;
			min2=min(l->min2,r->min2);
		}
		else if (l->min1<r->min1){
			min1=l->min1;
			min_cnt=l->min_cnt;
			min2=min(l->min2,r->min1);
		}
		else{
			min1=r->min1;
			min_cnt=r->min_cnt;
			min2=min(r->min2,l->min1);
		}
	}
	
	inline void push_sum(ll k){
		sum+=(e-s+1)*k;
		
		if (lazy_max!=-INF) lazy_max+=k;
		min1+=k;
		if (min2!=INF) min2+=k;
		lazy_sum+=k;
	}
	
	inline void push_max(ll k){ //we are garaunteed that max_cnt does not change
		if (k<=min1) return;
		
		sum+=(k-min1)*min_cnt;
		min1=k;
		lazy_max=k;
	}

	void update_sum(int i,int j,ll k){
		if (s==i && e==j){ //dont need to propogate
			push_sum(k);
		}
		else{
			propo();
		
			if (j<=m) l->update_sum(i,j,k);
			else if (m<i) r->update_sum(i,j,k);
			else l->update_sum(i,m,k),r->update_sum(m+1,j,k);
			
			upd();
		}
	}
	
	void update_max(int i,int j,ll k){
		if (k<=min1) return;
		else if (s==i && e==j && k<min2){ //dont need to propogate
			push_max(k);
		}
		else{
			propo();
		
			if (j<=m) l->update_max(i,j,k);
			else if (m<i) r->update_max(i,j,k);
			else l->update_max(i,m,k),r->update_max(m+1,j,k);
			
			upd();
		}
	}
}*root=new node(0,1000005);

int n;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	getline(cin,s);
	getline(cin,s);
	n=sz(s);
	
	
	bool on=false;
	int l;
	
	ll ans=0;
	rep(x,0,n){
		if (s[x]=='1'){
			if (!on) l=x;
			on=true;
			
			root->update_sum(l,x,1);
			if (l!=0){
				root->update_max(0,l-1,x-l+1);
			}
		}
		else{
			on=false;
		}
		
		ans+=root->sum;
	}
	
	cout<<ans<<endl;
}