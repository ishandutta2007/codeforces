#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 505
int n,m,a[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n==1&&m==1){puts("0");return 0;}
	if(m==1){
		for(int i=1;i<=n;++i)a[i][1]=i+1;	
	}
	else{
		for(int i=1;i<=m;++i)a[1][i]=i+1;
		for(int i=2;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=(m+i)*(j+1);		
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}