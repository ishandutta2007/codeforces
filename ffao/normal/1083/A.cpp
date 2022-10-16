#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


typedef pair<int, int> pii;


vector<pii> g[410000];
long long w[410000];
long long best = 0;
int n;

long long dfs(int v, int p) {
	long long ans = w[v];

	vector<long long> scs;
	for (pii x : g[v]) if (x.first != p) {
		scs.push_back(dfs(x.first,v) - x.second);
	}

	sort(scs.begin(), scs.end());
	
	best = max(best, w[v]);
	if (!scs.empty()) best = max(best, w[v] + scs.back());
	if (scs.size() >= 2) best = max(best, w[v] + scs.back() + scs[scs.size()-2]);

	if (!scs.empty()) ans = max(ans, scs.back() + w[v]);
	return ans;
}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &w[i]);
    for (int i = 0; i < n-1; i++) {
    	int a,b,c;
    	scanf("%d %d %d", &a, &b, &c); a--; b--;
    	g[a].push_back({b,c});
    	g[b].push_back({a,c});
    }

    dfs(0,-1);
    printf("%lld\n", best);
}


#include <fstream>


int main() {


    solve();
}