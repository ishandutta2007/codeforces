#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int myrand(){
	return rand()<<10+rand();
}
struct treap{
	treap *l,*r;
	int k,size;
	treap(int _k):l(NULL),r(NULL),k(_k),size(1){
	}
	treap(){
	}
}*root[100005];
vector<int> v[100005];
int Size(treap *&a){
	return a?a->size:0;
}
void pull(treap *&t){
	t->size=Size(t->l)+Size(t->r)+1;
}
treap *clone(treap *a){
	if(!a)return a;
	treap *t=new treap(a->k);
	t->l=a->l;
	t->r=a->r;
	t->size=a->size;
	return t; 
}
treap* merge(treap *a,treap *b){
	if(!a||!b)return a?clone(a):clone(b); 
	if(myrand()%(Size(a)+Size(b))<Size(a)){
	//	printf("1");
		treap *t=clone(a);
	//	printf("2");
		t->r=merge(a->r,b);
	//	printf("3");
		pull(t);
	//	printf("3");
		return t;
	}
	else{
	//	printf("1");
		treap *t=clone(b);
	//	printf("2");
		t->l=merge(a,b->l);
	//	printf("3");
		pull(t);
	//	printf("3");
		return t; 
	}
}
void split(treap *t,int k,treap *&a,treap *&b){
	if(!t)a=b=NULL;
	else if(t->k<k){

		a=clone(t);
		split(t->r,k,a->r,b);
		pull(a);
	}
	else{
	//	printf("%d %d\n",t->k,k);
		b=clone(t);
		split(t->l,k,a,b->l);
		pull(b);
	}
}
int main(){	
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<100005;i++)
	root[i]=NULL;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		v[a].pb(i);
		root[i]=new treap(i);
		root[i]=merge(root[i-1],root[i]);
		if(v[a].size()>k){
			int cut=v[a][v[a].size()-k-1];
			treap *a,*b;
			split(root[i],cut,a,root[i]);
			split(root[i],cut+1,b,root[i]);
			delete b;
			root[i]=merge(a,root[i]);
		}
	}

	int q;
	scanf("%d",&q);
	int last=0;
	treap *a;
	int l,r;
	while(q--){
		scanf("%d %d",&l,&r);
		l=(l+last)%n+1;
		r=(r+last)%n+1;
		if(l>r)
		swap(l,r);
		split(root[r],l,a,root[r]);
		last=Size(root[r]);
		root[r]=merge(a,root[r]);
		printf("%d\n",last);
	//	printf("%d\n",last);
	}
}