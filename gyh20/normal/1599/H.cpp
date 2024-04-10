#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline int ask(re int x,re int y){
	printf("? %d %d\n",x,y),fflush(stdout);
	return read();
}
int inf=1e9,lx,ly,rx,ry;
int main(){
	re int X1=ask(1,1),X2=ask(1,inf);
	re int mid=((1+inf)-(X2-X1))>>1;
	lx=1+ask(1,mid);
	X1=ask(1,1),X2=ask(inf,1);
	mid=((1+inf)-(X2-X1))>>1;
	ly=1+ask(mid,1);
	X1=ask(inf,1),X2=ask(inf,inf);
	mid=((1+inf)-(X2-X1))>>1;
	rx=inf-ask(inf,mid);
	X1=ask(1,inf),X2=ask(inf,inf);
	mid=((1+inf)-(X2-X1))>>1;
	ry=inf-ask(mid,inf);
	printf("! %d %d %d %d\n",lx,ly,rx,ry);
	fflush(stdout);
}