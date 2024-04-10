#include<bits/stdc++.h>
using namespace std;
#define y1 ysgh1
#define y2 ysgh2
const int inf=0x3f3f3f3f;
#define N 1010
typedef long long ll;
int n,m,dis1[N][N],dis2[N][N];
int x1,x2,y1,y2,ex,ey;
pair<int,int> pre1[N][N],pre2[N][N];
const int d[8][2]={{1,-2},{1,2},{-1,-2},{-1,2},{2,1},{2,-1},{-2,1},{-2,-1}};
inline int In(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;	
}
void bfs(int sx,int sy,int dis[][N],pair<int,int> pre[][N]){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			dis[i][j]=inf;
	dis[sx][sy]=0;
	queue<pair<int,int> > q;
	q.push(make_pair(sx,sy));
	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<8;++i){
			int nx=x+d[i][0],ny=y+d[i][1];
			if(In(nx,ny)&&dis[nx][ny]==inf){
				dis[nx][ny]=dis[x][y]+1;
				pre[nx][ny]=make_pair(x,y);
				q.push(make_pair(nx,ny));
			}
		}
	}
}
inline bool check(int x1,int y1,int x2,int y2){
	for(int i=0;i<8;++i){
		if(x2==x1+d[i][0]&&y2==y1+d[i][1]){
			return true;
		}	
	}
	return false;
}
void Read(int x,int y){
	int tx,ty;
	cin>>tx>>ty;
	if(tx<=0){exit(0);}
	if(check(x,y,tx,ty)){
		cout<<tx<<' '<<ty<<endl;
		exit(0);
	}
}
inline void Ask(int x,int y){
	cout<<x<<' '<<y<<endl;
	if(x==ex&&y==ey)exit(0);
	Read(x,y);
}
void Go(int x,int y,pair<int,int> pre[][N]){
	while(true){
		auto t=pre[x][y];
		x=t.first,y=t.second;
		if(!x)break;
		Ask(x,y);
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>x1>>y1>>x2>>y2;
	if(check(x1,y1,x2,y2)){
		cout<<"WHITE"<<endl<<x2<<' '<<y2<<endl;
		return 0;
	}
	bfs(n/2,m/2,dis1,pre1);
	bfs(n/2+1,m/2,dis2,pre2);
	if(((x1+y1)&1)^((x2+y2)&1)){ // white eat black
		if(dis1[x1][y1]<=dis2[x2][y2]){
			cout<<"WHITE"<<endl;ex=n/2,ey=m/2;
			Go(x1,y1,pre1);
		}
		else if(dis2[x1][y1]>=dis2[x2][y2]+2){
			cout<<"BLACK"<<endl;ex=n/2+1,ey=m/2;
			Read(x2,y2);
			Go(x2,y2,pre2);
		}
		else{
			cout<<"WHITE"<<endl;ex=n/2,ey=m/2;
			Go(x1,y1,pre2);
			Go(n/2+1,m/2,pre1);
		}
	}
	else{	// black eat white 
		if(dis2[x2][y2]<dis1[x1][y1]){
			cout<<"BLACK"<<endl;ex=n/2+1,ey=m/2;
			Read(x2,y2);
			Go(x2,y2,pre2);
		}
		else if(dis1[x2][y2]>=dis1[x1][y1]+1){
			cout<<"WHITE"<<endl;ex=n/2,ey=m/2;
			Go(x1,y1,pre1);
		}
		else{
			cout<<"BLACK"<<endl;ex=n/2+1,ey=m/2;
			Read(x2,y2);
			Go(x2,y2,pre1);
			Go(n/2,m/2,pre2);	
		}
	}
	return 0;
}