#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,x,tx,ty,ans,a[1005][1005],b[1005][1005],f[1005][1005],p[2][1005][1005];
void solve(int x,int y,int tp){
	if(x==1&&y==1)return;
	if(p[tp][x][y]){
		solve(x-1,y,tp);putchar('D');
	}
	else{
		solve(x,y-1,tp);putchar('R');
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			x=read();
			if(!x){tx=i;ty=j;continue;}
			while(x%2==0){++a[i][j];x/=2;}
			while(x%5==0){++b[i][j];x/=5;}
		}
	}
	for(int i=1;i<=n;++i){
		f[i][1]=f[i-1][1]+a[i][1];p[0][i][1]=1;
		f[1][i]=f[1][i-1]+a[1][i];p[0][1][i]=0;
	}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=n;++j){
			f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
			p[0][i][j]=f[i-1][j]<f[i][j-1];
		}
	}
	ans=f[n][n];
	for(int i=1;i<=n;++i){
		f[i][1]=f[i-1][1]+b[i][1];p[1][i][1]=1;
		f[1][i]=f[1][i-1]+b[1][i];p[1][1][i]=0;
	}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=n;++j){
			f[i][j]=min(f[i-1][j],f[i][j-1])+b[i][j];
			p[1][i][j]=f[i-1][j]<f[i][j-1];
		}
	}
	int tp=0;
	if(ans>f[n][n])tp=1;
	ans=min(ans,f[n][n]);
	if(ans>1&&tx){
		cout<<1<<"\n";
		for(int i=1;i<tx;++i)putchar('D');
		for(int j=1;j<n;++j)putchar('R');
		for(int i=tx;i<n;++i)putchar('D');
	}
	else{
		cout<<ans<<"\n";
		solve(n,n,tp);
	}
	
	return 0;
}