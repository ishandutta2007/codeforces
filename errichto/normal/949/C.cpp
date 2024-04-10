#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

typedef long long ll;

// http://www.algorytm.org/algorytmy-grafowe/silnie-spojne-skladowe/sss-1-c.html

const int nax = 1e5 + 5;
vector<int> graf[nax], grafT[nax], silna_vec[nax], memo[nax];
int visited[nax], visited2[nax], NR[nax];

int nr=1;//do numeracji
int silna=0;//do ilosci silni

void dfs(int v){//DFS
     visited[v]=1;
     while(!graf[v].empty()){
              int z = graf[v].back();
              graf[v].pop_back();
              if(visited[z]==false){
                   visited[z]=1;
                   dfs(z);
              }
     }
     NR[nr]=v;nr++;//post order !!! WAZNE 
}

void sss(int v){
     visited2[v]=1;//puszczamy takjakby dfs na odwrocony grafie .. ilosc dfs'ow to ilosc SSS
     while(!grafT[v].empty()){
              int z = grafT[v].back();
              grafT[v].pop_back();
              if(visited2[z]==false){
                   silna_vec[silna].push_back(z);
                   visited2[z]=1;
                   sss(z);
              }
     }
}

int main() {
	int n, m, h;
	scanf("%d%d%d", &n, &m, &h);
	vector<int> level(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &level[i]);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		for(int rep = 0; rep < 2; ++rep) {
			if((level[a] + 1) % h == level[b]) {
				graf[a+1].push_back(b+1);
				memo[a+1].push_back(b+1);
				grafT[b+1].push_back(a+1);
			}
			swap(a, b);
		}
	}
	 for(int i = 1; i <= n ; i++) if(visited[i]==false) dfs(i);//puszczamy dfs(y)
   for(int i = n; i >= 1 ; i--) if(visited2[NR[i]]==false) {
        sss(NR[i]);
        silna_vec[silna].push_back(NR[i]);
        silna++;
   }//wyszukujemy silna

	vector<int> which(n + 1);
	for(int i = 0; i < silna ; i++)
		for(int x : silna_vec[i])
			which[x] = i;
	int small = INT_MAX;
	vector<int> print;
	for(int i = 0; i < silna; ++i) {
		bool ok = true;
		for(int x : silna_vec[i]) for(int y : memo[x]) if(which[x] != which[y])
			ok = false;
		if(!ok) continue;
		if((int) silna_vec[i].size() < small) {
			small = silna_vec[i].size();
			print = silna_vec[i];
		}
	}
	printf("%d\n", (int) print.size());
	for(int x : print) printf("%d ", x);
	puts("");
}