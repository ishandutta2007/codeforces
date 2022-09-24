#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
double f[1005][1005];
int main(){
	cin>>n>>m>>x>>y;
	if(m==1)return printf("%.8lf\n",2.0*(n-x)),0;
	for(int i=n-1;i>=x;i--){
		for(int o=1;o<=50;o++){
			for(int j=2;j<m;j++)f[i][j]=(f[i][j]+f[i][j-1]+f[i+1][j]+f[i][j+1])/4+1;
			f[i][1]=(f[i][1]+f[i][2]+f[i+1][1])/3+1;
			f[i][m]=(f[i][m]+f[i][m-1]+f[i+1][m])/3+1;
		}
	}
	printf("%.8lf\n",f[x][y]);
    return 0;
}