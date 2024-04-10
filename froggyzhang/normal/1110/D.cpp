#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,m,s[N],dp[N][3][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		++s[x];	
	}
	for(int i=1;i<=m;++i){
		for(int x=0;x<=2;++x){
			for(int y=0;y<=2;++y){
				for(int z=0;z<=2;++z){
					if(s[i]<x+y+z)continue;
					dp[i][y][z]=max(dp[i][y][z],dp[i-1][x][y]+z+(s[i]-x-y-z)/3);	
				}		
			}
		}	
	}
	cout<<dp[m][0][0]<<'\n';
	return 0;
}