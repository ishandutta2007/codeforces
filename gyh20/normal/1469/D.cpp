#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,ansx[300002],ansy[300002],cnt;
int main(){
	t=read();
	while(t--){
		n=read(),cnt=0;
		if(n<=10){
		for(re int i=3;i<n;++i)ansx[++cnt]=i,ansy[cnt]=i+1;
		re int x=n;
		while(x>1)ansx[++cnt]=n,ansy[cnt]=2,x=(x+1)/2;
			printf("%d\n",cnt);
			for(re int i=1;i<=cnt;++i)printf("%d %d\n",ansx[i],ansy[i]);continue;
		}
		for(re int i=9;i<n;++i)ansx[++cnt]=i,ansy[cnt]=i+1;
		re int x=n;
		if(x>8){
		while(x>1){
			x=(x+7)/8;
			ansx[++cnt]=n,ansy[cnt]=8;
		}
		}
			ansx[++cnt]=3,ansy[cnt]=4;
			ansx[++cnt]=4,ansy[cnt]=5;
			ansx[++cnt]=5,ansy[cnt]=6;
			ansx[++cnt]=6,ansy[cnt]=7;
			ansx[++cnt]=7,ansy[cnt]=8;
			ansx[++cnt]=8,ansy[cnt]=2;
			ansx[++cnt]=8,ansy[cnt]=2;
			ansx[++cnt]=8,ansy[cnt]=2;
			printf("%d\n",cnt);
			for(re int i=1;i<=cnt;++i)printf("%d %d\n",ansx[i],ansy[i]);
	}
}