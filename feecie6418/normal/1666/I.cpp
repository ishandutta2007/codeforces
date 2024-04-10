#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,x1,y1,x2,y2,ansx1,ansy1,ansx2,ansy2;
inline int ask(re int x,re int y){
	printf("SCAN %d %d\n",x,y);
	fflush(stdout);
//	return abs(ansx1-x)+abs(ansy1-y)+abs(ansx2-x)+abs(ansy2-y);
	return read();
}
inline int dis(re int a,re int b,re int c,re int d){
	return abs(a-c)+abs(d-b);
}
inline int DIG(re int x,re int y){
	printf("DIG %d %d\n",x,y);
	fflush(stdout);return read();
}
int main(){
	t=read();
	while(t--){
		int n=read(),m=read();
	//	ansx1=read(),ansy1=read(),ansx2=read(),ansy2=read();
		re int X=0,Y=0;
		re int x1=ask(1,1),x2=ask(n,1),px3,px4,py3,py4,x3,x4;
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j)
				for(re int k=1;k<=n;++k)
					for(re int l=1;l<=m;++l){
						if(i==k&&j==l)continue;
						if(x1==dis(1,1,i,j)+dis(1,1,k,l)&&x2==dis(n,1,i,j)+dis(n,1,k,l)){
							X=i+k,Y=j+l;
						}
					}
		px3=X>>1,py3=1,px4=1,py4=Y>>1;
		x3=ask(X>>1,1),x4=ask(1,Y>>1);
		re int X1=0,Y1=0,X2=0,Y2=0;
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j)
				for(re int k=1;k<=n;++k)
					for(re int l=1;l<=m;++l){
						if(i==k&&j==l)continue;
						if(x1==dis(1,1,i,j)+dis(1,1,k,l)&&x2==dis(n,1,i,j)+dis(n,1,k,l)&&x3==dis(px3,py3,i,j)+dis(px3,py3,k,l)&&x4==dis(px4,py4,i,j)+dis(px4,py4,k,l)){
							if(!X1)X1=i;
							else X2=i;
							if(!Y1)Y1=j;
							else Y2=j;
						}
					}
		if(DIG(X1,Y1))DIG(X2,Y2);
		else DIG(X1,Y2),DIG(X2,Y1);
	}
}