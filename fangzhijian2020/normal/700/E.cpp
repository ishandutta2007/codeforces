#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int base=131;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
char c[200005];int n,num=1,last=1;
int tot,root[400005],ls[8000005],rs[8000005];
void change(int&p,int l,int r,int x){
	p=++tot;
	if(l==r)return;int mid=l+r>>1;
	if(x<=mid)change(ls[p],l,mid,x);
	else change(rs[p],mid+1,r,x);
}
bool query(int p,int l,int r,int L,int R){
	if(!p)return 0;if(L<=l&&r<=R)return 1;
	int mid=l+r>>1,ans=0;
	if(L<=mid)ans|=query(ls[p],l,mid,L,R);
	if(R>mid)ans|=query(rs[p],mid+1,r,L,R);
	return ans;
}
int merge(int p,int q,int l,int r){
	if(!p||!q)return p+q;int tmp=++tot;
	int mid=l+r>>1;
	ls[tmp]=merge(ls[p],ls[q],l,mid);
	rs[tmp]=merge(rs[p],rs[q],mid+1,r);
	return tmp;
}
int ch[400005][26],fail[400005],len[400005],pos[400005];
int newnode(int Len){len[++num]=Len;return num;}
void Insert(int x,int id){
	int now=newnode(len[last]+1),p=last;
	for(;p&&!ch[p][x];p=fail[p])ch[p][x]=now;
	if(!p)fail[now]=1;
	else{
		int q=ch[p][x];
		if(len[p]+1==len[q])fail[now]=q;
		else{
			int nq=newnode(len[p]+1);pos[nq]=pos[q];
			fail[nq]=fail[q];fail[q]=fail[now]=nq;
			for(int i=0;i<26;++i)ch[nq][i]=ch[q][i];
			for(;ch[p][x]==q;p=fail[p])ch[p][x]=nq;
		}
	}
	pos[now]=id;change(root[last=now],1,n,id);
}
int h[400005],cnt,f[400005],t[400005],ans;
struct edge{int to,next;}e[400005];
void add(int x,int y){e[++cnt]=(edge){y,h[x]};h[x]=cnt;}
void dfs(int x){
	int i,y;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;dfs(y);
		root[x]=merge(root[x],root[y],1,n);
	}
}
void DFS(int x){
	int i,y,fa=fail[x];
	if(x!=1){
		if(fa==1)f[x]=1,t[x]=x;
		else if(query(root[t[fa]],1,n,pos[x]-len[x]+len[t[fa]],pos[x]-1)){
			f[x]=f[fa]+1;t[x]=x;
		}
		else t[x]=t[fa];ans=max(ans,f[x]);	
	}
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;f[y]=f[x];DFS(y);
	}
}
int main(){
//	system("fc level.out level.out");
//	freopen("level31.in","r",stdin);
//	freopen("level.out","w",stdout);
	n=read();scanf("%s",c+1);
	for(int i=1;i<=n;++i)Insert(c[i]-'a',i);
	for(int i=2;i<=num;++i)add(fail[i],i);
	dfs(1);DFS(1);cout<<ans;
	return 0;
}