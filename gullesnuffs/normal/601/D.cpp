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

int c[300005];
char s[300005];
vector<int> adj[300005];

struct Node{
	int numDifferent;
	map<char, Node*> children;

	Node(){
		numDifferent=1;
	}

	void add(char c, Node* other){
		if(children.count(c)){
			children[c]->join(other);
		}
		else{
			children[c]=other;
		}
	}

	void join(Node* other){
		/*if(numDifferent < other->numDifferent){
			int pre=numDifferent;
			diff += other->join(this);
			numDifferent = other->numDifferent;
			children = other->children;
			return numDifferent-pre;
		}*/
		for(auto it=children.begin(); it != children.end(); ++it){
			if(other->children.count(it->first)){
				it->second->join(other->children[it->first]);
			}
		}
		for(auto it=other->children.begin(); it != other->children.end(); ++it){
			if(children.count(it->first))
				continue;
			children[it->first]=it->second;
			it->second->numDifferent;
		}
		numDifferent=1;
		for(auto it=children.begin(); it != children.end(); ++it){
			numDifferent += it->second->numDifferent;
		}
	}
};

int best;
vector<int> ans;
Node nodes[300005];

void rec(int node, int parent){
	rep(i,0,adj[node].size()){
		int to=adj[node][i];
		if(to == parent)
			continue;
		rec(to, node);
		nodes[node].add(s[to], nodes+to);
	}
	for(auto it=nodes[node].children.begin(); it != nodes[node].children.end(); ++it)
		nodes[node].numDifferent += it->second->numDifferent;
	int val=c[node]+nodes[node].numDifferent;
	if(val > best){
		ans.clear();
		ans.push_back(node);
		best=val;
	}
	else if(val == best){
		ans.push_back(node);
	}
}

int main(){
	best=-1;
	int n;
	scanf("%d", &n);
	rep(i,0,n)
		scanf("%d", c+i);
	scanf("%s", s);
	rep(i,0,n-1){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	rec(0, -1);
	assert(!ans.empty());
	printf("%d\n%d\n", best, ans.size());
}