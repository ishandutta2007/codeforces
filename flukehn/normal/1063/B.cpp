#include<bits/stdc++.h>
using namespace std;
const int N=2111;
char s[N][N];
int n,m,a[N][N],b[N][N],c[N][N];
void bfs(int x,int y){
	deque<int> X,Y;
	c[x][y]=1;
	X.push_front(x),Y.push_front(y);
	memset(a,0x3f,sizeof a);
	memset(b,0x3f,sizeof b);
	a[x][y]=b[x][y]=0;
	int i;
	while(!X.empty()){
		x=X.front(),X.pop_front();
		y=Y.front(),Y.pop_front();
		if(x>1&&!c[x-1][y]&&s[x-1][y]=='.')
			c[x-1][y]=1,a[x-1][y]=a[x][y],b[x-1][y]=b[x][y],X.push_front(x-1),Y.push_front(y);
		if(x<n&&!c[x+1][y]&&s[x+1][y]=='.')
			c[x+1][y]=1,a[x+1][y]=a[x][y],b[x+1][y]=b[x][y],X.push_front(x+1),Y.push_front(y);
		if(y>1&&!c[x][y-1]&&s[x][y-1]=='.')
			c[x][y-1]=1,a[x][y-1]=a[x][y]+1,b[x][y-1]=b[x][y],X.push_back(x),Y.push_back(y-1);
		if(y<m&&!c[x][y+1]&&s[x][y+1]=='.')
			c[x][y+1]=1,a[x][y+1]=a[x][y],b[x][y+1]=b[x][y]+1,X.push_back(x),Y.push_back(y+1);
	}
}
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	int r,c,i,j,x,y,an=0;
	cin>>n>>m>>r>>c>>x>>y;
	for(i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	bfs(r,c);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a[i][j]<=x&&b[i][j]<=y&&s[i][j]=='.')
				++an;//cerr<<i<<" "<<j<<endl;
	cout<<an<<endl;
}