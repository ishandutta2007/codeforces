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
int n;
int a1,a2,b1,b2,c1,c2;
bool used[1005][1005];
int main(){
	cin>>n>>a1>>a2>>b1>>b2>>c1>>c2;
	queue<P>que;
	que.push(mp(b1,b2));
	while(!que.empty()){
		P p = que.front(); que.pop();
		if(used[p.fi][p.sc]) continue;
		used[p.fi][p.sc] = 1;
		int dx[8]={0,0,1,1,1,-1,-1,-1};
		int dy[8]={1,-1,-1,0,1,-1,0,1};
		rep(k,8){
			int nx = p.fi+dx[k];
			int ny = p.sc+dy[k];
			if(1<=nx && nx<=n && 1<=ny && ny<=n){
				if(a1 == nx || a2 == ny || a1-a2 == nx-ny || a1+a2 == nx+ny) continue;
				que.push(mp(nx,ny));
			}
		}
	}
	if(used[c1][c2]) puts("YES");
	else puts("NO");
}