#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[35][35],m,n,b[35][35];
int f(int x,int y){
	return b[x][y]?-a[x][y]:a[x][y];
}
int f1(int x,int fl){//b[m][x]=fl
	b[m][x]=fl,b[m][x+m]=(b[m][x]^b[m][m]);
	int s=f(m,x)+f(m,x+m);
	for(int i=1;i<m;i++){
		//b[i][x]=0
		b[i][x]=0;
		b[i+m][x]=(b[i][x]^b[m][x]);
		b[i][x+m]=(b[i][x]^b[i][m]);
		b[i+m][x+m]=(b[i][x+m]^b[m][x+m]);
		int t1=f(i,x)+f(i+m,x)+f(i,x+m)+f(i+m,x+m);
		b[i][x]=1;
		b[i+m][x]=(b[i][x]^b[m][x]);
		b[i][x+m]=(b[i][x]^b[i][m]);
		b[i+m][x+m]=(b[i][x+m]^b[m][x+m]);
		int t2=f(i,x)+f(i+m,x)+f(i,x+m)+f(i+m,x+m);
		s+=max(t1,t2);
	}
	return s;
}
int main(){
	scanf("%d",&n),m=(n+1)/2;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	int ans=-1e9;
	for(int i=0;i<(1<<m);i++){
		for(int j=1;j<=m;j++)b[j][m]=((i>>j-1)&1);
		for(int j=m+1;j<=n;j++)b[j][m]=(b[m][m]^b[j-m][m]);
		int sum=0;
		for(int j=1;j<=n;j++)sum+=f(j,m);
		for(int k=1;k<m;k++)sum+=max(f1(k,0),f1(k,1));
		ans=max(ans,sum);
	}
	cout<<ans;
}