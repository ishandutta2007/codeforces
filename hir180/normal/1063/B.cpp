#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dist[2005][2005];
char f[2005][2005];
int n,m,r,c,x,y;
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	x = min(x,10000000);
	y = min(y,10000000);
	r--; c--;
	rep(i,n) scanf("%s",&f[i]);
	rep(i,n) rep(j,m) dist[i][j] = INF;
	dist[r][c] = 0;
	deque<P1>que;
	que.push_back(mp(0,mp(r,c)));
	while(!que.empty()){
		P1 p = que.front(); que.pop_front();
		if(p.fi != dist[p.sc.fi][p.sc.sc]) continue;
		int X = p.sc.fi, Y = p.sc.sc;
		int dx[4]={0,1,0,-1};
		int dy[4]={1,0,-1,0};
		rep(k,4){
			int nx = X+dx[k], ny = Y+dy[k];
			if(!(0<=nx&&nx<n&&0<=ny&&ny<m)) continue;
			if(f[nx][ny] == '*') continue;
			int add = (k==2);
			if(dist[nx][ny] > p.fi+add){
				dist[nx][ny] = p.fi+add;
				if(add == 0) que.push_front(mp(p.fi+add,mp(nx,ny)));
				else que.push_back(mp(p.fi+add,mp(nx,ny)));
			}
		}
	}
	int ans = 0;
	rep(i,n)rep(j,m){
		int mnx = dist[i][j];
		int mny = j+dist[i][j]-c;
		if(mnx<=x && mny<=y) ans++;
	}
	cout << ans << endl;
}