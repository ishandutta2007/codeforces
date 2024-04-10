#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
char X,Y;
int n,o,p[12];
int main(){
	n=read();X='a',Y='1',o=1;
	while(n>2&&Y<'7'){
		putchar(X),putchar(Y),putchar(' ');
		X+=o;
		if(X=='i')X='h',++Y,o=-1;
		if(X=='a'-1)X='a',++Y,o=1;
		--n;
	}
	putchar(X),putchar(Y),putchar(' ');
	if(n<=2){
		if(Y=='8'){
			putchar('g'),putchar(Y),putchar(' ');
			putchar('h'),putchar('8'),putchar(' ');
		}
		else if(X=='h'){
			putchar('h'),putchar('7'),putchar(' ');
			putchar('h'),putchar('8'),putchar(' ');
		}
		else{
			putchar(X),putchar('8'),putchar(' ');
			putchar('h'),putchar('8'),putchar(' ');
		}
	}
	else{
		if(n==3){
			putchar('a'),putchar('8'),putchar(' ');
			putchar('b'),putchar('8'),putchar(' ');
			putchar('h'),putchar('8'),putchar(' ');
		}
		else{
			p[2]=8;
			for(re int i=3;i<=8;++i)p[i]=i-1;
			re int pos=2,cur=1;
			while(n>2&&pos<=8){
				putchar('a'-1+p[pos]),putchar('7'),putchar(' ');cur=p[pos];
				--n,++pos;
			}
			putchar('a'-1+cur),putchar('8'),putchar(' ');--n;
			for(re int i=1;i<=8;++i)p[i]=i;
			swap(p[cur],p[1]);
			swap(p[8],p[n+1]);
			for(re int i=2;i<=n+1;++i)putchar('a'-1+p[i]),putchar('8'),putchar(' ');
		}
	}
}