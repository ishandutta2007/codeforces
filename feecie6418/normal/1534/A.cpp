#include<bits/stdc++.h>
using namespace std;
int n,m,is[2][2];
char a[55][55];
void Solve(){
	cin>>n>>m,memset(is,0,sizeof(is));
	for(int i=1;i<=n;i++){
		cin>>a[i]+1;
		for(int j=1;j<=m;j++){
			if(a[i][j]=='R')is[(i+j)&1][0]=1;
			if(a[i][j]=='W')is[(i+j)&1][1]=1;
		}
	}
	if(is[0][0]&&is[0][1])return puts("NO"),void();
	if(is[1][0]&&is[1][1])return puts("NO"),void();
	if(is[0][0]&&is[1][0])return puts("NO"),void();
	if(is[0][1]&&is[1][1])return puts("NO"),void();
	if(is[0][0])is[1][1]=1;
	if(is[0][1])is[1][0]=1;
	if(is[1][0])is[0][1]=1;
	if(is[1][1])is[0][0]=1;
	if(!is[0][0]&&!is[0][1]&&!is[1][0]&&!is[1][1])is[0][0]=is[1][1]=1;
	puts("YES");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(is[(i+j)&1][0])cout<<'R';
			else cout<<'W';
		}
		puts("");
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}