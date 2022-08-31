#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
int t,n,m,a[500002],b[500002],ans,head[500002],cnt,num,nxt[600002],f[600002],fst[100002];
priority_queue<int>q,d;
inline int first(){
	while(!d.empty()&&q.top()==d.top())q.pop(),d.pop();
	return q.top();
}
struct edge{int to,next;}e[1000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]};head[x]=cnt;}
inline void pls(re int &x,re int y){(x+=y)>=M?x-=M:x;}
struct node{int id,val;bool operator <(const node x){return val<x.val;}}p[600002];
char s[500002];
signed main(){
	for(re int i=1;i<=6;++i)a[i]=read();ans=1e18;
	sort(a+1,a+6+1);
	n=read();
	for(re int i=1;i<=n;++i){
		b[i]=read();
		for(re int j=1;j<=6;++j)p[++num]=(node){i,b[i]-a[j]};
	}
	sort(p+1,p+num+1);
	for(re int j=1;j<=n;++j)nxt[j]=num+1;
	p[num+1].val=1e18;
	for(re int i=num;i;--i){
		f[i]=nxt[p[i].id];
		nxt[p[i].id]=fst[p[i].id]=i;
	}
	for(re int i=1;i<=n;++i)q.push(fst[i]);
	for(re int i=1;i<=num;++i){
		ans=min(ans,p[first()].val-p[i].val);
		q.push(f[i]);
	}
	printf("%lld",ans);
}