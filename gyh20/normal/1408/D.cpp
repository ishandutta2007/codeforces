#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[2002],b[2002],c[2002],d[2002],mx,ans,cnt,ss,mxx;
struct node{
	int x,y;
	bool operator<(const node &a)const{
		return x==a.x?y<a.y:x>a.x;
	}
}p[4000002];
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read(),b[i]=read();
	for(re int i=1;i<=m;++i)c[i]=read(),d[i]=read();
	for(re int i=1;i<=n;++i)for(re int j=1;j<=m;++j){if(c[j]>=a[i]&&d[j]>=b[i])p[++cnt]=(node){c[j]-a[i]+1,d[j]-b[i]+1};
	if(d[j]>=b[i])mxx=max(mxx,d[j]-b[i]+1);
	}p[++cnt]=(node){0,mxx};
	sort(p+1,p+cnt+1);ans=1e9;
	for(re int i=1;i<=cnt;++i)ans=min(ans,mx+p[i].x),mx=max(mx,p[i].y);
	printf("%d",ans);
}