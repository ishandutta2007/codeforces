#include<bits/stdc++.h>
#define re register
using namespace std;
int n,ans,f[102][102][2];
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct node{int x,y;bool operator <(const node a)const{return x<a.x;};}a[102];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1),a[0].x=-1e9;
	for(re int i=0;i<=n;++i)
		for(re int j=0;j<=i;++j)
			for(re int B=0;B<2;++B){
				re int tmp=a[j].x+B*a[j].y,mx=-1e9;
				for(int k=i+1,x,y;k<=n;++k)
					for(int A=0;A<2;++A){
						int t=a[k].x+A*a[k].y;
						if(t>mx)mx=t,x=k,y=A;
						f[k][x][y]=max(f[k][x][y],f[i][j][B]+min(a[k].y,t-tmp)-t+mx);
					}
				}
	for(re int i=0;i<=n;++i)for(re int j=0;j<2;++j)ans=max(ans,f[n][i][j]);
	printf("%d",ans);
}