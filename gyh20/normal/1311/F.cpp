#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0,f=0;
	re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return f?-t:t;
}
struct node{
	int x,y;
}p[200002];
int r[200002],c[200002],d[200002];int n,ans;
inline bool cmp(re node x,re node y){
	return x.x<y.x;
}
inline void add(re int x,re int y){
	for(x;x<=n;x+=x&(-x))c[x]+=y;
}
inline void add1(re int x,re int y){
	for(x;x<=n;x+=x&(-x))d[x]+=y;
}
inline int ask(re int x){
	int sum=0;
	for(x;x;x-=x&(-x))sum+=c[x];
	return sum;
}
inline int ask1(re int x){
	int sum=0;
	for(x;x;x-=x&(-x))sum+=d[x];
	return sum;
}

signed main(){
	n=read();
	for(re int i=1;i<=n;++i){
		p[i].x=read();
	}
	for(re int i=1;i<=n;++i)r[i]=p[i].y=read();
	sort(r+1,r+n+1);
	int m=unique(r+1,r+n+1)-r-1;
	for(re int i=1;i<=n;++i){
		p[i].y=lower_bound(r+1,r+m+1,p[i].y)-r;
	}
	sort(p+1,p+n+1,cmp);
	for(re int i=1;i<=n;++i){
		int tmp=ask(p[i].y),tmp1=ask1(p[i].y);
		ans+=tmp1*p[i].x-tmp;
		add(p[i].y,p[i].x),add1(p[i].y,1);
	}
	printf("%lld",ans);
}