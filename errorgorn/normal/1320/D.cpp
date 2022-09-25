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

//mt19937 rng(69);
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=1000000007;
const int P=103; //but why

ll hashes[200005];
ll powP[200005];

struct range{
	int s,e; //legth of stuff at start and end
	int l,r; //left and right of position
	int len; //len of position
	ll h; //hash of position
	int sz; //size of range
};

range merge(range i,range j){
	range val;
	
	val.s=i.s;
	val.e=j.e;
	val.l=i.l,val.r=i.r;
	val.len=i.len;
	val.h=i.h;
	val.sz=i.sz+j.sz;
	
	int middle=i.e+j.s; //add position to left side if needed
	if (middle%2==1){
		if (j.e==j.sz){
			val.e++;
		}
		else if (i.e==i.sz){
			val.s=1;
		}
		else if (val.l==-1){
			val.l=i.sz-i.e;
			val.r=i.e-1;
			val.len++;
		}
		else{
			int temp=val.r;
			val.r=i.e-1;
			//cout<<"diff: "<<temp-val.r<<endl;
			val.h=(val.h+powP[val.len]*hashes[temp-val.r])%MOD;
			val.len++;
		}
		
		middle--;
	}
	val.e+=middle;
	
	//merge both hashes
	if (val.l!=-1 && j.l!=-1){
		//cout<<"diff: "<<val.r+j.l-middle+1<<endl;
		val.h=(val.h+powP[val.len]*(hashes[val.r+j.l-middle+1]+j.h))%MOD;
		val.len+=j.len;
		
		val.r=j.r+middle;
	}
	else if (val.l!=-1){
		val.r+=j.sz;
	}
	else if (j.l!=-1){
		val.l=j.l+i.sz-middle,val.r=j.r+middle;
		val.len=j.len;
		val.h=j.h;
	}
	
	return val;
}

int n;
string st;

struct node{
	int s,e,m;
	range val;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			val=merge(l->val,r->val);
		}
		else{
			if (st[s]=='0'){
				val.s=0,val.e=0;
				val.l=-1,val.r=0;
				val.len=0;
				val.h=0;
				val.sz=1;
			}
			else{
				val.s=0,val.e=1;
				val.l=-1,val.r=0;
				val.len=0;
				val.h=0;
				val.sz=1;
			}
		}
		
		//cout<<s<<" "<<e<<" "<<val.s<<" "<<val.e<<" "<<val.l<<" "<<val.r<<" "<<val.len<<" "<<val.h<<endl;
	}
	
	range query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return merge(l->query(i,m),r->query(m+1,j));
	}
}*root;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//rep(x,0,200005) hashes[x]=x;
	rep(x,0,200005) hashes[x]=rng()%MOD;
	
	powP[0]=1;
	rep(x,1,200005) powP[x]=(powP[x-1]*P)%MOD;
	
	/*
	range A,B;
	cin>>A.s>>A.e>>A.l>>A.r>>A.len>>A.h>>A.sz;
	cin>>B.s>>B.e>>B.l>>B.r>>B.len>>B.h>>B.sz;
	
	A=merge(A,B);
	
	cout<<A.s<<" "<<A.e<<" "<<A.l<<" "<<A.r<<" "<<A.len<<" "<<A.h<<" "<<A.sz<<endl;
	return 0;
	*/
	
	cin>>n;
	cin>>st;
	
	root=new node(0,n-1);
	
	int q,a,b,c;
	cin>>q;
	while (q--){
		cin>>a>>b>>c;
		a--,b--;
		
		range r1=root->query(a,a+c-1),r2=root->query(b,b+c-1);
		
		//cout<<r1.s<<" "<<r1.e<<" "<<r1.l<<" "<<r1.r<<" "<<r1.len<<" "<<r1.h<<endl;
		//cout<<r2.s<<" "<<r2.e<<" "<<r2.l<<" "<<r2.r<<" "<<r2.len<<" "<<r2.h<<endl;
		
		if (r1.s==r2.s && r1.e==r2.e &&
			r1.l==r2.l && r1.r==r2.r &&
			r1.h==r2.h && r1.len==r2.len) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}