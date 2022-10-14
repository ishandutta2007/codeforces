#include<cstdio>
const int N=550;
int n,a[N][N];
int main(){
	scanf("%d",&n);
	if(n<3)return puts("-1"),0;
	int x=0;
	for(int i=n; i>3; --i) 
		if(i&1){
			a[2][i]=++x,a[1][i]=++x,a[3][i]=++x;
			for(int j=4;j<=i;++j)a[j][i]=++x;
			for(int j=i-1;j>2;--j)a[i][j]=++x;
			a[i][1]=++x,a[i][2]=++x;
		}
		else{
			a[i][2]=++x,a[i][1]=++x;
			for(int j=3;j<=i;++j)a[i][j]=++x;
			for(int j=i-1;j>2;--j)a[j][i]=++x;
			a[1][i]=++x,a[2][i]=++x;
		}
	a[1][1]=n*n-2,a[1][2]=n*n-3,a[1][3]=n*n-0;
	a[2][1]=n*n-1,a[2][2]=n*n-8,a[2][3]=n*n-4;
	a[3][1]=n*n-7,a[3][2]=n*n-6,a[3][3]=n*n-5;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		printf("%d%c",a[i][j]," \n"[j==n]);
	return 0;
}