#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
char ch[N*2];
int n,q,x,y;
struct Onfo{int a,b,di,ml,al,mr,ar;};
struct Info{int l,r;Onfo x;}t[N*8];
Onfo operator +(Onfo x,Onfo y){
	Onfo z;
	if (x.b>=y.a){z.a=x.a;z.b=x.b-y.a+y.b;}else{z.a=x.a+y.a-x.b;z.b=y.b;}
	z.di=max(x.di,max(y.di,max(x.ar+y.ml,x.mr+y.al)));
	z.ar=max(y.ar,max(x.mr+y.a+y.b,x.ar-y.a+y.b));
	z.mr=max(x.mr+y.a-y.b,y.mr);
	z.ml=max(x.ml,y.ml-x.a+x.b);
	z.al=max(x.al,max(y.al-x.b+x.a,y.ml+x.a+x.b));
	return z;
}
Onfo que(char x){
	Onfo z;
	if (x=='('){
		z.a=0;z.b=1;z.di=1;
		z.al=z.ar=1;
		z.ml=1;z.mr=0;
	}else{
		z.a=1;z.b=0;z.di=1;
		z.al=z.ar=1;
		z.ml=0;z.mr=1;
	}
	return z;
}
void build(int nu,int l,int r){
	t[nu].l=l;t[nu].r=r;
	if (l==r){
		t[nu].x=que(ch[l]);
	}else{
		build(nu*2,l,(l+r)/2);build(nu*2+1,(l+r)/2+1,r);
		t[nu].x=t[nu*2].x+t[nu*2+1].x;
	}
}
void chan(int nu,int we){
	if (t[nu].l==t[nu].r){
		t[nu].x=que(ch[t[nu].l]);
	}else{
		if (we<=(t[nu].l+t[nu].r)/2) chan(nu*2,we);else chan(nu*2+1,we);
		t[nu].x=t[nu*2].x+t[nu*2+1].x;
	}
}
int main(){
//	freopen("d.in","r",stdin);
	read(n);read(q);
	for (int i=1;i<=(n-1)*2;i++){
		ch[i]=getchar();
		while (ch[i]!='('&&ch[i]!=')') ch[i]=getchar();
	}
	build(1,1,(n-1)*2);
	printf("%d\n",t[1].x.di);
	while (q--){
		read(x);read(y);swap(ch[x],ch[y]);
		chan(1,x);chan(1,y);
		printf("%d\n",t[1].x.di);
	}
	return 0;
}