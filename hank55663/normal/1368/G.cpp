#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> E[400005];
int val[400005];
int Val(int x){
	if(val[x]!=0)return val[x];
	val[x]=1;
	for(auto it:E[x]){
		val[x]+=Val(it);
		//printf("%d %d\n",x,it);
	}
	return val[x];
}
vector<int> tag[400005];
struct node{
	node *l,*r;
	int a,b;
	int tag;
	int sum;
	node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(0),sum(0){

	}
}*root;
int sum(node *n){
	if(n->tag)return n->b-n->a+1;
	return n->sum;
}
void pull(node *n){
	n->sum=sum(n->l)+sum(n->r);
}
void build(node *n){
	if(n->a==n->b)return;
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
}
void add(node *n,int l,int r,int k){
	if(n->a>=l&&n->b<=r){
		n->tag+=k;
		return ;
	}
	if(n->b<l||n->a>r)return ;
	add(n->l,l,r,k);
	add(n->r,l,r,k);
	pull(n);
}
int t;
int in[400005],out[400005];
void dfs1(int x){
	in[x]=++t;
	for(auto it:E[x]){
		dfs1(it);
	}
	out[x]=t;
//	printf("%d in:%d out:%d\n",x,in[x],out[x]);
}
LL ans=0;
void dfs2(int x){
	for(auto it:tag[x]){
		add(root,in[it],out[it],1);
	//	printf("?%d %d %d\n",it,in[it],out[it]);
	}
	ans+=sum(root);
	//printf("%d %d\n",x,sum(root));
	for(auto it:E[x])dfs2(it);
	for(auto it:tag[x]){
		add(root,in[it],out[it],-1);
	}
}
int degree[400005];
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
/*	for(int i =0;i<n*m;i++){
		f[i]=i;
		Size[i]=1;
	}*/
	vector<string> v;
	for(int i = 0;i<n;i++){
		char c[200005];
		scanf("%s",c);
		v.pb(string(c));
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int x=i,y=j+1;
			if(y<m){
				if(v[x][y]=='L'){
					E[i*m+j].pb(x*m+y+1);
					degree[x*m+y+1]++;
				}
			}
			x=i,y=j-1;
			if(y>=0){
				if(v[x][y]=='R'){
					E[i*m+j].pb(x*m+y-1);
					degree[x*m+y-1]++;
				}
			}
			x=i+1,y=j;
			if(x<n){
				if(v[x][y]=='U'){
					E[i*m+j].pb((x+1)*m+y);
					degree[(x+1)*m+y]++;
				}
			}
			x=i-1,y=j;
			if(x>=0){
				if(v[x][y]=='D'){
					E[i*m+j].pb((x-1)*m+y);
					degree[(x-1)*m+y]++;
				}
			}
		}
	}
	//LL ans=0;
	for(int i = 0;i<n*m;i++){
		Val(i);
	}
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			if(v[i][j]=='U'){
				int a=i*m+j,b=(i+1)*m+j;
			//	if(s.find(mp(a,b))==s.end()){
			//		s.insert(mp(a,b));
				if((i+j)%2==0)tag[a].pb(b);
				else tag[b].pb(a);
				//ans+=Val(a)*1ll*Val(b);
			//	}
			}
			else if(v[i][j]=='L'){
				int a=i*m+j,b=i*m+j+1;
				//if(s.find(mp(a,b))==s.end()){
			//		s.insert(mp(a,b));
				if((i+j)%2==0)tag[a].pb(b);
				else tag[b].pb(a);
					//ans+=Val(a)*1ll*Val(b);
			//	}
			}
		}
	}
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if((i+j)%2==1)
			if(degree[i*m+j]==0)dfs1(i*m+j);
		}
	}
	root=new node(1,t);
	build(root);
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if((i+j)%2==0)
			if(degree[i*m+j]==0)dfs2(i*m+j);
		}
	}
//	printf("%lld\n",ans);
	
	printf("%lld\n",ans);
	return 0;
}