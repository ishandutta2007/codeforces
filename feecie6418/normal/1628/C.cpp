#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1005][1005],cnt[1005][1005],ans=0;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void Do(int x,int y){
	ans^=a[x][y];
	for(int i=0;i<4;i++){
		int p=x+dx[i],q=y+dy[i];
		if(p<1||p>n||q<1||q>n)continue;
		cnt[p][q]^=1;
	}
}
void Solve(){
	scanf("%d",&n),ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)Do(1,i);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cnt[i-1][j]==0)Do(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cnt[i][j]=0;
	//	puts("");
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}