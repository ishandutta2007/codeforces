#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[100002],f[100002],g[100002],P[100002],ans,cnt,rt,p[100002],deg[100002],d[100002],h[100002];
char v[100002];
struct edge{int to,next;}e[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt,++d[x];}
vector<int>S[100002],Ans;
inline bool cmp(re int x,re int y){return f[x]>f[y];}
inline bool cmp1(re int x,re int y){return deg[x]>deg[y];}
inline void dfs(re int x,re int y){
	S[x].clear(),f[x]=0;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs(e[i].to,x),S[x].push_back(e[i].to);
	sort(S[x].begin(),S[x].end(),cmp);
	for(re int i=0;i<S[x].size();++i)f[x]=max(f[x],f[S[x][i]]+i);
	if(!S[x].size())f[x]=1,g[x]=x;
	else g[x]=g[S[x][0]];f[x]=max(f[x],(int)S[x].size());
}
inline void dfs1(re int x){
	if(n==1)return;
	vector<int>tmp,suf;f[x]=h[x];
	if(x^rt)tmp.push_back(x);
	for(auto z:S[x])tmp.push_back(z);
	sort(tmp.begin(),tmp.end(),cmp),suf.resize(tmp.size());
	for(re int i=1;i<tmp.size();++i)ans=max(ans,f[tmp[i]]+i-1+f[tmp[0]]);
	ans=max(ans,f[tmp[0]]);
	for(re int i=tmp.size()-1;~i;--i){
		suf[i]=f[tmp[i]]+i-1;
		if(i+1<tmp.size())suf[i]=max(suf[i],suf[i+1]);
	}
	re int mx=0;
	for(re int i=0;i<tmp.size();++i){
		re int xx=f[tmp[i]];
		if(tmp[i]^x){
			re int o=mx;
			if(i+1<tmp.size())o=max(o,suf[i+1]);
			h[tmp[i]]=o,dfs1(tmp[i]);
		}
		mx=max(mx,xx+i);
	}
}
inline int ask(re int x){
	if(v[x])return 0;
	v[x]=1;
	printf("? %d\n",x),fflush(stdout);
	return read();
}
inline void work(re int x){
	for(re int i=0;i<S[x].size();++i){
		re int z=ask(g[S[x][i]]);
		if(z&&(z^x)){
			work(z);
			if(x^rt||Ans.size()==2)return;
		}
	}
	Ans.push_back(x);
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);rt=1;
	for(re int i=1;i<=n;++i)if(d[i]>1)rt=i;
	dfs(rt,rt),dfs1(rt);
	if(n==1)ans=0;
	printf("%d\n",ans),fflush(stdout);
	rt=read();dfs(rt,rt);
	work(rt);
	if(Ans.size()==1)Ans.push_back(Ans[0]);
	printf("! %d %d\n",Ans[0],Ans[1]);
}