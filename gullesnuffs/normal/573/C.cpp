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

vector<int> adj[100005];
int deg[100005];
int sz[100005];
bool done[100005];
queue<int> q;
int n;
map<pair<int, int>, int> childMap;
int leavesN;

int childrenN(int node, int parent){
	int ret=0;
	rep(i,0,adj[node].size()){
		int to=adj[node][i];
		if(to == parent)
			continue;
		int r=childrenN(to, node);
		ret += r;
		//ret += childrenN(to, node);
	}
	if(ret == 0)
		ret=1;
	if(ret == leavesN)
		--ret;
	childMap[make_pair(node, parent)]=ret;
	childMap[make_pair(parent, node)]=leavesN-ret;
	return ret;
}

int getChildN(int node, int parent){
	pair<int, int> p=make_pair(node, parent);
	return childMap[p];
}

bool isBad(int node){
	int numBad=0;
	rep(i,0,adj[node].size()){
		int to=adj[node][i];
		int cn=getChildN(to, node);
		if(cn >= 3 || (cn == 2 && adj[to].size() == 2))
			++numBad;
	}
	return numBad >= 3;
}

int main(){
	scanf("%d", &n);
	if(n == 1){
		puts("Yes");
		return 0;
	}
	rep(i,0,n-1){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		++deg[a];
		++deg[b];
	}
	rep(i,0,n)
		if(deg[i] == 1)
			++leavesN;
	childrenN(0, -1);
	rep(i,0,n){
		if(isBad(i)){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	/*rep(i,0,n){
		if(deg[i] == 1){
			q.push(i);
		}
	}
	int numBad=0;
	while(!q.empty()){
		int cur=q.front();
		done[cur]=1;
		q.pop();
		int numLarge=0;
		int largest=0;
		rep(i,0,adj[cur].size()){
			int to=adj[cur][i];
			if(!done[to]){
				--deg[to];
				if(deg[to] == 1){
					q.push(to);
				}
				continue;
			}
			if(sz[to] >= 3)
				++numLarge;
			sz[cur] += sz[to];
			largest=max(largest, sz[to]);
		}
		if(q.empty() && numBad && sz[cur]-largest >= 3){
			puts("No");
			return 0;
		}
		if(!sz[cur])
			++sz[cur];
		if(numLarge >= 2)
			++numBad;
		if(numLarge >= 3){
			puts("No");
			return 0;
		}
	}
	puts(numBad <= 1 ? "Yes" : "No");*/
}