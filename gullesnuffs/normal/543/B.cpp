#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int n, m;
int s1, t1, l1, s2, t2, l2;
vector<int> adj[3005];
vector<int> d[3005];
vector<int> dis;

vector<int> getDis(int node){
	dis=vector<int>(3005);
	rep(i,0,n)
		dis[i]=1000000;
	dis[node]=0;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		rep(i,0,adj[cur].size()){
			int to=adj[cur][i];
			if(dis[to] != 1000000)
				continue;
			dis[to]=dis[cur]+1;
			q.push(to);
		}
	}
	return dis;
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i,0,m){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
	--s1;--t1;--s2;--t2;
	rep(i,0,n)
		d[i]=getDis(i);
	if(d[s1][t1] > l1 || d[s2][t2] > l2){
		puts("-1");
		return 0;
	}
	int need=d[s1][t1]+d[s2][t2];
	rep(i,0,n)
		rep(j,0,n){
			int d1=min(d[s1][i]+d[t1][j], d[s1][j]+d[t1][i]);
			int d2=min(d[s2][i]+d[t2][j], d[s2][j]+d[t2][i]);
			if(d1+d[i][j] > l1 || d2+d[i][j] > l2)
				continue;
			int tmp=d1+d2+d[i][j];
			need=min(need, tmp);
			/*if(d[s1][i]+d[i][j]+d[j][t1] > l1 || d[t2][i]+d[i][j]+d[j][s2] > l2)
				continue;
			int tmp=d[s1][i]+d[s2][i]+d[i][j]+d[t1][j]+d[t2][j];
			need=min(need, tmp);
			tmp=d[s1][i]+d[s2][j]+d[i][j]+d[t1][j]+d[t2][i];
			need=min(need, tmp);*/
		}
	printf("%d\n", m-need);
}