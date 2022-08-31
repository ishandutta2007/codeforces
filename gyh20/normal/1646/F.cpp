#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[102][102],pos,d[102],ans[10002][102],*cur,tot;
inline void Mov(re int x){
	for(re int i=1;i<=n;++i)if(a[x][i]>1){--a[x][i],++a[(x+1)%n][i],cur[x]=i;return;}
}
inline int ck(){
	for(re int i=0;i<n;++i)for(re int j=1;j<=n;++j)if(a[i][j]>1)return i;
	return -1;
}
int main(){
	n=read();
	for(re int i=0;i<n;++i)for(re int j=1;j<=n;++j)++a[i][read()];
	while(~(pos=ck())){
		cur=ans[++tot];
		for(re int i=pos;i<pos+n;++i)Mov(i%n);
	}
	for(re int i=1;i<=n*(n-1)/2;++i){
		cur=ans[++tot];
		for(re int j=0;j<n;++j){
			re int pos=0;
			for(re int k=j+2;k<j+n+1;++k)if(a[j][(k-1)%n+1]){pos=(k-1)%n+1;break;}
			cur[j]=pos;
		}
		for(re int j=0;j<n;++j)--a[j][cur[j]],++a[(j+1)%n][cur[j]];
	}
	printf("%d\n",tot);
	for(re int i=1;i<=tot;++i,puts(""))for(re int j=0;j<n;++j)printf("%d ",ans[i][j]);
}