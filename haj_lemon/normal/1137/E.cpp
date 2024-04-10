#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int x;ll y;}st[300010];
int m,n,b,s,nst,x,opt,k;
ll ns,nb,y;
int main(){
	read(n);read(m);
	nst=1;
	for (int i=1;i<=m;i++){
		read(opt);
		if (opt==1){
			read(k);n+=k;ns=0;nb=0;
			nst=1;st[1].x=st[1].y=0;
		}
		if (opt==2){
			read(k);x=n;y=-nb-ns*n;n+=k;
			while (nst>1&&((long double)(st[nst].y-st[nst-1].y))/(st[nst].x-st[nst-1].x)>((long double)(y-st[nst].y))/(x-st[nst].x))nst--;
			st[++nst].x=x;st[nst].y=y;
		}
		if (opt==3){
			read(b);read(s);
			nb+=b;ns+=s;
		}
		while (nst>1&&st[nst].x*ns+st[nst].y>=st[nst-1].x*ns+st[nst-1].y)nst--;
		printf("%d %I64d\n",st[nst].x+1,st[nst].x*ns+st[nst].y+nb);
	}
	return 0;
}