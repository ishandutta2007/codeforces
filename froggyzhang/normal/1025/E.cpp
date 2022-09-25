#include<bits/stdc++.h>
using namespace std;
#define y1 ysgh1
#define y2 ysgh2
#define N 55
typedef long long ll;
typedef pair<int,int> pii;
int n,m,a[N][N];
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
mt19937 rnd(time(0));
inline bool In(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=n;
}
vector<pair<pii,pii> > bfs(int sx,int sy,int tx,int ty){
	static pii pre[N][N];
	static int zyk,vis[N][N];
	queue<pii> q;
	++zyk;
	q.emplace(sx,sy);
	vis[sx][sy]=zyk;
	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop();
		if(x==tx&&y==ty)break;
		for(int i=0;i<4;++i){
			int nx=x+d[i][0],ny=y+d[i][1];
			if(In(nx,ny)&&vis[nx][ny]^zyk&&!a[nx][ny]){
				vis[nx][ny]=zyk;
				q.emplace(nx,ny);
				pre[nx][ny]=pii{x,y};
			}
		}
	}
	vector<pair<pii,pii> > ans;
	if(vis[tx][ty]^zyk){
		ans.emplace_back(pii{-1,-1},pii{-1,-1});
		return ans;
	}
	for(int x=tx,y=ty;x^sx||y^sy;tie(x,y)=pre[x][y]){
		ans.emplace_back(pre[x][y],pii{x,y});
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
vector<pair<pii,pii> > Solve(vector<pii> P){
	vector<pair<pii,pii> > ans;
	auto Move=[&](int x1,int y1,int x2,int y2)->void{
		swap(a[x1][y1],a[x2][y2]);
		ans.emplace_back(pii{x1,y1},pii{x2,y2});
	};
	auto Find=[&](int x)->pii{
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(a[i][j]==x)return make_pair(i,j);
			}
		}
		assert(false);
	};
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]=0;
	for(int i=0;i<(int)P.size();++i){
		a[P[i].first][P[i].second]=i+1;	
	}
	for(int i=m;i>=1;--i){
		while(true){
			auto [x,y]=Find(i);
			auto tmp=bfs(x,y,i,i);
			if(!(!tmp.empty()&&tmp[0].first.first==-1)){
				for(auto [t1,t2]:tmp){
					Move(t1.first,t1.second,t2.first,t2.second);
				}
				break;
			}
			while(true){
				int u=rnd()%i+1;
				int c=rnd()%4;
				auto [x,y]=Find(u);
				int nx=x+d[c][0],ny=y+d[c][1];
				if(In(nx,ny)&&!a[nx][ny]){
					Move(x,y,nx,ny);
					break;	
				}
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vector<pii> A,B;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		A.emplace_back(x,y);
	}
	auto a1=Solve(A);
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		B.emplace_back(x,y);
	}
	auto b1=Solve(B);
	for(auto &[a,b]:b1){
		swap(a,b);	
	}
	reverse(b1.begin(),b1.end());
	a1.insert(a1.end(),b1.begin(),b1.end());
	cout<<a1.size()<<'\n';
	for(auto [x,y]:a1){
		cout<<x.first<<' '<<x.second<<' '<<y.first<<' '<<y.second<<'\n';
	}
	return 0;
}