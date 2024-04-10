#include<bits/stdc++.h>
struct Treap{
	Treap *l,*r;
	long long int pri,key,first,firstx,size,secondx,i;
	Treap(){
	}
	Treap(long long int _key,long long int a):l(NULL),r(NULL),pri(rand()),key(_key),size(1){
        first=_key;
        firstx=a;
        i=a;
        secondx=0;
	}
};
long long int size(Treap *t){
	return t? t->size:0;
}
void pull(Treap *t){
	t->size=size(t->l)+size(t->r)+1;
		t->first=t->key;
		t->firstx=t->i;
		t->secondx=0; 
	if(t->l){
		t->first=t->l->first;
		t->firstx=t->l->firstx;
		if(t->l->secondx!=0)
		t->secondx=t->l->secondx;
		else if(t->key!=t->l->first) 
		t->secondx=t->i;
	}
	if(t->r&&t->secondx==0){
		if(t->first==t->r->first){
			t->secondx=t->r->secondx;
		}
		else
		{
			t->secondx=t->r->firstx;
		}
	}
}
Treap* merge(Treap *a,Treap *b){
	if(!a)
	{
		return b;
	}
	if(!b){
		return a;
	}
	if(a->pri>b->pri){
		a->r=merge(a->r,b);
		pull(a);
		return a;
	}
	else{
		b->l=merge(a,b->l);
		pull(b);
		return b;
	}
}
void split(Treap *t,int k,Treap *&a,Treap *&b){
	if(!t)a=b=NULL;
	else if(k==0) a=NULL,b=t;
	else if(k==t->size)a=t,b=NULL;
	else if(size(t->l)<k){
		a=t;
		split(t->r,k-size(t->l)-1,a->r,b);
		pull(a);
	}
	else
	{
		b=t;
		split(t->l,k,a,b->l);
		pull(b);
	}
}
main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[200005];
	Treap* root=NULL;
	for(int i=1;i<=n;i++){
		scanf("%d\n",&a[i]); 
		root=merge(root,new Treap(a[i],i));
	}
	while(m--){
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		Treap *a,*b;
		split(root,l-1,a,root);
		split(root,r-l+1,root,b);
		if(x!=root->first)
		printf("%d\n",root->firstx);
		else{
			if(root->secondx==0)
			printf("-1\n");
			else
			printf("%d\n",root->secondx);
		}
		root=merge(a,merge(root,b));
	}
	return 0;
}