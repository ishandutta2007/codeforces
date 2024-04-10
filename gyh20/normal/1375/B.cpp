#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,ans,a[402][402],b[402][402];
int main(){
	t=read();
	while(t--){
		bool ia=0;
		n=read();m=read();
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<=m;++j){
				a[i][j]=0;b[i][j]=read();
			}
		}
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<=m;++j){
				if((i!=1))++a[i][j];
				if(i^n)++a[i][j];
				if(j^1)++a[i][j];
				if(j^m)++a[i][j];
				if(b[i][j]>a[i][j])ia=1;
			}
		}
		if(ia)puts("NO");
		else{
			puts("YES");
			for(re int i=1;i<=n;++i){
			for(re int j=1;j<=m;++j){
				printf("%d ",a[i][j]);
			}puts("");
		}
		}
	}
}