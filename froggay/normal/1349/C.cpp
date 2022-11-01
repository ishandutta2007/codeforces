#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const ll inf=2e18;
#define N 1010
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N][N],m,b[N][N],Q;
char s[N];
ll p[N][N];
const int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
inline bool IN(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
queue<pair<int,int> > q;
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j){
			a[i][j]=s[j]-'0';
			p[i][j]=inf;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=0;k<4;++k){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(!IN(nx,ny))continue;
				if(a[nx][ny]==a[i][j]){
					p[i][j]=0,q.push(make_pair(i,j));
					break;
				}
			}
		}
	}
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int k=0;k<4;++k){
			int nx=x+d[k][0],ny=y+d[k][1];
			if(!IN(nx,ny)||p[nx][ny]<inf)continue;
			p[nx][ny]=p[x][y]+1;
			q.push(make_pair(nx,ny));
		}
	}
	while(Q--){
		int x=read(),y=read();
		ll h=read();
		if(h<p[x][y]){
			printf("%d\n",a[x][y]);
		}
		else{
			printf("%d\n",a[x][y]^((h-p[x][y])&1));
		}
	}
//	for(int T=0;T<=10;++T){
//		printf("NOW: %d\n",T);
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=m;++j){
//				printf("%d ",a[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=m;++j){
//				if((i>1&&a[i-1][j]==a[i][j])||(i<n&&a[i+1][j]==a[i][j])||(j>1&&a[i][j-1]==a[i][j])||(j<m&&a[i][j+1]==a[i][j]))b[i][j]=a[i][j]^1;
//				else b[i][j]=a[i][j];
//			}
//		}
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=m;++j)a[i][j]=b[i][j];
//		}
//	}
	return 0;
}