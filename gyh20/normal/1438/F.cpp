#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,p[1<<20],o[1<<20];
inline int Rand(re int x){return ((rand()<<15)|(rand()))%x+1;}
inline bool cmp(re int x,re int y){return p[x]>p[y];}
int main(){
	srand(time(0));
	n=(1<<read())-1;
	for(re int i=1;i<=n;++i)o[i]=i;
	for(re int i=1;i<=420;++i){
		re int x=Rand(n),y=Rand(n),z=Rand(n);
		while(x==y)y=Rand(n);
		while(x==z||y==z)z=Rand(n);
		printf("? %d %d %d\n",x,y,z),fflush(stdout);
		++p[read()];
	}
	sort(o+1,o+n+1,cmp);re int X=o[1],Y=o[2];
	for(re int i=1;i<=n;++i)
		if((X^i)&&(Y^i)){
			printf("? %d %d %d\n",X,Y,i),fflush(stdout);
			if(read()==i)return printf("! %d",i),0;
		}
}