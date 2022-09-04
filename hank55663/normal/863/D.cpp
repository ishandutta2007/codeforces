#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
struct node{
	node *l,*r;
	int rev;
	int k;
	int pri;
	int Size;
	node(int _k):l(NULL),r(NULL),rev(0),k(_k),pri(rand()),Size(1){
	}
}*root;
int Size(node *n){
	return n?n->Size:0;
} 
void pull(node *n){
	n->Size=Size(n->l)+Size(n->r)+1;
}
void push(node *n){
	if(n->rev){
		if(n->l)
		n->l->rev^=1;
		if(n->r)
		n->r->rev^=1;
		swap(n->l,n->r);
		n->rev=0;
	}
}
node* merge(node *a,node *b){
	if(!a||!b)return a?a:b;
	if(a->pri>b->pri){
		push(a);
		a->r=merge(a->r,b);
		pull(a);
		return a;
	}
	else{
		push(b);
		b->l=merge(a,b->l);
		pull(b);
		return b;
	}
} 
void split(node *t,int k,node *&a,node *&b){
	if(!t){
		a=b=NULL;
		return;
	}
	push(t);
	if(Size(t->l)<k){
		a=t;
		split(t->r,k-Size(t->l)-1,a->r,b);
		pull(a);
	}
	else{
		b=t;
		split(t->l,k,a,b->l);
		pull(b);
	}
}
int ans[200005];
int index;
void travel(node *n){
	push(n);
	if(n->l)
	travel(n->l);
	ans[++index]=n->k;
	if(n->r)
	travel(n->r);
}
int main(){
	index=0;
	int n ,q,m;
	scanf("%d %d %d",&n,&q,&m);
	root=NULL;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		root=merge(root,new node(a));
	}
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==2){
			int l,r;
			scanf("%d %d",&l,&r);
			node *a,*b;
			split(root,l-1,a,root);
			split(root,r-l+1,root,b);
			root->rev^=1;
			root=merge(a,merge(root,b));
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			node *a,*b,*c;
			split(root,l-1,a,root);
			split(root,r-l,b,root);
			split(root,1,c,root); 
			root=merge(merge(a,merge(c,b)),root);
		}
	}
	travel(root);
	while(m--) {
		int a;
		scanf("%d",&a);
		printf("%d ",ans[a]);
	} 
}
/*3 2 6 5 4 1
1 3 2 6 5 4*/