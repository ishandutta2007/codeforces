#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
double f[2005][2005];
int n,m,is[2005][2];
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,is[x][0]=is[y][1]=1;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)cnt1+=(is[i][0]),cnt2+=(is[i][1]);
	for(int i=n;i>=0;i--){
		for(int j=n;j>=0;j--){
			if(i==n&&j==n)continue;
			f[i][j]=(1+1.0*(n-i)*j/n/n*f[i+1][j]+1.0*(n-j)*i/n/n*f[i][j+1]+1.0*(n-i)*(n-j)/n/n*f[i+1][j+1])/(1-1.0*i*j/n/n);
		}
	}
	printf("%.10lf",f[cnt1][cnt2]);
}