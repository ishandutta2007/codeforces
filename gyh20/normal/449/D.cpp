#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,a[1048576],pw[1000002];
int main(){
	n=read();
	for(re int i=pw[0]=1;i<=n;++i)pw[i]=Mod(pw[i-1]+pw[i-1]);
	while(n--)++a[read()];
	for(re int i=1;i<1048576;i<<=1)
		for(re int j=i;j<1048576;++j)
			if(j&i)add(a[j^i],a[j]);
	for(re int i=0;i<1048576;++i)a[i]=pw[a[i]];
	for(re int i=1;i<1048576;i<<=1)
		for(re int j=i;j<1048576;++j)
			if(j&i)add(a[j^i],M-a[j]);
	printf("%d",a[0]);
}