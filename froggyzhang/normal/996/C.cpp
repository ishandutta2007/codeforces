#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<tuple>
using namespace std;
#define N 123
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[5][N],vis[5][N],g;
//bool ok;
vector<tuple<int,int,int> > ans;
//vector<pair<int,int> > vec; 
//bool qwq;
//const int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//void dfs(int x,int y){
//	if(qwq)return;
//	vec.emplace_back(x,y);
//	vis[x][y]=1;
//	for(int i=0;i<4&&!qwq;++i){
//		int nx=x+d[i][0],ny=y+d[i][1];
//		if(ny<1||ny>n||vis[nx][ny])continue;
//		if(nx==1||nx==4){
//			if(g==a[nx][ny]){
//				qwq=true;
//				vec.emplace_back(nx,ny);
//				if(qwq){
//					a[nx][ny]=0;
//					ok=true;
//					for(int i=1;i<(int)vec.size();++i){
//						//ans.emplace_back(g,vec[i].first,vec[i].second);
//						cout<<vec[i].first<<" "<<vec[i].second<<endl;
//					}
//				}
//				--m;
//				break;
//			}
//		}
//		else if(!a[nx][ny]){
//			dfs(nx,ny);
//		}
//	}
//	vec.pop_back();
//}
int main(){
	n=read(),m=read();
	for(int i=1;i<=4;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
		}
	}
	for(int i=1,x=2,y=1;m;++i){
		if(i>2e7)return !printf("-1\n");
		int px=-1,py=-1;
		if(x==2){
			if(y==n){
				px=3,py=n;
			}
			else{
				px=2,py=y+1;
			}
		}
		else{
			if(y==1){
				px=2,py=1;
			}
			else{
				px=3,py=y-1;
			}
		}
		if(a[x][y]){
			int tox=(x==2?1:4),toy=y;
			if(a[x][y]==a[tox][toy]){
				--m;
				ans.emplace_back(a[x][y],tox,toy);
				a[x][y]=a[tox][toy]=0;
			}
			else if(!a[px][py]){
				ans.emplace_back(a[x][y],px,py);
				swap(a[x][y],a[px][py]);
			}
		}
		x=px,y=py;
	}
//	while(m){
//		ok=false;
//		for(int i=2;i<=3;++i){
//			for(int j=1;j<=n;++j){
//				g=a[i][j];
//				if(g){
//					qwq=false;
//					vec.clear();
//					cerr<<" now: "<<g<<endl;
//					memset(vis,0,sizeof(vis));
//					dfs(i,j);
//					if(qwq)a[i][j]=0,cerr<<" !! "<<i<<" "<<j<<endl;
//				}
//			}
//		}	
//		if(!ok)return !printf("-1\n");
//	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y,z]:ans){
		printf("%d %d %d\n",x,y,z);
	}
	return 0;
}