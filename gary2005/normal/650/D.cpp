/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct node{
	int v1=0,v2=0,delta=0;
};
node tmp;
node merge(node A,node B,int save){
	tmp.v1=max(A.v1,B.v1);
	tmp.v2=max(A.v2,B.v2);
	tmp.delta=save;
	return tmp;
}
void update(node& A){
	A.v2=max(A.v2,A.v1+A.delta);
}
const int N=1<<19;
node tree[400000*4];
void change(int index,int val){
	index+=N-1;
	tree[index].v1=val;
	tree[index].v2=-1;
	update(tree[index]);
	index>>=1;
	while(index){
		tree[index]=merge(tree[index<<1],tree[(index<<1)+1],tree[index].delta);
		update(tree[index]);
		index>>=1;
	}
}
node turn(int a,int b,int val,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return tree[now];	
	}
	if(r<=b&&l>=a){
//		cout<<"now"<<"!"<<" "<<l<<" "<<r<<" "<<now<<endl;
		tree[now].delta=max(tree[now].delta,val);
		update(tree[now]);
		return tree[now];
	}
	int mid=(l+r)>>1;
	turn(a,b,val,now<<1,l,mid);
	turn(a,b,val,(now<<1)+1,mid,r);
	tree[now]=merge(tree[now<<1],tree[(now<<1)+1],tree[now].delta);
	update(tree[now]);
	return tree[now];
}
int query1(int a,int b,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return 0;
	}
	if(r<=b&&l>=a){
		return tree[now].v1;
	}
	int mid=(l+r)>>1;
	return max(query1(a,b,now<<1,l,mid),query1(a,b,(now<<1)+1,mid,r)); 
} 
void push_off(int index){
	tree[index<<1].delta=max(tree[index<<1].delta,tree[index].delta);
	tree[(index<<1)+1].delta=max(tree[(index<<1)+1].delta,tree[index].delta);
	tree[index].delta=0;
	update(tree[index<<1]);
	update(tree[(index<<1)+1]);
	tree[index]=merge(tree[index<<1],tree[(index<<1)+1],0);
	update(tree[index]);
}
int query2(int a,int b,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return 0;
	}
	if(r<=b&&l>=a){
		return tree[now].v2;
	}
	cout<<tree[now].delta<<endl;
	push_off(now);
	cout<<now<<" "<<l<<" "<<r<<" "<<tree[now<<1].delta<<""<<endl;
	int mid=(l+r)>>1;
	return max(query2(a,b,now<<1,l,mid),query2(a,b,(now<<1)+1,mid,r));
} 
mp change1[400000+2];/*index,prev-value*/
vector<int> v;
map<int,int> M;
int cnt=0;
int lowerbound(int val){
	return M[*lower_bound(ALL(v),val)];
}
int upperbound(int val){
	return M[*upper_bound(ALL(v),val)];
}
vector<pair<mp,int> > queries;
int h[400000+20],res[400000+20];
int simpletree[400000*4];
int query(int a,int b,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return 0;
	}
	if(r<=b&&l>=a){
		return simpletree[now];
	}
	int mid=(l+r)>>1;
	return max(query(a,b,now<<1,l,mid),query(a,b,(now<<1)+1,mid,r)); 
}
void change_s(int index,int val){
	index+=N-1;
	simpletree[index]=val;
	index>>=1;
	while(index)
		simpletree[index]=max(simpletree[index<<1],simpletree[(index<<1)+1]),index>>=1;
}
int main(){
	fastio;
	v.PB(INF);
	v.PB(-INF);
	int n,m;
	cin>>n>>m;
	rb(i,1,n) cin>>h[i],v.PB(h[i]);
	sort(ALL(v));
	for(auto it:v){
		M[it]=++cnt;
	} 
	rb(i,1,n) h[i]=M[h[i]];
	rb(i,1,m){
		int index,val;
		cin>>index>>val;
		queries.PB(II(II(index,val),i));
	}
	sort(ALL(queries));
	reverse(ALL(queries));
	rb(i,1,n){
		int prev=tree[h[i]+N-1].v1;
		change(h[i],query1(1,h[i])+1);
		change1[i]=II(h[i],prev);
//		cout<<h[i]<<" "<<prev<<endl;
	}
//	cout<<query1(1,N+1)<<endl;
	int id=0;
	rl(i,n,1){
		if(i!=n){
			int is=query(h[i+1]+1,N+1)+1;
			change_s(h[i+1],is);
//			cout<<1<<" "<<" "<<h[i+1]<<" "<<is<<endl;
			turn(1,h[i+1],is);
		} 
		change(change1[i].FIR,change1[i].SEC);
//		cout<<i<<"*"<<query2(1,N+1)<<endl;
//		cout<<"*"<<query2(1,2)<<endl;
//		cout<<tree[131072].delta<<endl;
//		query2(1,2);
//		cout<<"---------"<<endl;
//		if(0)
		while(id<m&&queries[id].FIR.FIR==i){
			int NOW=lowerbound(queries[id].FIR.SEC);
			res[queries[id].SEC]=max(query2(1,N+1),query1(1,NOW)+1+query(upperbound(queries[id].FIR.SEC),N+1));
			id++;
		}
	}
	rb(i,1,m) cout<<res[i]<<endl;
	return 0;
}