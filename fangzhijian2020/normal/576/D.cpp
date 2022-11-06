#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,c,w[155];
struct node{
	int x,y,z;
	bool operator<(const node&a)const{
		return z<a.z;
	}
}e[155];
struct matrix{
	bitset<155>a[155];
	void init(){
		for(int i=1;i<=n;++i)a[i].reset();
	}
	matrix trans(){
		matrix b;b.init();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				b.a[j][i]=a[i][j];
			}
		}
		return b;
	}
}a,b[155];
matrix mul(matrix a,matrix B){
	matrix b,c;b=B.trans();c.init();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			c.a[i][j]=(a.a[i]&b.a[j]).any();
		}
	}
	return c;
}
int main(){
//	freopen("griffin3.in","r",stdin);
//	freopen("griffin.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;++i){
		e[i].x=read();e[i].y=read();e[i].z=read();
		w[i]=e[i].z;
	}
	sort(e+1,e+m+1);sort(w+1,w+m+1);c=unique(w+1,w+m+1)-w-1;
	if(w[1]!=0){
		if(n==1)puts("0");
		else puts("Impossible");
		return 0;
	}
	a.init();a.a[1][1]=1;
	b[0].init();b[0].a[n][n]=1;
	int ans=0,now=1;w[c+1]=w[c]+(n<<1);
	for(int i=1;i<=c;++i){
		while(now<=m&&e[now].z<=w[i]){
			b[0].a[e[now].x][e[now].y]=1;++now;
		}
		for(int j=1;j<30;++j){
			b[j]=mul(b[j-1],b[j-1]);
		}
		for(int j=29;~j;--j){
			if(ans+(1<<j)<=w[i+1]&&!mul(a,b[j]).a[1][n]){
				a=mul(a,b[j]);ans+=(1<<j);
			}
		}
		if(ans!=w[i+1]){
			printf("%d\n",ans+1);return 0;
		}
	}
	puts("Impossible");
	return 0;
}