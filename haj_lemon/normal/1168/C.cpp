#include<bits/stdc++.h>
#define N 300010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
int n,m,a[N],la[N][22],sh[N],x,y;
int main(){
	read(n);read(m);
	for (int i=1;i<=n;i++){
		read(a[i]);
		for (int j=0;j<=18;j++){
			if (a[i]&(1<<j)){
				la[i][j]=i;
				for (int k=0;k<=18;k++)la[i][k]=max(la[i][k],la[sh[j]][k]);
				sh[j]=i;
			}
		}
	}
	for (int i=1;i<=m;i++){
		read(x);read(y);
		bool an=0;
		for (int j=0;j<=18;j++){
			if (a[x]&(1<<j))if (la[y][j]>=x)an=1;
		}
		if (an) puts("Shi");else puts("Fou");
	}
	return 0;
}