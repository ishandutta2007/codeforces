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

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=1000000007;
const int P=177013;

ll pow2[100200];
ll powp[100200];

struct node;

node *cache[2][270000];

struct node{
	int s,e,m;
	int len;
	int id;
	
	bool h0=false;
	ll h=0;
	ll v=0;
	node *l,*r;
	
	node (int _s,int _e,int _id,int val){
		s=_s,e=_e,m=s+e>>1;
		len=e-s+1;
		id=_id;
		
		if (val==0) h0=true;
		
		if (s!=e){
			l=new node(s,m,id<<1,val);
			r=new node(m+1,e,id<<1|1,val);
			
			h0=l->h0|r->h0;
			h=(l->h+powp[l->len]*r->h)%MOD;
			v=(l->v+r->v)%MOD;
		}
		else{
			if (val==0) h=601012521;
			else h=703511875;
			
			v=val*pow2[s];
		}
		
		cache[val][id]=this;
	}
	
	node (node *i){
		s=i->s,e=i->e,m=i->m;
		len=i->len;
		id=i->id;
		
		h0=i->h0;
		h=i->h;
		l=i->l,r=i->r;
	}
	
	void update(int i,int j,int k){
		if (j<=m){
			l=new node(l);
			if (s==i && m==j) l=cache[k][id<<1];
			else l->update(i,j,k);
		}
		else if (m<i){
			r=new node(r);
			if (m+1==i && e==j) r=cache[k][id<<1|1];
			else r->update(i,j,k);
		}
		else{
			l=new node(l);
			r=new node(r);
			if (s==i) l=cache[k][id<<1];
			else l->update(i,m,k);
			
			if (e==j) r=cache[k][id<<1|1];
			else r->update(m+1,j,k);
		}
		
		h0=l->h0|r->h0;
		h=(l->h+powp[l->len]*r->h)%MOD;
		v=(l->v+r->v)%MOD;
	}
	
	ll search(int i){
		if (!h0) return -1;
		if (s==e) return s;
		
		if (m<i) return r->search(i);
		else{
			int temp=l->search(i);
			if (temp!=-1) return temp;
			return r->search(i);
		}
	}
};

bool ncmp(node *i,node *j){
	if (i->s==i->e){
		return i->v<j->v;
	}
	if (i->r->h==j->r->h) return ncmp(i->l,j->l);
	else return ncmp(i->r,j->r);
}

int n,m;
vector<ii> al[100005];
node* w[100005];
int pp[100005];
int s,t;

#define wi pair<node*,int>

struct cmp{
	bool operator()(wi i,wi j){
		return ncmp(j.fi,i.fi);
	}
};

priority_queue<wi,vector<wi>,cmp> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	powp[0]=1;
	rep(x,1,100200) powp[x]=(powp[x-1]*P)%MOD;
	pow2[0]=1;
	rep(x,1,100200) pow2[x]=(pow2[x-1]*2)%MOD;
	
	new node(0,100100,1,0);
	new node(0,100100,1,1);
	
	cin>>n>>m;
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		
		al[a].pub(ii(b,c));
		al[b].pub(ii(a,c));
	}
	
	cin>>s>>t;
	
	w[s]=cache[0][1];
	pq.push(wi(w[s],s));
	
	node* weight;
	int id;
	while (!pq.empty()){
		tie(weight,id)=pq.top(),pq.pop();
		
		if (w[id]!=weight) continue;
		
		for (auto &it:al[id]){
			
			node* temp=new node(weight);
			int msb=temp->search(it.se);
			if (msb!=it.se) temp->update(it.se,msb-1,0);
			temp->update(msb,msb,1);
			
			if (w[it.fi]==0 || ncmp(temp,w[it.fi])){
				swap(w[it.fi],temp);
				pp[it.fi]=id;
				pq.push(wi(w[it.fi],it.fi));
			}
		}
	}
	
	if (w[t]==0){
		cout<<"-1"<<endl;
		return 0;
	}
	
	cout<<w[t]->v<<endl;
	
	vector<int> ans={t};
	int curr=t;
	while (curr!=s){
		curr=pp[curr];
		ans.pub(curr);
	}
	
	reverse(all(ans));
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it<<" "; cout<<endl;
}