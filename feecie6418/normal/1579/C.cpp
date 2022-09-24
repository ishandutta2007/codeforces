#include<bits/stdc++.h>
using namespace std;
int n,m,K;
char a[25][25],b[25][25];
void Solve(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++)cin>>a[i]+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.')continue;
			int u=0;
			while(a[i-u][j-u]=='*'&&a[i-u][j+u]=='*')u++;
			if(u<=K)continue;
			for(int k=0;k<u;k++)b[i-k][j-k]=b[i-k][j+k]='*';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((a[i][j]=='*')!=(b[i][j]=='*'))return puts("NO"),void();
		}
	}
	puts("YES");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}