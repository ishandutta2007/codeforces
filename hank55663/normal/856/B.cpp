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
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
struct node{
	node *n[26];
	int word;
	node(){
		MEM(n);
		word=0;
	} 
}*root;
vector<pair<node*,node*> > v[1000005];
int maxlen;
void add(char *c){
	node *n1=root;
	node *n2=root;
	if(!root->n[c[0]-'a'])
	root->n[c[0]-'a']=new node();
	n2=n2->n[c[0]-'a'];
	for(int i=1;c[i]!=0;i++){
		n2->word=1;
		if(!n1->n[c[i]-'a'])
		n1->n[c[i]-'a']=new node();
		if(!n2->n[c[i]-'a'])
		n2->n[c[i]-'a']=new node();
		n1=n1->n[c[i]-'a'];
		n2=n2->n[c[i]-'a'];
		v[i].pb(mp(n1,n2));
		maxlen=max(maxlen,i);
	}n2->word=1;
}
int cal(node *n){
	int sum=n->word;
	for(int i=0;i<26;i++){
		if(n->n[i])
		sum+=cal(n->n[i]);
	}
	return sum;
}
void erase(node *n){
	if(n){
		for(int i=0;i<26;i++)
		erase(n->n[i]);
		delete n;
	}
}
char c[1000005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){	
		root=new node();
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",c);
			add(c);
		}
		for(int i=maxlen;i>=1;i--){
			for(vector<pair<node*,node*> >::iterator it=v[i].begin();it!=v[i].end();it++){
				if(it->y->word==1)
				it->x->word=0;
			}
		}
		printf("%d\n",cal(root));
		erase(root);
		for(int i=1;i<=maxlen;i++)v[i].clear();
		
	}
}