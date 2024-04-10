#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b)
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
#define seg pair<pii,pii>
//#define M 1000005
//#define pi 3.14159265359
#define count Count
using namespace std;
typedef long long LL;
vector<int> v[1000005];
int in[1000005];
int out[1000005];
int ans[1000005];
int t;
void dfs(int k,int f,int Min){
//	printf("%d %d\n",k,f);
	in[k]=++t;
	ans[in[k]]=min(Min,k);
//	printf("%d %d %\n",in[k],ans[in[k]]);
	for(int i=0;i<v[k].size();i++){
		if(v[k][i]!=f)
		dfs(v[k][i],k,ans[in[k]]); 
	}
	out[k]=t;
}
struct Node{
	Node *l,*r;
	int tag,Min,a,b;
	Node(int c,int d):a(c),b(d),l(NULL),r(NULL){
		if(c==d)
		Min=ans[c];
		tag=1e9;
	}
}*root;
void push(Node *n){
	if(!n->l){
		n->l=new Node(n->a,(n->a+n->b)/2);
		n->r=new Node((n->a+n->b)/2+1,n->b);
	}
	n->l->tag=min(n->l->tag,n->tag);
	n->r->tag=min(n->r->tag,n->tag);
} 
void revise(Node *n,int l,int r,int a){
//	printf("%d %d %d %d\n",l,r,n->a,n->b);
//	system("PAUSE");
	if(l>r)
	return ;
	if(n->a==l&&n->b==r)
	{
		n->tag=min(n->tag,a);
		return;
	}
	push(n);
	revise(n->l,l,min(n->l->b,r),a);
	revise(n->r,max(n->r->a,l),r,a);
}
int ask(Node *n,int x){
//	printf("%d %d %d\n",n->a,n->b,x);
//	system("PAUSE");
	if(n->a==x&&n->b==x)
	return min(n->tag,n->Min);
	push(n);
	if(x>(n->a+n->b)/2)
	return ask(n->r,x);
	else
	return ask(n->l,x);
}
int main()
{	
	t=0;
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	root=new Node(1,n);
	q--;
	int op,k,last=0;
	scanf("%d %d",&op,&k);
	k=k%n+1;
	dfs(k,0,1e9);
	while(q--){
		scanf("%d",&op);
		if(op==1){
			int x;
			scanf("%d",&x);
			x=(x+last)%n+1;
		//	printf("%d\n",x);
			revise(root,1,in[x]-1,ans[in[x]]);
			revise(root,out[x]+1,n,ans[in[x]]);			
		}
		else{
			int x;
			scanf("%d",&x);
			x=(x+last)%n+1;
		//	printf("%d\n",x);
		//	system("PAUSE");
			last=ask(root,in[x]);
			printf("%d\n",last);
		}
	}
}