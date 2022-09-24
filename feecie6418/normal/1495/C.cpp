#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char str[505][505];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",str[i]+1);
		if(i%3==1)for(int j=1;j<=m;j++)str[i][j]='X';
		if(i>3&&i%3==1){
			bool flag=0;
			for(int j=1;j<=m&&!flag;j++)if(str[i-1][j]=='X'||str[i-2][j]=='X')str[i-1][j]=str[i-2][j]='X',flag=1;
			if(!flag)str[i-1][1]=str[i-2][1]='X';
		}
	}
	if(n%3==0){
		for(int i=1;i<=m;i++)if(str[n][i]=='X')str[n-1][i]='X';
	}
	for(int i=1;i<=n;i++)cout<<str[i]+1<<'\n';
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)str[i][j]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
    return 0;
}