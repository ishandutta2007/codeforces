#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	int t;
	cin>>t;
	while(t--){
		bool is[25][25]={0};
		cin>>n>>m,is[1][1]=is[1][m]=is[n][1]=is[n][m]=1;
		for(int i=2;i<m;i++)if(!is[1][i-1]&&!is[1][i+1])is[1][i]=1;
		for(int i=2;i<m;i++)if(!is[n][i-1]&&!is[n][i+1])is[n][i]=1;
		for(int i=2;i<n;i++)if(!is[i-1][1]&&!is[i+1][1])is[i][1]=1;
		for(int i=2;i<n;i++)if(!is[i-1][m]&&!is[i+1][m])is[i][m]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)cout<<is[i][j];
			puts("");
		}
		puts("");
	}
}