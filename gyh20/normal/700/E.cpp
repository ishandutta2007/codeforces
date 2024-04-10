#include<cstdio>
#include<cstring>
using namespace std;
#define re register
int ch[400002][26],len[400002],fa[400002],lst,tot,n,l,rt[400002],siz[8000002],p[400002],num[400002],tp[400002],pos[400002],ans,ls[8000002],rs[8000002],f[400002],sss,now;
char s[200002];
inline void ins(re int &p,re int l,re int r,re int x){
	if(!p)p=++sss;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x);
	else ins(rs[p],mid+1,r,x);
}
inline void ins(re char c){
	re int np=++tot,x=l;len[np]=len[l]+1,l=tot;pos[tot]=now;
	for(;!ch[x][c];x=fa[x])ch[x][c]=np;
	if(!x)fa[np]=1;
	else{
		re int q=ch[x][c];
		if(len[x]+1==len[q])fa[np]=q;
		else{
			re int nq=++tot;pos[nq]=pos[q];
			for(re int i=0;i<26;++i)ch[nq][i]=ch[q][i];
			len[nq]=len[x]+1,fa[nq]=fa[q],fa[q]=fa[np]=nq;
			for(;ch[x][c]==q;x=fa[x])ch[x][c]=nq;
		}
	}
}
inline int merge(re int x,re int y){
	if(!x||!y){return x+y;}
	re int z=++sss;
	ls[z]=merge(ls[x],ls[y]),rs[z]=merge(rs[x],rs[y]);
	return z;
}
inline bool ask(re int p,re int l,re int r,re int x,re int y){
	if(!p)return 0;
	if(l>=x&&r<=y)return 1;
	re int mid=l+r>>1;
	if(x<=mid&&ask(ls[p],l,mid,x,y))return 1;
	if(y>mid&&ask(rs[p],mid+1,r,x,y))return 1;
	return 0;
}
inline int max(re int x,re int y){return x>y?x:y;}
int main(){
	scanf("%d%s",&n,s+1),n=strlen(s+1),l=tot=1;
	for(re int i=1;i<=n;++i)now=i,ins(s[i]-'a'),ins(rt[l],1,n,i);
	for(re int i=1;i<=tot;++i)++num[len[i]];
	for(re int i=1;i<=n;++i)num[i]+=num[i-1];
	for(re int i=1;i<=tot;++i)p[num[len[i]]--]=i;
	for(re int i=tot;i>1;--i)rt[fa[p[i]]]=merge(rt[fa[p[i]]],rt[p[i]]);ans=1;
	for(re int i=2;i<=tot;++i){
		re int x=p[i];
		if(fa[x]==1){f[x]=1,tp[x]=x;continue;}
		if(ask(rt[tp[fa[x]]],1,n,pos[x]-len[x]+len[tp[fa[x]]],pos[x]-1))f[x]=f[fa[x]]+1,tp[x]=x;
		else f[x]=f[fa[x]],tp[x]=tp[fa[x]];ans=max(ans,f[x]);
	}
	printf("%d",ans);
}