#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

vector<vector<int>> all;


// SCC: https://www.geeksforgeeks.org/strongly-connected-components/
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // An array of adjacency lists 
  
    // Fills Stack with vertices (in increasing order of finishing 
    // times). The top element of stack has the maximum finishing  
    // time 
    void fillOrder(int v, bool visited[], stack<int> &Stack); 
  
    // A recursive function to print DFS starting from v 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V); 
    void addEdge(int v, int w); 
  
    // The main function that finds and prints strongly connected 
    // components 
    void printSCCs(); 
  
    // Function that returns reverse (or transpose) of this graph 
    Graph getTranspose(); 
}; 
  
Graph::Graph(int _V) 
{ 
    this->V = _V; 
    adj = new list<int>[_V]; 
} 
  
// A recursive function to print DFS starting from v 
vector<int> last;
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    last.push_back(v);
    //~ cout << v << " "; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph Graph::getTranspose() 
{ 
    Graph g(V); 
    for (int v = 0; v < V; v++) 
    { 
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            g.adj[*i].push_back(v); 
        } 
    } 
    return g; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to vs list. 
} 
  
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            fillOrder(*i, visited, Stack); 
  
    // All vertices reachable from v are processed by now, push v  
    Stack.push(v); 
} 
  
// The main function that finds and prints all strongly connected  
// components 
void Graph::printSCCs() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited (For first DFS) 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Fill vertices in stack according to their finishing times 
    for(int i = 0; i < V; i++) 
        if(visited[i] == false) 
            fillOrder(i, visited, Stack); 
  
    // Create a reversed graph 
    Graph gr = getTranspose(); 
  
    // Mark all the vertices as not visited (For second DFS) 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Now process all vertices in order defined by Stack 
    while (Stack.empty() == false) 
    { 
        // Pop a vertex from stack 
        int v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        { 
			last.clear();
            gr.DFSUtil(v, visited); 
            all.push_back(last);
            //~ cout << endl; 
        } 
    } 
}

const int nax = 2e5 + 5;
int gg[nax];
vector<int> inv[nax];
int in[nax];
vector<int> memo[nax];
  
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Graph gr(n);
	vector<pair<int,int>> edges;
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		gr.addEdge(a, b);
		edges.emplace_back(a, b);
		memo[a].push_back(b);
	}
	gr.printSCCs();
	debug() << imie(all);
	for(int i = 0; i < (int) all.size(); ++i) {
		inv[i] = all[i];
		for(int x : all[i]) {
			gg[x] = i;
		}
	}
	for(pair<int,int> p : edges) {
		if(gg[p.first] != gg[p.second]) {
			++in[gg[p.second]];
		}
	}
	int a = -1;
	for(int i = 0; i < n; ++i) {
		if(!in[gg[i]]) {
			a = i;
			break;
		}
	}
	assert(a != -1);
	set<int> ggs; // available groups
	for(int i = 0; i < (int) all.size(); ++i) {
		if(in[i] == 0) {
			ggs.insert(i);
		}
	}
	{
		int me = gg[a];
		for(int i = 0; i < (int) inv[me].size(); ++i) {
			if(inv[me][i] == a) {
				swap(inv[me][i], inv[me].back());
				inv[me].pop_back();
			}
		}
	}
	
	auto rem = [&](int g) {
		g = gg[g];
		if(!inv[g].empty()) {
			return;
		}
		for(int x : all[g]) {
			for(int y : memo[x]) {
				if(gg[x] == gg[y]) {
					continue;
				}
				if(--in[gg[y]] == 0) {
					ggs.insert(gg[y]);
				}
				assert(in[gg[y]] >= 0);
			}
		}
		ggs.erase(g);
	};
	
	while(true) {
		int me = gg[a];
		if((int) ggs.size() == 1) {
			assert(ggs == set<int>{me});
			break;
		}
		auto it = ggs.find(me);
		if(it == ggs.begin()) {
			++it;
		}
		else {
			--it;
		}
		int he = *it;
		int b = inv[he].back();
		inv[he].pop_back();
		printf("? %d %d\n", a + 1, b + 1);
		fflush(stdout);
		int r;
		scanf("%d", &r);
		if(r == 1) {
			// from a to b, skip b
			rem(b);
		}
		else {
			assert(r == 0);
			// change a to b
			rem(a);
			a = b;
		}
	}
	printf("! %d\n", a + 1);
}