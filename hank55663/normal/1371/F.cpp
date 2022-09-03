#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
	node *l,*r;
	int pre,suf,ans;
	int preans,sufans;
	int rpre,rsuf,rans;
	int rpreans,rsufans;
	int tag;
	int a,b;
	node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
		pre=suf=ans=0;
		preans=sufans=0;
		rpre=rsuf=rans=0;
		rpreans=rsufans=0;
		tag=0;
	}
	void print(){
		printf("pre %d suf %d ans %d\n",pre,suf,ans);
		printf("preans %d sufans %d\n",preans,sufans);
		printf("tag %d\n",tag);
		printf("rpre %d rsuf %d rans %d\n",rpre,rsuf,rans);
		printf("rpreans %d rsufans %d\n",rpreans,rsufans);
	}
}*root;
int pre(node *n,int tag=0){
	if(n->tag^tag)return n->rpre;
	else return n->pre;
}
int suf(node *n,int tag=0){
	if(n->tag^tag)return n->rsuf;
	else return n->suf;
}
int ans(node *n,int tag=0){
	if(n->tag^tag)return n->rans;
	else return n->ans;
}
int preans(node *n,int tag=0){
	if(n->tag^tag)return n->rpreans;
	return n->preans;
}
int sufans(node *n,int tag=0){
	if(n->tag^tag)return n->rsufans;
	return n->sufans;
}
void pull(node *n){
	if(pre(n->l)==n->l->b-n->l->a+1){
		n->pre=pre(n->l)+pre(n->r);
	}
	else{
 		n->pre=pre(n->l);
	}
	if(suf(n->l)==n->l->b-n->l->a+1){
		n->preans=suf(n->l)+preans(n->r);
	}
	else if(preans(n->l)==n->l->b-n->l->a+1)n->preans=preans(n->l)+pre(n->r);
	else n->preans=preans(n->l);
	if(suf(n->r)==n->r->b-n->r->a+1)n->suf=suf(n->r)+suf(n->l);
	else n->suf=suf(n->r);
	if(pre(n->r)==n->r->b-n->r->a+1){
		n->sufans=pre(n->r)+sufans(n->l);
	}
	else if(sufans(n->r)==n->r->b-n->r->a+1){
		n->sufans=sufans(n->r)+suf(n->l);
	}
	else{
		n->sufans=sufans(n->r);
	}
	n->ans=max(max(ans(n->l),ans(n->r)),max(preans(n->r)+suf(n->l),sufans(n->l)+pre(n->r)));
///////////////////////////////////////
	if(pre(n->l,1)==n->l->b-n->l->a+1){
		n->rpre=pre(n->l,1)+pre(n->r,1);
	}
	else{
 		n->rpre=pre(n->l,1);
	}
	if(suf(n->l,1)==n->l->b-n->l->a+1){
		n->rpreans=suf(n->l,1)+preans(n->r,1);
	}
	else if(preans(n->l,1)==n->l->b-n->l->a+1)n->rpreans=preans(n->l,1)+pre(n->r,1);
	else n->rpreans=preans(n->l,1);
	if(suf(n->r,1)==n->r->b-n->r->a+1)n->rsuf=suf(n->r,1)+suf(n->l,1);
	else n->rsuf=suf(n->r,1);
	if(pre(n->r,1)==n->r->b-n->r->a+1){
		n->rsufans=pre(n->r,1)+sufans(n->l,1);
	}
	else if(sufans(n->r,1)==n->r->b-n->r->a+1){
		n->rsufans=sufans(n->r,1)+suf(n->l,1);
	}
	else{
		n->rsufans=sufans(n->r,1);
	}
	n->rans=max(max(ans(n->l,1),ans(n->r,1)),max(preans(n->r,1)+suf(n->l,1),sufans(n->l,1)+pre(n->r,1)));

}
void push(node *n){
	n->l->tag^=n->tag;
	n->r->tag^=n->tag;
	n->tag=0;
}
void build(node *n,char *c){
	if(n->a==n->b){
		if(c[n->a]=='<')n->pre=n->preans=n->sufans=n->ans=n->rsuf=n->rsufans=n->rpreans=n->rans=1;
		else            n->suf=n->sufans=n->preans=n->ans=n->rpre=n->rpreans=n->rsufans=n->rans=1;
		return ;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l,c);
	build(n->r,c);
	pull(n);
}
node revise(node *n,int l,int r){
	if(n->a>=l&&n->b<=r){
		n->tag^=1;
		return *n;
	}
	if(n->b<l||n->a>r){
		return node(0,0);
	}
	push(n);
	node ln=revise(n->l,l,r);
	node rn=revise(n->r,l,r);
		pull(n);
	if(ans(&ln)==0)return rn;
	if(ans(&rn)==0)return ln;
	ln.a=max(ln.a,l);
	rn.b=min(rn.b,r);
	node res(max(n->a,l),min(n->b,r));
	//printf("%d %d\n",n->l->a,n->l->b);
//	ln.print();
	res.l=&ln;
	//printf("%d %d\n",n->r->a,n->r->b);
	//rn.print();
	//printf("???\n");
	//n->r->print();
	res.r=&rn;
	pull(&res);

	return res;
}
int main() {
	int n,q;
	scanf("%d %d",&n,&q);
	char c[500005];
	scanf("%s",c+1);
	root=new node(1,n);
	build(root,c);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		node res=revise(root,l,r);
		printf("%d\n",ans(&res));
	//	res.print();
	}
	return 0;
}