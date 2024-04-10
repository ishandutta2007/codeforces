#include<bits/stdc++.h>
#define re register
using namespace std;
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,a[100002],b[100002],s[100002],p[100002];
inline bool cmp(re int x,re int y){return s[x]<s[y];}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)s[i]=read(),p[i]=i;
	sort(p+1,p+n+1,cmp);
	int T=(n+2)/3;
	for(re int i=1;i<=T;++i)a[p[i]]=i-1,b[p[i]]=s[p[i]]-a[p[i]];
	for(re int i=T+1;i<=n-T;++i)b[p[i]]=i-1,a[p[i]]=s[p[i]]-b[p[i]];
	for(re int i=n-T+1;i<=n;++i)b[p[i]]=n-i,a[p[i]]=s[p[i]]-b[p[i]];
	puts("YES");
	for(re int i=1;i<=n;++i)printf("%d ",a[i]);puts("");
	for(re int i=1;i<=n;++i)printf("%d ",b[i]);
}