/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
mp tshirts[200000+20];
vector<int> pr;
bool cmp (mp A,mp B){
	if(A.SEC!=B.SEC){
		return A.SEC>B.SEC;
	}
	return  A.FIR<B.FIR;
}
int res[200000+20];
vector<mp> queries;
SRAND;
struct Treap{
	/*
	This is a "tiny" fhq-treap templet created by GWj on 13.8.2020
	What does this templet support?
	Just normal "Split","Merge" ,"add" and "insert".
	Can't "flip","reverse"...and so on        :(
	*/ 
	int root=0;
	struct node{
		int val,ran,l,r,delta,delta2,val2,oldid;
	};
	node v[200000+20];
	int cnt=0;
	int new_node(int val){
		if(!cnt){
			v[cnt]=(node{val,(int)random(INF),0,0,0,0,0,(int)cnt});
			cnt++;
		}
		v[cnt]=(node{val,(int)random(INF),0,0,0,0,0,(int)cnt});
		cnt++;
		return cnt-1;
	}
	void add2(int index){
		v[index].delta2++;
	}
	void add(int index,int val){
		v[index].delta+=val;
	}
	void push_down(int index){
		v[index].val+=v[index].delta; 
	if(v[index].l)	v[v[index].l].delta+=v[index].delta;
	if(v[index].r)	v[v[index].r].delta+=v[index].delta;
		v[index].delta=0;
		v[index].val2+=v[index].delta2;
	if(v[index].l)	v[v[index].l].delta2+=v[index].delta2;
	if(v[index].r)	v[v[index].r].delta2+=v[index].delta2;
		v[index].delta2=0;
	}
	void split(int base,int & x,int & y,int boundary){
		//take all elements <=boundary
		if(!base){
			x=y=0;
			return;
		} 
		push_down(base);
		if(v[base].val<=boundary){
			x=base;
			split(v[base].r,v[x].r,y,boundary);
		}
		else{
			y=base;
			split(v[base].l,x,v[y].l,boundary);
		}
	}
	int merge(int x,int y){
		if(x==0||y==0) return x+y;
		push_down(x);
		if(v[x].ran>v[y].ran){
			v[x].r=merge(v[x].r,y);
			return x;	
		}
		push_down(y);
		v[y].l=merge(x,v[y].l);
		return y;
	}
	int rest[200000+20]={0};
	void travel(int index){
		push_down(index);
		rest[v[index].oldid]=v[index].val2;
		if(v[index].l){
			travel(v[index].l);
		}
		if(v[index].r){
			travel(v[index].r);
		}
	}	
	inline void insert(int index){
		int l,r;
		split(root,l,r,v[index].val);
		l=merge(l,index);
		root=merge(l,r);
	}
}treap;

int main(){
//	freopen("test.in","r",stdin);
	fastio;	
	int n;
	R(n);
	rb(i,1,n)
		R2(tshirts[i].FIR,tshirts[i].SEC);
	sort(tshirts+1,tshirts+1+n,cmp);
	rb(i,1,n)
		pr.PB(tshirts[i].FIR);
	int k;
	R(k);
	rb(i,1,k){
		int u;
		R(u);
		queries.PB(II(u,i));
	}
	sort(ALL(queries));
	for(auto it:queries){
		treap.root=treap.merge(treap.root,treap.new_node(it.FIR));
	}
	for(auto it:pr){
//		cout<<it<<endl;
		int l=0,r=0;
		treap.split(treap.root,l,r,it-1);
//		cout<<"1"<<endl;
		treap.add(r,-it);
//		cout<<"2"<<endl;
		treap.add2(r);
//		cout<<"3"<<endl;
		int mid=0;
		treap.split(r,mid,r,it-1);
//		cout<<"5--"<<endl;
		treap.root=treap.merge(l,r);
//		cout<<"4"<<endl;
		queue<int> q;
		q.push(mid);
		int si=0;
		while(!q.empty()){
			si++;
			int now=q.front();
			q.pop();
			treap.push_down(now);
			if(treap.v[now].l)
			{
				q.push(treap.v[now].l);
			}
			if(treap.v[now].r){
				q.push(treap.v[now].r);
			}
			treap.v[now].l=treap.v[now].r=0;
			treap.insert(now);
			
		}
//		cout<<si<<endl;
//		treap.insert_treap(mid);
//		cout<<"6"<<endl;
	}
	treap.travel(treap.root);
	rep(i,k){
		res[queries[i].SEC]=treap.rest[i+1];
	}
	rb(i,1,k){
		cout<<res[i]<<" ";
	}
	return 0;
}