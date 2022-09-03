#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
	node *l,*r;
	int a,b;
	int tag;
	int sum;
	node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(-1),sum(0){

	}
}*root;
int Sum(node *n){
	if(n->tag==-1)return n->sum;
	return n->tag?n->b-n->a+1:0;
}
void pull(node *n){
	n->sum=Sum(n->l)+Sum(n->r);
}
void push(node *n){
	if(n->tag!=-1){
		n->l->tag=n->tag;
		n->r->tag=n->tag;
		n->tag=-1;
	}
}
void build(node *n,char *c){
	if(n->a==n->b){
		n->sum=c[n->a]-'0';
		return;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l,c);
	build(n->r,c);
	pull(n);
}
void add(node *n,int l,int r,int k){
	if(n->a>=l&&n->b<=r){
		n->tag=k;
		return;
	}
	if(n->b<l||n->a>r)return;
	push(n);
	add(n->l,l,r,k);
	add(n->r,l,r,k);
	pull(n);
	//return res;
}
int query(node *n,int l,int r){
	if(n->a>=l&&n->b<=r){
		return Sum(n);
	}
	if(n->b<l||n->a>r)return 0;
	push(n);
	int res=query(n->l,l,r)+query(n->r,l,r);
	pull(n);
	return res;
}
vector<int> res;
void go(node *n){
	if(n->a==n->b){
		res.pb(Sum(n));
		delete n;
		return;
	}
	push(n);
	go(n->l);
	go(n->r);
	delete n;
}
	pii p[200005];
bool solve(){
	int n,q;
	scanf("%d %d",&n,&q);
	char c2[200005],c[200005];
	scanf("%s %s",c2+1,c+1);
	root=new node(1,n);
	build(root,c);
	int ok=1;

	for(int i = 0;i<q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
	}
	reverse(p,p+q);
	for(int i = 0;i<q;i++){
		int l,r;
		tie(l,r)=p[i];
		//scanf("%d %d",&l,&r);
		int x=query(root,l,r);
		if((r-l+1)%2==0&&(r-l+1)/2==x){
			ok=0;
		}
		if(x<=(r-l+1)/2){
			add(root,l,r,0);
		}
		else{
			add(root,l,r,1);
		}
		//printf("%d\n",ok);
	}
	if(!ok)printf("NO\n");
	else{
		res.clear();
		go(root);
		for(int i = 0;i<res.size();i++){
			if(c2[i+1]-'0'!=res[i]){
				ok=0;
			}
		}
		if(!ok)printf("NO\n");
		else printf("YES\n");
	}
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/