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

char name[105][105];
vector<int> adj[256];
int deg[256];

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n)
		scanf("%s", name[i]);
	rep(i,0,n-1){
		int j;
		for(j=0; name[i][j] == name[i+1][j]; ++j){
		}
		if(name[i][j] == 0)
			continue;
		char c1=name[i][j];
		char c2=name[i+1][j];
		adj[c1].push_back(c2);
		++deg[c2];
	}
	queue<int> q;
	rep(c,'a','z'+1)
		if(!deg[c])
			q.push(c);
	string alpha;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		alpha.push_back(cur);
		rep(i,0,adj[cur].size()){
			--deg[adj[cur][i]];
			if(!deg[adj[cur][i]])
				q.push(adj[cur][i]);
		}
	}
	if(alpha.size() == 26)
		cout << alpha << endl;
	else
		puts("Impossible");
}