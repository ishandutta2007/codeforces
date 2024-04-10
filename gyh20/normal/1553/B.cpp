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
int t,n,m,ans,cnt,head[1000002],p[1002];
inline bool check(re char* a,re char* b){
	memset(p,0,sizeof(p));
	for(re int i=1;i<=m;++i){
		re int p1=i,p2=i;p[i]=1;
		while(p1&&p2<=m){
			if(b[p1]!=b[p2]){p[i]=0;break;}
			else --p1,++p2;
		}
	}
	for(re int l=1;l<=n;++l){
		for(re int r=l;r<=n&&a[r]==b[r-l+1];++r){
			if((r-l+1)>(m>>1)&&p[r-l+1])return 1;
		}
	}
	return 0;
}
char a[100002],b[100002],f[1002][502];
signed main(){
	t=read();
	while(t--){
		scanf("%s%s",a+1,b+1);
		n=strlen(a+1),m=strlen(b+1);
		if(check(a,b))puts("YES");
		else{
			reverse(b+1,b+m+1);
			if(check(a,b))puts("YES");
			else puts("NO");
		}
	}
}