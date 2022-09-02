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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int x[3],y[3];
int dist[1005][1005][3];
P pre[1005][1005][3];
bool used[1005][1005][3];
int main(){
	rep(i,3) cin>>x[i]>>y[i];
	rep(i,3){
		queue<P>que;
		que.push(mp(x[i],y[i]));
		rep(p,1005)rep(q,1005)dist[p][q][i] = INF;
		dist[x[i]][y[i]][i] = 0;
		pre[x[i]][y[i]][i] = mp(-1,-1);
		while(!que.empty()){
			P p = que.front(); que.pop();
			if(used[p.fi][p.sc][i]) continue; used[p.fi][p.sc][i] = 1;
			int dx[4]={0,1,0,-1};
			int dy[4]={1,0,-1,0};
			rep(k,4){
				int nx = p.fi+dx[k];
				int ny = p.sc+dy[k];
				if(0<=nx&&nx<=1002 && 0<=ny&&ny<=1002){
					if(dist[nx][ny][i] > dist[p.fi][p.sc][i]+1){
						dist[nx][ny][i] = min(dist[nx][ny][i],dist[p.fi][p.sc][i]+1);
						pre[nx][ny][i] = p;
					}
					if(!used[nx][ny][i])
						que.push(mp(nx,ny));
				}
			}
		}
	}
	int ans = INF;
	rep(i,3){
		int cnt = 3;
		rep(j,3){
			if(i == j) continue;
			cnt += dist[x[j]][y[j]][i]-1;
		}
		ans = min(ans,cnt);
	}
	for(int X=0;X<=1002;X++)for(int Y=0;Y<=1002;Y++){
		int cnt = 4;
		rep(j,3){
			cnt += dist[X][Y][j]-1;
		}
		ans = min(ans,cnt);
	}
	rep(i,3){
		int cnt = 3;
		rep(j,3){
			if(i == j) continue;
			cnt += dist[x[j]][y[j]][i]-1;
		}
		if(cnt == ans){
			vector<P>vec;
			rep(j,3){
				if(i == j) continue;
				P cur = mp(x[j],y[j]);
				while(1){
					vec.pb(cur);
					if(pre[cur.fi][cur.sc][i].fi == -1) break;
					cur = pre[cur.fi][cur.sc][i];
				}
			}
			SORT(vec); ERASE(vec);
			cout<<vec.size()<<endl;
			rep(i,vec.size()){
				cout<<vec[i].fi<<" "<<vec[i].sc<<endl;
			}
			return 0;
		}
	}
	for(int X=0;X<=1002;X++)for(int Y=0;Y<=1002;Y++){
		int cnt = 4;
		rep(j,3){
			cnt += dist[X][Y][j]-1;
		}
		if(cnt == ans){
			vector<P>vec;
			rep(j,3){
				P cur = mp(X,Y);
				while(1){
					vec.pb(cur);
					if(pre[cur.fi][cur.sc][j].fi == -1) break;
					cur = pre[cur.fi][cur.sc][j];
				}
			}
			SORT(vec); ERASE(vec);
			cout<<vec.size()<<endl;
			rep(i,vec.size()){
				cout<<vec[i].fi<<" "<<vec[i].sc<<endl;
			}
			return 0;
		}
	}
}