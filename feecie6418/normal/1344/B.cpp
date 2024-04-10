#include<bits/stdc++.h>
using namespace std;
int n,m,v[1005][1005];
char a[1005][1005];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int i,int j){
	v[i][j]=1;
	for(int k=0;k<4;k++){
		int x=i+dx[k],y=j+dy[k];
		if(v[x][y])continue;
		if(a[x][y]=='#')dfs(x,y);
	}
}
bool che1(){
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=1;j<=m;j++)s+=(a[i][j]=='.');
		if(s==m)return 1;
	}
	return 0;
}
bool che2(){
	for(int i=1;i<=m;i++){
		int s=0;
		for(int j=1;j<=n;j++)s+=(a[j][i]=='.');
		if(s==n)return 1;
	}
	return 0;
}
int main(){
	cin>>n>>m;
	int tmps=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]+1;
		for(int j=1;j<=m;j++){
			if(a[i][j]=='#')tmps++;
		}
	}
	if(!tmps)return puts("0"),0;
	if(che1()^che2())return puts("-1"),0;
	for(int i=1;i<=n;i++){
		int fir=0,lst=-1;
		for(int j=1;j<=m;j++){
			if(a[i][j]=='#'){
				fir=j;
				break;
			}
		}
		for(int j=m;j>=1;j--){
			if(a[i][j]=='#'){
				lst=j;
				break;
			}
		}
		for(int j=fir;j<=lst;j++)if(a[i][j]!='#')return puts("-1"),0;
	}
	for(int i=1;i<=m;i++){
		int fir=0,lst=-1;
		for(int j=1;j<=n;j++){
			if(a[j][i]=='#'){
				fir=j;
				break;
			}
		}
		for(int j=n;j>=1;j--){
			if(a[j][i]=='#'){
				lst=j;
				break;
			}
		}
		for(int j=fir;j<=lst;j++)if(a[j][i]!='#')return puts("-1"),0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='#'&&!v[i][j])dfs(i,j),sum++;
		}
	}
	cout<<sum;
	return 0;
}