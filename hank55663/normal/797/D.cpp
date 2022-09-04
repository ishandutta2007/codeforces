//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
struct node{
	node *l,*r;
	int i,k;
	node(int _i,int _k):l(NULL) ,r(NULL),i(_i),k(_k){
	}
};
int a[100005],l[100005],r[100005];
void build(node *n){
	if(l[n->i]!=-1){
		n->l=new node(l[n->i],a[l[n->i]]);
		build(n->l);
	}
	if(r[n->i]!=-1){
		n->r=new node(r[n->i],a[r[n->i]]);
		build(n->r); 
	}
}
int ans=0;
vector<int> v;
set<int> s; 
void Find(node *n,int l,int r){
//	printf("%d %d %d\n",l,r,n->k);
	if(n->k<l||n->k>r)
	ans++,v.pb(n->k);
	else
	s.insert(n->k);
	if(n->l){
		Find(n->l,l,min(n->k,r));
	}
	if(n->r){
		Find(n->r,max(l,n->k),r);
	}
}
int main(){
	int p[100005];
	MEM(p);	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i],&l[i],&r[i]);
		if(l[i]!=-1)
		p[l[i]]=1;
		if(r[i]!=-1)
		p[r[i]]=1;
	}
	node *root;
	for(int i=1;i<=n;i++)
	if(p[i]==0){
		root=new node(i,a[i]);
		build(root);
	}
	Find(root,0,1e9);
	for(int i=0;i<v.size();i++)
	if(s.find(v[i])!=s.end())
	ans--;
	printf("%d\n",ans);
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
*/