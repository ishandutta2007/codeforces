#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[2][100002],b[2][100002];
struct node{
	int x,y;
	bool operator <(const node a)const{return x<a.x;}
}p[100002];
int main(){
	t=read();
	while(t--){
		memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
		n=read();
		for(re int i=1;i<=n;++i)p[i].x=read(),p[i].y=i,a[i&1][p[i].x]++;
		sort(p+1,p+n+1);
		for(re int i=1;i<=n;++i)b[i&1][p[i].x]++;
		re bool ia=1;
		for(re int i=1;i<=100000;++i)ia&=(a[0][i]==b[0][i])&&(a[1][i]==b[1][i]);
		puts(ia?"YES":"NO");
	}
}