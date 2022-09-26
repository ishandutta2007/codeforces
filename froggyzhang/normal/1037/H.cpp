#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,Q;
char s[N];
int segtot,root[N],nxt[N];
struct node{
	int l,r,sum;
}tree[N<<5];
#define ls tree[k].l
#define rs tree[k].r
inline void update(int k){
	tree[k].sum=tree[ls].sum+tree[rs].sum;
}
int Merge(int u,int v,int L,int R){
	if(!u||!v)return u|v;
	int k=++segtot;
	int mid=(L+R)>>1;
	tree[k].l=Merge(tree[u].l,tree[v].l,L,mid);
	tree[k].r=Merge(tree[u].r,tree[v].r,mid+1,R);
	update(k);
	return k;
}
int Modify(int k,int L,int R,int pos){
	if(!k)k=++segtot;
	if(L==R){
		++tree[k].sum;
		return k;
	}
	int mid=(L+R)>>1;
	if(pos<=mid){
		tree[k].l=Modify(ls,L,mid,pos);
	}
	else{
		tree[k].r=Modify(rs,mid+1,R,pos);
	}
	update(k);
	return k;
}
int Query(int k,int L,int R,int l,int r){
	if(L>=l&&R<=r){
		return tree[k].sum;
	}
	int mid=(L+R)>>1,tot=0;
	if(l<=mid)tot+=Query(ls,L,mid,l,r);
	if(r>mid)tot+=Query(rs,mid+1,R,l,r);
	return tot;
}
int tot,las;
struct SAM{
	int ch[26],len,fa;
}t[N];
void Insert(int c,int x){
	int p=las;
	int u=++tot;
	root[u]=Modify(root[u],1,n,x);
	t[u].len=t[las].len+1;
	while(p&&!t[p].ch[c]){
		t[p].ch[c]=u;
		p=t[p].fa;
	}
	if(!p){
		t[u].fa=1;
	} 
	else{
		int q=t[p].ch[c];
		if(t[q].len==t[p].len+1){
			t[u].fa=q;
		}
		else{
			int clone=++tot;
			t[clone]=t[q];
			t[clone].len=t[p].len+1;
			while(p&&t[p].ch[c]==q){
				t[p].ch[c]=clone;
				p=t[p].fa;
			}
			t[q].fa=t[u].fa=clone;
		}
	}
	las=u;
}
int cnt,head[N];
struct Edge{
	int to,nxt;
}edge[N];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		dfs(v);
		root[u]=Merge(root[u],root[v],1,n);
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	las=tot=1;
	for(int i=1;i<=n;++i){
		Insert(s[i]-'a',i);
	}
	for(int i=2;i<=tot;++i){
		add(t[i].fa,i);
	}
	dfs(1);
	Q=read();
	while(Q--){
		int l=read(),r=read();
		scanf("%s",s+1);
		int len=strlen(s+1);
		int pos=1,u=1;
		while("I love MYH forever!"){
			int lim=(pos==len+1?-1:s[pos]-'a');
			nxt[pos]=-1;
			for(int i=lim+1;i<26;++i){
				if(Query(root[t[u].ch[i]],1,n,l+pos-1,r)){
					nxt[pos]=i;
					break;
				} 
			}
			if(pos==len+1)break;
			int c=s[pos]-'a';
			u=t[u].ch[c];
			if(!Query(root[u],1,n,l+pos-1,r))break;
			++pos;
		}
		while(pos&&nxt[pos]==-1){
			--pos;
		}
		if(!pos){
			printf("-1\n");
		}
		else{
			for(int i=1;i<pos;++i){
				putchar(s[i]);
			}
			putchar(nxt[pos]+'a'),putchar('\n');
		}
	}
	return 0;
}