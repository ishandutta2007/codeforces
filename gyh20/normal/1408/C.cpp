#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],b[1000002],t,ans,pos1,pos2;
long double tim1,sp1,sp2,p1,p2;
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=sp1=sp2=1;i<=n;++i)a[i]=read();
		p1=0,p2=m;pos1=1,pos2=n;tim1=0;
		while(pos2-pos1>=0){
			long double tim=min((p2-a[pos2])/sp2,(a[pos1]-p1)/sp1);
			if((p2-a[pos2])/sp2<(a[pos1]-p1)/sp1){
				p2-=sp2*tim;
				p1+=sp1*tim;
				--pos2;++sp2;
			}
			else{
				p1+=sp1*tim;
				p2-=sp2*tim;
				++pos1;++sp1;
			}
			tim1+=tim;
		}
		printf("%.10Lf\n",tim1+(p2-p1)/(sp1+sp2));
	}
}