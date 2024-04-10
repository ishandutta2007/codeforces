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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct trie{
	struct node{
		node* n[26];
		int pri;
		node(){
			for(int i=0;i<26;i++)
			n[i]=NULL;
			pri=-1;
		}
	};
	node *root[100005];
	trie(){
		root[0]=new node();
	}
	node* Clone(node *n){
		node *res=new node();
		if(!n)
		return res;
		for(int i=0;i<26;i++)
		res->n[i]=n->n[i];
		res->pri=n->pri;
		return res;
	}
	void add(int i,char *c,int pri){
		node * n=root[i];
		for(int j=0;c[j]!=0;j++){
			n->n[c[j]-'a']=Clone(n->n[c[j]-'a']);
			n=n->n[c[j]-'a'];
		}
		n->pri=pri;
	}
	int query(int i,char *c){
		root[i]=Clone(root[i-1]);
		
		node *n=root[i];
		for(int j=0;c[j]!=0;j++){//printf("1");
			if(!n->n[c[j]-'a'])
			return -1;
			n=n->n[c[j]-'a'];
		}
		return n->pri;
	}
	void back(int i,int k){
		root[i]=Clone(root[i-k-1]);
	}
}tree;
struct BT{
	struct node{
		int a,b;
		node *l,*r;
		int num;
		int sum;
		node(int _a,int _b):a(_a),b(_b){
			l=NULL;
			r=NULL;
			num=0;
			sum=0;
		}
	};
	node *root[100005];
	BT(){
		root[0]=new node(1,1e9);
	}
	node * Clone(node *n){
		node *res=new node(n->a,n->b);
		res->l=n->l;
		res->r=n->r;
		res->num=n->num;
		res->sum=n->sum;
		return res;
	}
	int Sum(node *n){
		return n?n->sum+n->num:0;
	}
	void pull(node *n){
		n->sum=Sum(n->l)+Sum(n->r);
	}
	void add(int i,int p,int k){
		node *n = root[i];
		vector<node *>v;
		while(1){
			int mid=(n->a+n->b)/2;
			v.pb(n);
			if(mid==p)
			break;
			if(mid<p){
				if(n->r)
				n->r=Clone(n->r);
				else
				n->r=new node(mid+1,n->b);
				n=n->r;
			}
			else{
				if(n->l)
				n->l=Clone(n->l);
				else
				n->l=new node(n->a,mid-1);
				n=n->l; 
			}
		}
		n->num+=k;
		while(!v.empty()){
		//	printf("%d\n",v.back());
			pull(v.back());
			v.pop_back();
		}
	}
	int query(int i,int p){
		root[i]=Clone(root[i-1]);
		node *n=root[i];
		int res=0;
		while(1){
			if(!n)
			break;
		//	printf("%d %d\n",n->a,n->b);
			int mid=(n->a+n->b)/2;
			if(mid<=p){
				res+=Sum(n->l);
				if(mid==p)
				break;
				res+=n->num;
				n=n->r;
			}
			else{
				n=n->l;
			}
		}
		return res;
	}
	void back(int i,int k){
		root[i]=Clone(root[i-k-1]);
	}
}bt;
int main(){
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){ 
		char c[10],c2[20];
		scanf("%s",c);
		if(c[0]=='s'){
			scanf("%s",c2);
			int k;
			scanf("%d",&k);
			int x=tree.query(i,c2);
		
			if(x==-1){
				tree.add(i,c2,k);
				bt.root[i]=bt.Clone(bt.root[i-1]);
				bt.add(i,k,1); 
			}
			else{
				tree.add(i,c2,k);
				bt.root[i]=bt.Clone(bt.root[i-1]);
				bt.add(i,x,-1);
				bt.add(i,k,1); 
			}
		}
		else if(c[0]=='r'){
			scanf("%s",c2);
			int x=tree.query(i,c2);
			if(x!=-1){
				tree.add(i,c2,-1);
				bt.root[i]=bt.Clone((bt.root[i-1]));
				bt.add(i,x,-1);
			}
			else{
				bt.back(i,0);
			}
		}
		else if(c[0]=='q'){
			scanf("%s",c2);
			int x=tree.query(i,c2);
		//	printf("%d\n",x);
			if(x==-1){
				bt.back(i,0);
				printf("-1\n");
			}
			else{
				printf("%d\n",bt.query(i,x));
			}
			fflush(stdout);
		}
		else if(c[0]=='u'){
			int k;
			scanf("%d",&k);
			tree.back(i,k);
			bt.back(i,k);
		}
	}
}