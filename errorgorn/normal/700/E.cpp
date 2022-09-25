//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=998244353;
const int P=177013;
const int invP=946942873;

int base[30];
int pp[200005];
int ip[200005];
int pref[200005];

int get(int l,int r){
	return (pref[r+1]-pref[l]+MOD)*ip[l]%MOD;
}

int n;
string s;

int sa[200005];
int ra[200005];

int sa2[200005];
int ra2[200005];
int cnt[200005];

int lcp[200005];

struct node{
	int s,e,m;
	int val;
	node *l,*r;
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			val=min(l->val,r->val);
		}
		else{
			val=lcp[s];
		}
	}
	
	int findl(int i,int k){ //find something that is <k
		if (val>=k) return -1;
		if (s==e) return s;
		if (i<=m) return l->findl(i,k);
		else{
			int temp=r->findl(i,k);
			if (temp==-1) return l->findl(i,k);
			else return temp;
		}
	}
	
	int findr(int i,int k){ //find something that is <k
		if (val>=k) return -1;
		if (s==e) return s;
		if (m<i) return r->findr(i,k);
		else{
			int temp=l->findr(i,k);
			if (temp==-1) return r->findr(i,k);
			else return temp;
		}
	}
} *root;

struct node2{
	int s,e,m;
	int val=1e9;
	node2 *l,*r;
	
	node2 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void update(int i,int k){
		val=min(val,k);
		if (s==e) return;
		if (i<=m) l->update(i,k);
		else r->update(i,k);
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
} *root2=new node2(0,200005);

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	cin>>s;
	
	rep(x,0,30) base[x]=rng()%MOD;
	pp[0]=ip[0]=1;
	rep(x,1,200005){
		pp[x]=pp[x-1]*P%MOD;
		ip[x]=ip[x-1]*invP%MOD;
	}
	rep(x,0,sz(s)) pref[x+1]=(pref[x]+base[s[x]-'a']*pp[x])%MOD;
	
	s+="$";
	
	rep(x,0,sz(s)) sa[x]=x;
	rep(x,0,sz(s)) ra[x]=s[x];
	
	rep(x,0,20){
		int mov=x?(1<<(x-1))%sz(s):0;
		
		memset(cnt,0,sizeof(cnt));
		rep(x,0,sz(s)) cnt[ra[x]]++;
		rep(x,1,200005) cnt[x]+=cnt[x-1];
		
		rep(x,sz(s),0){
			int pos=(sa[x]-mov+sz(s))%sz(s);
			sa2[--cnt[ra[pos]]]=pos;
		}
		
		int IDX=ra2[sa2[0]]=0;
		rep(x,1,sz(s)){
			if (ra[sa2[x-1]]!=ra[sa2[x]] || ra[(sa2[x-1]+mov)%sz(s)]!=ra[(sa2[x]+mov)%sz(s)]) IDX++;
			ra2[sa2[x]]=IDX;
		}
		
		swap(sa,sa2);
		swap(ra,ra2);
	}
	
	int curr=0;
	rep(x,0,n) if (ra[x]!=sz(s)-1){
		int y=sa[ra[x]+1];
		while (s[(curr+x)%sz(s)]==s[(curr+y)%sz(s)]) curr++;
		lcp[ra[x]]=curr;
		if (curr) curr--;
	}
	
	//rep(x,0,sz(s)) cout<<lcp[x]<<" "<<s.substr(sa[x],sz(s)-sa[x])<<endl;
	root=new node(0,sz(s));
	
	int ans=0;
	rep(x,n,0){
		int r=x,pp=1;
		int curr=1;
		
		while (true){
			int lo=0,hi=(n-1-r)/pp+1,mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (get(x,r+(mi-1)*pp)==get(x+pp,r+mi*pp)) lo=mi;
				else hi=mi;
			}
			
			curr+=lo;
			r+=pp*lo;
			
			int ql=root->findl(ra[x]-1,r-x+1)+1;
			int qr=root->findr(ra[x],r-x+1);
			
			int nxt=root2->query(ql,qr)+(r-x);
			if (nxt>=1e8) break;
			pp=nxt-r;
			r=nxt;
			curr++;
		}
		
		ans=max(ans,curr);
		
		root2->update(ra[x],x);
	}
	
	cout<<ans<<endl;
}