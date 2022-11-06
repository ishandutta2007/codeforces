#include<bits/stdc++.h>
#define ll long long
#define N 1010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int nu,we,nn;}b[N];
int m,n,a[N][N],da[N][N][2],xi[N][N][2],s;
bool cp(const Info &a,const Info &b){return a.nu<b.nu;}
bool c1(const Info &a,const Info &b){return a.we<b.we;}
int main(){
	read(n);read(m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) read(a[i][j]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){b[j].nu=a[i][j];b[j].we=j;}
		sort(b+1,b+m+1,cp);
		for (int j=1;j<=m;j++) b[j].nn=b[j-1].nn+(j==1||b[j].nu!=b[j-1].nu);s=b[m].nn;
		sort(b+1,b+m+1,c1);
		for (int j=1;j<=m;j++){
			xi[i][j][0]=b[j].nn-1;da[i][j][0]=s-b[j].nn;
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){b[j].nu=a[j][i];b[j].we=j;}
		sort(b+1,b+n+1,cp);
		for (int j=1;j<=n;j++) b[j].nn=b[j-1].nn+(j==1||b[j].nu!=b[j-1].nu);s=b[n].nn;
		sort(b+1,b+n+1,c1);
		for (int j=1;j<=n;j++){
			xi[j][i][1]=b[j].nn-1;da[j][i][1]=s-b[j].nn;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			printf("%d ",max(xi[i][j][0],xi[i][j][1])+max(da[i][j][0],da[i][j][1])+1);
		}
		puts("");
	}
	return 0;
}