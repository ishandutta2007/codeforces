#include<bits/stdc++.h>
using namespace std;
int n,m,f[35][35],D[35][35],R[35][35];
void Solve(int n){
	if(n==1)return ;
	Solve(n>>1);
	for(int i=0;i<n/2;i++){
		for(int j=n/2;j<n;j++){
			f[i][j]=f[i%(n/2)][(n/2)-1-j%(n/2)]+(n/2)*(n/2)*1;
		}
	}
	for(int i=n/2;i<n;i++){
		for(int j=0;j<n/2;j++){
			f[i][j]=f[(n/2)-1-i%(n/2)][j%(n/2)]+(n/2)*(n/2)*2;
		}
	}
	for(int i=n/2;i<n;i++){
		for(int j=n/2;j<n;j++){
			f[i][j]=f[(n/2)-1-i%(n/2)][(n/2)-1-j%(n/2)]+(n/2)*(n/2)*3;
		}
	}
}
int main(){
	cin>>n>>m;
	Solve(32);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i)D[i-1][j]=(f[i][j]^f[i-1][j]);
			if(j)R[i][j-1]=(f[i][j]^f[i][j-1]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++)cout<<R[i][j]<<' ';
		cout<<endl;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++)cout<<D[i][j]<<' ';
		cout<<endl;
	}
	int cx=0,cy=0;
	for(int i=1;i<=m;i++){
		int x,A=0,B=0;
		cin>>x;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if((f[cx][cy]^f[j][k])==x){
					A=j,B=k;
				}
			}
		}
		cout<<A+1<<' '<<B+1<<endl;
		cx=A,cy=B;
	}
}