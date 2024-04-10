#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector> 
#include<algorithm>
using namespace std;
int n,q;
#define maxn 400010
#define nlogn 8000010 
char str[maxn];
int num1[maxn],num2[maxn],num3[maxn],zjr=0;//trie fail zjr
//AC_Machine
int ch[maxn][26],fa[maxn],fail[maxn];
int rt=1,cnt=1;
int root[maxn];
queue<int> Q;
void insert(int &k,int at,int up,int f,int id){
	int now=1;
	for(int i=1;i<=up;++i){
		int pre=now;
		if(!ch[now][str[i]-'a'])ch[now][str[i]-'a']=++cnt;
		now=ch[now][str[i]-'a'];
		fa[now]=pre;
	}
	num1[id]=now;
}
vector<int> G[maxn];
void Build_AC(){
	fail[rt]=0;
	Q.push(rt);
	int to;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		G[fail[k]].push_back(k);
		for(int i=0;i<26;++i){
			if(k==rt)to=rt;
			else to=ch[fail[k]][i];
			if(ch[k][i]){
				fail[ch[k][i]]=to;
				Q.push(ch[k][i]);
			}else ch[k][i]=to;
		}
	}
}
//fail tree
int l[maxn],r[maxn],dfk=0;
void dfs(int u){
	num2[u]=l[u]=++dfk;
	for(int i=0;i<G[u].size();++i)dfs(G[u][i]);
	r[u]=dfk;
}
//zjr tree
int tot=0;
struct node{
	int ls,rs;
	int sumv;
}tree[nlogn];
void Insert(int &k,int x,int l,int r,int pos){
	k=++tot;
	tree[k]=tree[x];
	tree[k].sumv++;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos<=mid)Insert(tree[k].ls,tree[x].ls,l,mid,pos);
	else Insert(tree[k].rs,tree[x].rs,mid+1,r,pos);
}
int Query(int k1,int k2,int l,int r,int L,int R){
	if(l==L&&r==R)return tree[k2].sumv-tree[k1].sumv;
	int mid=(l+r)>>1;
	if(R<=mid)return Query(tree[k1].ls,tree[k2].ls,l,mid,L,R);
	else if(mid<L)return Query(tree[k1].rs,tree[k2].rs,mid+1,r,L,R);
	else return Query(tree[k1].ls,tree[k2].ls,l,mid,L,mid)+Query(tree[k1].rs,tree[k2].rs,mid+1,r,mid+1,R);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		insert(rt,1,strlen(str+1),0,i);
	}
	Build_AC();
	dfs(rt);
	for(int i=1;i<=n;++i){
		for(int j=num1[i];j;j=fa[j]){
			zjr++;
			Insert(root[zjr],root[zjr-1],1,dfk,num2[j]);
		}
		num3[i]=zjr;
	}
	int L,R,k;
	for(int i=1;i<=q;++i){
		scanf("%d%d%d",&L,&R,&k);
		printf("%d\n",Query(root[num3[L-1]],root[num3[R]],1,dfk,l[num1[k]],r[num1[k]]));
	}
	return 0;
}