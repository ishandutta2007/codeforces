#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 800005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
using namespace std;
typedef long long LL;
struct Node{
	Node *l,*r;
	int tag;
	int Max;
	int a,b;
	Node(int c,int d):l(NULL),r(NULL),tag(0),Max(0),a(c),b(d){
	}
};
int Max(Node *n){
	return n->tag+n->Max; 
}
void push(Node *n){
	if(!n->l){
		int l=n->a,r=n->b; 
		n->l=new Node(n->a,(n->a+n->b)/2); 
		n->r=new Node((l+r)/2+1,r);
	} 
	n->l->tag+=n->tag;
	n->r->tag+=n->tag;
	n->tag=0;
}
void pull(Node *n){
	n->Max=max(Max(n->l),Max(n->r));
}
int dp[35005][55];
void build(Node *n,int num){
	if(n->a==n->b){
		n->Max=dp[n->a-1][num];
		n->tag=0;
	}
	else{
		push(n);
		build(n->l,num);
		build(n->r,num);
		pull(n);
	}
}
void add(Node *n,int l,int r,int k){
	if(l>r)
	return;
	if(n->a==l&&n->b==r){
		n->tag+=k;
		return;
	}
	push(n);
	add(n->l,l,min(r,n->l->b),k);
	add(n->r,max(l,n->r->a),r,k);
	pull(n);
}
int query(Node *n,int l,int r){
	if(l>r)
	return 0;
	if(n->a==l&&n->b==r)
	return Max(n);
	push(n);
	int ans=max(query(n->l,l,min(n->l->b,r)),query(n->r,max(n->r->a,l),r));
	pull(n);
	return ans;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int last[35005];
	vector<int> v[35005];
	for(int i=0;i<=n;i++)
	v[i].pb(0);
	int a[35005];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		last[i]=v[a[i]].back();
		v[a[i]].pb(i); 
	}
	Node *root=new Node(1,n);
	MEM(dp);
	for(int i=1;i<=k;i++){
		build(root,i-1);
		for(int j=1;j<=n;j++){
			add(root,last[j]+1,j,1);
			dp[j][i]=query(root,1,j);
		}
	}
/*	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",dp[j][i]);
		printf("\n");
	}*/
	printf("%d\n",dp[n][k]);
}