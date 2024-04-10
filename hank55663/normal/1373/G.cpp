#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
	node *l,*r;
	int tag;
	int a,b;
	int Max;
	node(int _a,int _b):a(_a),b(_b),tag(0),l(NULL),r(NULL){

	}
}*root;
int Max(node *n){
	return n->Max+n->tag;
}
void pull(node *n){
	n->Max=max(Max(n->l),Max(n->r));
}
void push(node *n){
	n->l->tag+=n->tag;
	n->r->tag+=n->tag;
	n->tag=0;
}
void build(node *n){
	if(n->a==n->b){
		n->Max=n->a-1;
		return ;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
	pull(n);
}
void add(node *n,int l,int r,int k){
	if(n->a>=l&&n->b<=r){
		n->tag+=k;
		return ;
	}
	if(n->b<l||n->a>r){
		return ;
	}
	push(n);
	add(n->l,l,r,k);
	add(n->r,l,r,k);
	pull(n);
}
int query(node *n,int l,int r){
	if(n->a>=l&&n->b<=r){
		return Max(n);
	}
	if(n->b<l||n->a>r)return 0;
	push(n);
	int res=max(query(n->l,l,r),query(n->r,l,r));
	pull(n);
	return res;
}
int main() {
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	set<pii> s;
	multiset<int> s2;
	root = new node(1,3*n);
	build(root);
	for(int i = 0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(s.find(mp(x,y))==s.end()){
			s.insert(mp(x,y));
			y+=abs(x-k);
			s2.insert(y);
			add(root,1,y,1);
		}
		else{
			s.erase(mp(x,y));
			y+=abs(x-k);
			s2.erase(s2.find(y));
			add(root,1,y,-1);
		}
		if(s.empty()){
			printf("0\n");
		}
		else
		printf("%d\n",max(query(root,1,*s2.rbegin())-n,0));
	}
	return 0;
}