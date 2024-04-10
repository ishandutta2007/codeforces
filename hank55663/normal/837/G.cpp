#include<stdio.h>
#include<algorithm> 
#include<map>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef unsigned long long LL;
struct Node{
	Node *l,*r;
	LL pro,sum;
	int a,b;
	Node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
		pro=0;
		sum=0;
	}
}*root[225000];
Node * Clone(Node *n){
//	printf("%d %d\n",n->a,n->b);
	Node *a=new Node(n->a,n->b);
	a->l=n->l;
	a->r=n->r;
	return a;
}
int x1[75005];
int x2[75005];
int y1[75005];
int a[75005];
int b[75005];
int y2[75005];
map<int,int> m;
void pull(Node *n){
	n->pro=n->l->pro+n->r->pro;
	n->sum=n->l->sum+n->r->sum; 
}
void build(Node *n){
	if(n->a==n->b){
		n->sum=y1[n->a-1];
		return;
	}
	int mid=(n->a+n->b)/2;
	n->l=new Node(n->a,mid);
	n->r=new Node(mid+1,n->b);
	build(n->l);
	build(n->r); 
	pull(n);
}
void revise(Node *n,int x,int type){
	if(n->a==x&&n->b==x){
		if(type==1)
		{
			n->pro=a[x-1];
			n->sum=b[x-1];
		}
		if(type==2){
			n->pro=0;
			n->sum=y2[x-1];
		}
		return;
	}
	if(n->l->b>=x){
		n->l=Clone(n->l);
		revise(n->l,x,type); 
	} 
	else{
		n->r=Clone(n->r);
		revise(n->r,x,type);
	}
	pull(n);
}
void init(int n){
	pair<int,pii> p[225000];
	int index=1;
	for(int i=0;i<n;i++){
		p[index++]=mp(x1[i],mp(i+1,1));
	}
	for(int i=0;i<n;i++){
		p[index++]=mp(x2[i],mp(i+1,2));
	}
	sort(p,p+index);
	root[0]=new Node(1,n);
	build(root[0]);
	for(int i=1;i<index;i++){
	//	printf("?");
		root[i]=Clone(root[i-1]);
//		printf("%d %d %d %d\n",i,p[i].x,p[i].y.x,p[i].y.y);
		revise(root[i],p[i].y.x,p[i].y.y);
		m[p[i].x]=i;
	}
}
pll query(Node *n,int l,int r){
//	printf("%d %d %d %d\n",l,r,n->a,n->b);
	if(l>r){
		return mp(0,0);
	}
	if(n->a==l&&n->b==r){
		return mp(n->pro,n->sum);
	}
	pll p1=query(n->l,l,min(r,n->l->b));
	pll p2=query(n->r,max(n->r->a,l),r);
	return mp(p1.x+p2.x,p1.y+p2.y);
}
int mod=1e9;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d %d %d",&x1[i],&x2[i],&y1[i],&a[i],&b[i],&y2[i]);
	}
	init(n);
	int q;
	scanf("%d",&q);
	LL last=0;
	while(q--){
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		x=(x+last)%mod;
		map<int,int>::iterator it=m.lower_bound(x);
		int num=0;
		if(it!=m.begin()){ 
			it--;
			num=it->y;
		} 
		//printf("%d\n",num);
		pll p=query(root[num],l,r);
		//printf("%I64d %I64d\n",p.x,p.y);
		printf("%I64d\n",last=p.x*x+p.y);
	}
}
/*141213562
/*
1 1 1 1 1 1 
1 2 3 4 5 6 
1 3 6 10 15 21
1 4 10 20 
1 5 15
1 6 21
*/
/*
  1 2 3 3 5 6
0 1 2 3 4 5 6
*/