#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,rt[100002],ch[4000002][2],tot,sz[4000002],o[100002];
char s[100002];
set<int>S;
#define IT set<int>::iterator
inline void ins(re int &p,re int l,re int r,re int x){
	if(!p)p=++tot;++sz[p];
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ins(ch[p][0],l,mid,x);
	else ins(ch[p][1],mid+1,r,x);
}
inline int merge(re int x,re int y){
	if(!x||!y)return x|y;
	sz[x]+=sz[y],ch[x][0]=merge(ch[x][0],ch[y][0]),ch[x][1]=merge(ch[x][1],ch[y][1]);
	ch[y][0]=ch[y][1]=sz[y]=0;
	return x;
}
inline void split(re int x,re int &y,re int O,re int k){
	if(!x)return;
	y=++tot;
	if(sz[ch[x][O]]<k)split(ch[x][O^1],ch[y][O^1],O,k-sz[ch[x][O]]);
	else swap(ch[x][O^1],ch[y][O^1]);
	if(sz[ch[x][O]]>k)split(ch[x][O],ch[y][O],O,k);
	sz[y]=sz[x]-k,sz[x]=k;
}
inline void dfs(re int p,re int l,re int r,re int O){
	if(!p)return;
	if(l==r){
		while(sz[p]--)pc(l+'a'-1,0);
		return;
	}
	re int mid=l+r>>1;
	if(O)dfs(ch[p][0],l,mid,O),dfs(ch[p][1],mid+1,r,O);
	else dfs(ch[p][1],mid+1,r,O),dfs(ch[p][0],l,mid,O);
}
inline IT split(re int x){
	re IT it=S.lower_bound(x);
	if(*it==x||x>n)return it;
	--it,o[x]=o[*it];
	split(rt[*it],rt[x],o[x]^1,x-*it);
	return S.insert(x).first;
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(re int i=1;i<=n;++i)ins(rt[i],1,26,s[i]-'a'+1),S.insert(i);
	while(m--){
		re int x=read(),y=read(),z=read();
		re IT L=split(x),R=split(y+1);
		++L;
		for(IT it=L;it!=R;){
			merge(rt[x],rt[*it]);
			IT tmp=it;++it,S.erase(tmp);
		}
		o[x]=z;
	}
	for(IT it=S.begin();it!=S.end();++it)dfs(rt[*it],1,26,o[*it]);
	pc('o',1);
}