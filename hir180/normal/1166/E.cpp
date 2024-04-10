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

int n,m;
bitset<100005>B[105];
bool used[55][100005];
vector<P>edge[105];
int dist[105];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		int a; scanf("%d",&a);
		rep(x,a){
			int w; scanf("%d",&w);
			used[i][w] = 1;
			B[i][w] = 1;
		}
		for(int j=1;j<=m;j++) if(!used[i][j]) B[i+n][j] = 1;
		edge[i].push_back(mp(i+n,-1));
	}
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=2*n;j++){
			if(i == j) continue;
			//i -> j iff vec[i] > vec[j]
			bitset<100005>C = B[i]&B[j];
			if(C.count() == B[j].count()){
				edge[i].pb(mp(j,0)); //cout << i << " " << j << endl;
			}
		}
	}
	for(int i=0;i<105;i++) dist[i] = 0;
	int last = -1;
	rep(x,305){
		for(int j=1;j<=2*n;j++){
			for(int k=0;k<edge[j].size();k++){
				int to = edge[j][k].fi;
				int cs = edge[j][k].sc;
				if(dist[to] > dist[j]+cs){
					dist[to] = dist[j]+cs;
					last = max(last,x);
				}
			}
		}
	}
	if(last > 200){
		cout << "impossible" << endl;
	}
	else{
		cout << "possible" << endl;
	}
}