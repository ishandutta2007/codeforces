#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,Q,vst[1005][1005],dis[1005][1005];
char a[1005][1005];
struct Pr{
	int x,y;
};
queue<Pr> q;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==a[i][j-1]||a[i][j]==a[i+1][j]||a[i][j]==a[i][j+1]||a[i][j]==a[i-1][j]){
				dis[i][j]=1;
				q.push({i,j});
			}
		}
	}
	while(!q.empty()){
		Pr now=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			Pr t;
			t.x=now.x+dx[i],t.y=now.y+dy[i];
			if(t.x<1||t.y<1||t.x>n||t.y>m)continue;
			if(dis[t.x][t.y]==0x3f3f3f3f){
				dis[t.x][t.y]=dis[now.x][now.y]+1;
				q.push(t);
			} 
		}
	}
	while(Q--){
		int i,j;
		ll t;
		scanf("%d%d%lld",&i,&j,&t);
	//	cout<<dis[i][j]<<endl;
		if(dis[i][j]==0x3f3f3f3f||t<dis[i][j])printf("%c\n",a[i][j]);
		else if((t-dis[i][j])%2)printf("%c\n",a[i][j]);
		else printf("%c\n",a[i][j]^1);
	}
	return 0;
}