#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002];
struct node{
	int x,y;
	bool operator <(const node s)const{return a[y]-a[x]==a[s.y]-a[s.x]?y>s.y:a[y]-a[x]>a[s.y]-a[s.x];}
}p[500002];
char s[100002];
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)for(re int j=i+1;j<=n;++j)p[++cnt]=(node){i,j};
	for(re int i=1;i<=cnt;++i)if(a[p[i].x]>a[p[i].y])swap(p[i].x,p[i].y);
	sort(p+1,p+cnt+1);
	for(re int i=1;i<=cnt;++i){
		printf("? %d %d\n",p[i].y,p[i].x);
		fflush(stdout);
		scanf("%s",s+1);
		if(s[1]=='Y'){
			printf("! %d %d\n",p[i].x,p[i].y);
		fflush(stdout);
			return 0;
		}
	}
			printf("! %d %d\n",0,0);
		fflush(stdout);
			return 0;
}