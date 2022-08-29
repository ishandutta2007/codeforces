#include<bits/stdc++.h>
#define re register
using namespace std;
char s[500002],a[500002];
int n,m,mx[3000002],ls[3000002],rs[3000002],ch[100002][26],tr[100002][26],num,tot,q,k,ans2,ans1,pre[100002],rt[100002],pos[3000002],fa[100002],head[100002],f[22][100002],cnt,ed[100002],len[100002],L,P,A[500002],B[500002];
struct edge{int to,next;}e[100002];
inline void pu(re int p){
	mx[p]=0;
	if(ls[p]&&mx[ls[p]]>mx[p])mx[p]=mx[ls[p]],pos[p]=pos[ls[p]];
	if(rs[p]&&mx[rs[p]]>mx[p])mx[p]=mx[rs[p]],pos[p]=pos[rs[p]];
}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline void ins(re int &p,re int l,re int r,re int x){
	if(!p)p=++num;
	if(l==r){pos[p]=l,++mx[p];return;}
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x);
	else ins(rs[p],mid+1,r,x);
	pu(p);
}
inline int ins(re int lst,re int c){
	re int np=++tot,p=lst;len[np]=len[p]+1;
	for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
	if(!p)fa[np]=1;
	else{	
		re int q=ch[p][c];
		if(len[q]==len[p]+1)fa[np]=q;
		else{
			re int nq=++tot;fa[nq]=fa[q];
			for(re int i=0;i<26;++i)ch[nq][i]=ch[q][i];
			len[nq]=len[p]+1,fa[q]=fa[np]=nq;
			for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
		}
	}
	return np;
}
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline int merge(re int x,re int y,re int l,re int r){
	if(!x||!y)return x+y;
	if(l==r){++num,mx[num]=mx[x]+mx[y],pos[num]=l;return num;}
	re int mid=l+r>>1,nw=++num;
	ls[nw]=merge(ls[x],ls[y],l,mid),rs[nw]=merge(rs[x],rs[y],mid+1,r),pu(nw);
	return nw;
}
queue<int>Q;
vector<int>v[100002];
inline void dfs(re int x){
	for(re int i=head[x];i;i=e[i].next)f[0][e[i].to]=x,dfs(e[i].to),rt[x]=merge(rt[x],rt[e[i].to],1,m);
}
inline void ask(re int p,re int l,re int r,re int x,re int y){
	if(mx[p]<=ans1)return;
	if(l>=x&&r<=y){
		ans1=mx[p],ans2=pos[p];
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)ask(ls[p],l,mid,x,y);
	if(y>mid)ask(rs[p],mid+1,r,x,y);
}
int main(){
	scanf("%s%d",s+1,&m),n=strlen(s+1);
	for(re int i=1;i<=m;++i){
		scanf("%s",a+1),k=strlen(a+1);
		re int nw=0;
		for(re int j=1;j<=k;++j){
			if(!tr[nw][a[j]-'a'])tr[nw][a[j]-'a']=++tot;
			nw=tr[nw][a[j]-'a'],v[nw].push_back(i);
		}
	}
	Q.push(0),tot=1,pre[0]=1;
	while(!Q.empty()){
		re int x=Q.front();Q.pop();
		for(re int i=0;i<26;++i)
			if(tr[x][i]){
				pre[tr[x][i]]=ins(pre[x],i);
				for(re int j=0;j<v[tr[x][i]].size();++j)ins(rt[pre[tr[x][i]]],1,m,v[tr[x][i]][j]);
				Q.push(tr[x][i]);
			}
	}
	for(re int i=2;i<=tot;++i)add(fa[i],i);
	dfs(1),P=1;
	for(re int i=1;i<=n;++i){
		if(ch[P][s[i]-'a'])P=ch[P][s[i]-'a'],++L;
		else{
			while(P&&!ch[P][s[i]-'a'])P=fa[P];
			if(P)L=len[P]+1,P=ch[P][s[i]-'a'];
			else P=1,L=0;
		}
		A[i]=P,B[i]=L;
	}
	q=read();
	for(re int i=1;i<=19;++i)for(re int j=1;j<=tot;++j)f[i][j]=f[i-1][f[i-1][j]];
	while(q--){
		re int pl=read(),pr=read(),l=read(),r=read(),pp=A[r],Len=r-l+1;
		if(B[r]<Len)printf("%d %d\n",pl,0);
		else{
			for(re int i=19;~i;--i)if(len[f[i][pp]]>=Len)pp=f[i][pp];
			ans1=ans2=0,ask(rt[pp],1,m,pl,pr);
			if(!ans1)printf("%d %d\n",pl,0);
			else printf("%d %d\n",ans2,ans1);
		}
	}
}