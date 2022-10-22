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

vector<int> colorNode[100005];
map<int, int> colorComp[100005];
map<int, vector<int> > adj[100005];
set<int> belongs[100005];
vector<int> belV[100005];

bool rec(int node, int c, int comp){
	if(colorComp[c].find(node) != colorComp[c].end())
		return false;
	colorComp[c][node]=comp;
	vector<int>* v = &adj[c][node];
	for(auto it=v->begin(); it != v->end(); ++it){
		int to=*it;
		rec(to, c, comp);
	}
	return true;
}

map<pair<int, int>, int> saved;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,m){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;--b;--c;
		colorNode[c].push_back(a);
		colorNode[c].push_back(b);
		belongs[a].insert(c);
		belongs[b].insert(c);
		adj[c][a].push_back(b);
		adj[c][b].push_back(a);
	}
	rep(i,0,n){
		for(auto it=belongs[i].begin(); it != belongs[i].end(); ++it){
			belV[i].push_back(*it);
		}
	}
	rep(i,0,m){
		int compN=0;
		rep(j,0,colorNode[i].size()){
			if(rec(colorNode[i][j], i, compN))
				++compN;
		}
	}
	int q;
	scanf("%d", &q);
	rep(i,0,q){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;--v;
		if(belongs[v].size() < belongs[u].size())
			swap(u,v);
		int ans=0;
		if(saved.find(make_pair(u,v)) != saved.end())
			ans=saved[make_pair(u,v)];
		else if(saved.find(make_pair(v,u)) != saved.end())
			ans=saved[make_pair(v,u)];
		else{
		if(belV[v].size() < belV[u].size()*30){
			auto it1=belV[u].begin();
			auto it2=belV[v].begin();
			while(it1 != belV[u].end() && it2 != belV[v].end()){
				if(*it1 == *it2){
					if(colorComp[*it1][u] == colorComp[*it1][v])
						++ans;
					++it1;
					++it2;

				}
				else if(*it2 < *it1){
					++it2;
				}
				else
					++it1;
			}
		}
		else{
		for(auto it=belV[u].begin(); it != belV[u].end(); ++it){
			if(belongs[v].find(*it) == belongs[v].end())
				continue;
			if(colorComp[*it][u] == colorComp[*it][v])
				++ans;
		}
		}
		saved[make_pair(u,v)]=ans;
		}
		printf("%d\n", ans);
	}
}