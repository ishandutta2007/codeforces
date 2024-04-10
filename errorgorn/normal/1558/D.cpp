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

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

struct treap{
	unsigned long long priority; //higher priority means higher on the heap
	ll val,lazy=0;
	int cnt=1;

	treap *l=nullptr,*r=nullptr;

	treap(ll val){
		this->val=val;
		priority=rng(); //remember to copy rng struct
	}
}*root=nullptr;

int count(treap *item){
	if (item==nullptr) return 0;
	return item->cnt;
}

void upd(treap *item){
	if (item==nullptr) return;
	item->cnt=1+count(item->l)+count(item->r);
}
	
void push(treap *item){
	if (item==nullptr) return;

	item->val+=item->lazy;
	if (item->l!=nullptr) 
		item->l->lazy+=item->lazy;
	if (item->r!=nullptr)
		item->r->lazy+=item->lazy;
	item->lazy=0;	
}
	
void split(treap *item,treap *&lp, treap *&rp,int key,int add=0){ 
	//split node into 2 trees rooted at lp and rp
	if (item==nullptr){
		lp=rp=nullptr;
		return;
	}
	
	push(item);
		
	int curr_key=add+(item->l==nullptr?0:item->l->cnt);
	if (item->val>=key){ //split at left child
		rp=item;
		split(item->l,lp,item->l,key,add);
	}
	else{ //split at right 
		lp=item;
		split(item->r,item->r,rp,key,curr_key+1);
	}
	upd(item);
}

void merge(treap *&item,treap *lp, treap *rp){
	push(lp);
	push(rp);

	if (lp==nullptr || rp==nullptr){
		if (lp==nullptr) item=rp;
		else item=lp;
	}
	else if (lp->priority>rp->priority){
		item=lp;
		merge(lp->r,lp->r,rp);
	}
	else{
		item=rp;
		merge(rp->l,lp,rp->l);
	}
	upd(item);
}
	
ll get(treap *item,int key){
	push(item);
	
	if (item==nullptr) return 0;
	if (key==item->val) return 1;
	else if (key<item->val) return get(item->l,key);
	else return get(item->r,key);
}

void insert(treap *item,int pos){ //you can insert more than 1 node only
	treap *t1,*t2;
	split(root,t1,t2,pos);
	merge(root,t1,item);
	merge(root,root,t2);
}

treap* remove(int i,int j){ //[i,j]
	treap *t1,*t2,*t3;
	split(root,t2,t3,j+1);
	split(t2,t1,t2,i);
	merge(root,t1,t3);
	return t2;
}

void add(int i,int j,ll k){ //[i,j]
	treap *t1,*t2,*t3;
	split(root,t2,t3,j+1);
	split(t2,t1,t2,i);
	t2->lazy+=k;
	merge(root,t1,t2);
	merge(root,root,t3);
}

int n,m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		root=nullptr;
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			if (!get(root,b-1)){
				insert(new treap(b-1),b-1);
			}
			add(b-1,1e9,1);
		}
		
		int cnt=0;
		if (root!=nullptr) cnt=root->cnt;
		//cout<<cnt<<endl;
		
		cout<<nCk(n-1-cnt+n,n)<<endl;
	}
}