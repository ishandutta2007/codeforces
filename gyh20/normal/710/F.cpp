#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int q[300002],hd,tl,cnt,tp,n,O[300002],ttt,L[32],R[32],m;
struct edge{int to,next;}e[10000002];
vector<char>a[300002],tmp;
char s[300002];
struct ACAM{
	int tot;
	vector<int>ch[26],f,sz,head;
	inline void clr(){
		for(re int i=0;i<26;++i)ch[i].clear();
		f.clear(),sz.clear(),head.clear();
		tot=0;
	}
	inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
	inline void ins(vector<char>s,re int y){
		re int m=s.size();
		for(re int i=0;i<26;++i)ch[i].resize(tot+m+1);sz.resize(tot+m+1);
		re int nw=0;
		for(re int i=0;i<s.size();++i){
			if(!ch[s[i]-'a'][nw])ch[s[i]-'a'][nw]=++tot;
			nw=ch[s[i]-'a'][nw];
		}
		sz[nw]+=y;
	}
	inline void dfs(re int x){
		sz[x]+=sz[f[x]];
		for(re int i=head[x];i;i=e[i].next)dfs(e[i].to);
	}
	inline void build(){
		f.resize(tot+1),head.resize(tot+1),tl=0,hd=1;
        for(re int i=0;i<26;++i)if(ch[i][0])q[++tl]=ch[i][0];
		while(hd<=tl){
			re int x=q[hd++];
			for(re int i=0;i<26;++i)
				if(!ch[i][x])ch[i][x]=ch[i][f[x]];
				else f[ch[i][x]]=ch[i][f[x]],q[++tl]=ch[i][x];
		}
		for(re int i=1;i<=tot;++i)add(f[i],i);
		dfs(0);
	}
	inline ll ask(vector<char>s){
		re int nw=0;re ll ans=0;
		for(re int i=0;i<s.size();++i)nw=ch[s[i]-'a'][nw],ans+=sz[nw];
		return ans;
	}
}T[19];
int main(){
	n=read();
	for(re int ii=1;ii<=n;++ii){
		re int o=read();scanf("%s",s+1),m=strlen(s+1);tmp.clear();
		for(re int i=1;i<=m;++i)tmp.push_back(s[i]);
		if(o==3){
			re ll ans=0;
			for(re int i=1;i<=tp;++i)ans+=T[i].ask(tmp);
			printf("%lld\n",ans);fflush(stdout);
		}
		else{
			a[++ttt]=tmp,O[ttt]=(o==1?1:-1),++tp,T[tp].clr();L[tp]=R[tp]=ttt;T[tp].ins(a[ttt],O[ttt]),T[tp].build();
			while(tp>1&&R[tp]-L[tp]==R[tp-1]-L[tp-1]){
				--tp,R[tp]=R[tp+1],T[tp].clr();
				for(re int i=L[tp];i<=R[tp];++i)T[tp].ins(a[i],O[i]);
				T[tp].build();
			}
		}
	}
}