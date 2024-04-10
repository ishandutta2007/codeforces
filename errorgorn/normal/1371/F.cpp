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

const int INF=1e9;

bool arr[500005]; //initialize to 0, this is 1-indexed
void update(int i){ //adds j to ith term
    while (i<500005){
        arr[i]^=true;
        i+=(i&(-i));
    }
}

void update(int i,int j){
	update(i);
	update(j+1);
}

bool query(int i){ //calculate the sum of the 0-i terms
    bool k=false;
    while (i>0){
        k^=arr[i];
        i-=(i&(-i));
    }
    return k; //we only care about mod 2
}


struct dat{
	int l=-INF,m=-INF,r=INF;
	
	void merge(dat i,dat j,bool flag,int mv){
		//false detects 0, 1 (normal)
		//true detects 1, 0 (reverse)
		
		bool mid=(query(mv)==flag && query(mv+1)!=flag);
		
		l=i.l,r=j.r;
		m=max(i.m,j.m);
		if (mid) m=MAX(m,j.l-mv,mv-i.r);
		else m=MAX(m,j.l-i.r);
		
		if (mid){
			if (l==-INF) l=mv;
			if (r==INF) r=mv;
		}
		
		if (r==INF){
			if (i.r!=INF) r=i.r;
			else if (l!=-INF) r=l;
		}	
		if (l==-INF){
			if (j.l!=-INF) l=j.l;
			else if (r!=INF) l=r;
		}
	}
};

bool ss;
dat glob;

struct node{
	int s,e,m;
	dat val,rval;
	bool lazy=false;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			val.merge(l->val,r->val,false,m);
			rval.merge(l->rval,r->rval,true,m);
			
		}
	}
	
	void propo(){
		if (lazy){
			swap(val,rval);
			
			if (s!=e){
				l->lazy^=true;
				r->lazy^=true;
			}
			
			lazy=false;
		}
	}
	
	void update(int i,int j){
		propo();
	
		if (s==i && e==j) lazy^=true;
		else{
			if (j<=m) l->update(i,j);
			else if (m<i) r->update(i,j);
			else l->update(i,m),r->update(m+1,j);
			
			l->propo(),r->propo();
			val.merge(l->val,r->val,false,m);
			rval.merge(l->rval,r->rval,true,m);
		}
	}
	
	void query(int i,int j){
		propo();
		
		if (s==i && e==j){
			if (!ss) glob=val,ss=true;
			else glob.merge(glob,val,false,s-1);
		}
		else if (j<=m) l->query(i,j);
		else if (m<i) r->query(i,j);
		else l->query(i,m),r->query(m+1,j); 
	}
} *root;

int n,q;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	cin>>s;
	
	s="$"+s;
	rep(x,1,n+1){
		if (s[x]=='>') update(x,x);
	}
	
	root=new node(1,n);
	
	int a,b;
	while (q--){
		cin>>a>>b;
		
		update(a,b);
		//rep(x,1,n+1) cout<<query(x)<<" ";cout<<endl;
		
		root->update(a,b);
		
		ss=false;
		root->query(a,b);
		
		//cout<<glob.l<<" "<<glob.m<<" "<<glob.r<<endl;
		
		if (glob.l==-INF) cout<<b-a+1<<endl;
		else{
			//cout<<glob.l-a+1<<" "<<glob.m<<" "<<b-glob.r<<endl;
			cout<<MAX(glob.l-a+1,glob.m,b-glob.r)<<endl;
		}
	}
}