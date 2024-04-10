#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
struct node{
	node *l,*r;
	int k;
	node():l(NULL),r(NULL){
		k=0; 
	}
}*root;
int k;
void build(node *n,int l,int r){
	if(l==r){
		n->k=l;
		return ;
	}
	int mid=(l+r)/2;
	n->l=new node();
	n->r=new node();
	if(k<=0){
		build(n->l,l,mid);
		build(n->r,mid+1,r);
	}
	else{
		k-=2;
		if((r-l)%2==0){
		build(n->l,mid+1,r);
		build(n->r,l,mid);
		}	
		else{
			build(n->l,mid+1,r);
			build(n->r,l,mid);
		}
	
	}
}
void print(node *n){
	if(!n->l){
		printf("%d ",n->k);
	} 
	else{
		print(n->l);
		print(n->r);
	}
}
int main() {
	int n;
	scanf("%d %d",&n,&k);
	k--;
	root = new node();
	build(root,1,n);
	if(k!=0){
		printf("-1\n");
	}
	else{
		print(root);
	}
}