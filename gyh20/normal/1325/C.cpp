#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int n,m,cnt,head[400002];
struct edge{
	int to,next;
}e[400002];
inline void add(re int x,re int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int rd[400002],p[400002],v[400002],tot,vis[400002];
inline bool cmp(re int x,re int y){
	return rd[x]>rd[y];
}
int main(){
	n=read();
	for(re int i=1;i<n;++i){
		re int x=read(),y=read();
		add(x,y);
		add(y,x);
		++rd[x];
		++rd[y];
	}
	for(re int i=1;i<=n;++i)p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(re int i=1;i<=n;++i){
		vis[p[i]]=1;
		for(re int j=head[p[i]];j;j=e[j].next){
			if(!vis[e[j].to])v[j]=tot++;
		}
	}
	for(re int i=1;i<=cnt;i+=2)printf("%d\n",v[i]+v[i+1]);
}