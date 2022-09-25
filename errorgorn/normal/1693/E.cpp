// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

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
		val=k;
		if (s==e) return;
		if (i<=m) l->update(i,k);
		else r->update(i,k);
		val=max(l->val,r->val);
	}
	
	int findl(int i,int k){
		if (val<k) return -1;
		if (s==e) return s;
		if (m<i) return r->findl(i,k);
		else{
			int temp=l->findl(i,k);
			if (temp==-1) return r->findl(i,k);
			else return temp;
		}
	}
	
	int findr(int i,int k){
		if (val<k) return -1;
		if (s==e) return s;
		if (i<=m) return l->findr(i,k);
		else{
			int temp=r->findr(i,k);
			if (temp==-1) return l->findr(i,k);
			else return temp;
		}
	}
} *root=new node(0,200005);

struct FEN{
	int arr[200005];
	
	void update(int i,int j){
		while (i<200005){
			arr[i]+=j;
			i+=i&-i;
		}
	}
	
	int query(int i){
		int res=0;
		while (i){
			res+=arr[i];
			i-=i&-i;
		}
		return res;
	}
	
	int query(int i,int j){
		return query(j)-query(i-1);
	}
} fen;

int n;
int arr[200005];

set<int> pos; //stores increasing and decreasing guys
set<int> top;
ii range[200005]; //where does this guy dominate

priority_queue<ii> pq;

void proc(int l,int r){
	if (arr[l]){
		auto it=top.ub(range[l].se);
		if (it!=top.begin()){
			int temp=*prev(it);
			if (l<temp){
				arr[temp]=arr[l];
				root->update(temp,arr[temp]);
				pq.push({arr[temp],temp});
				range[temp]={0,0};
			}
		}
	}
	if (arr[r]){
		auto it=top.lb(range[r].fi);
		if (it!=top.end()){
			int temp=*it;
			if (temp<r){
				arr[temp]=arr[r];
				root->update(temp,arr[temp]);
				pq.push({arr[temp],temp});
				range[temp]={0,0};
			}
		}
	}
	range[l].se=0;
	range[r].fi=0;
	
	int currl=l;
	while (true){
		int temp=root->findl(currl+1,arr[currl]+1);
		if (temp==-1) break;
		range[currl].se=temp-1;
		range[temp].fi=temp;
		pos.insert(temp);
		currl=temp;
	}
	
	int currr=r;
	while (true){
		int temp=root->findr(currr-1,arr[currr]+1);
		if (temp==-1) break;
		range[currr].fi=temp+1;
		range[temp].se=temp;
		pos.insert(temp);
		currr=temp;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	vector<int> idx;
	rep(x,1,n+1) idx.pub(x);
	sort(all(idx),[](int i,int j){
		return arr[i]<arr[j];
	});
	
	for (auto it:idx){
		root->update(it,arr[it]);
	}
	
	pos={0,n+1};
	proc(0,n+1);
	
	rep(x,1,n+1) pq.push({arr[x],x});
	
	long long ans=0;
	while (!pq.empty() && pq.top().fi){
		vector<int> temp;
		do{
			temp.pub(pq.top().se);
			pq.pop();
		} while (!pq.empty() && pq.top().fi==arr[temp.back()]);
		
		sort(all(temp));
		for (auto it:temp){
			root->update(it,0);
			if (!top.count(it)) fen.update(it,1);
			top.insert(it);
		}
		
		int l=temp.front(),r=temp.back();
		int l2=*prev(pos.find(l)),r2=*next(pos.find(r));
		
		ans+=fen.query(range[l].fi,range[r].se);
		
		pos.erase(l);
		pos.erase(r);
		proc(l2,r2);
	}
	
	cout<<ans<<endl;
}