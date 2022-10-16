#include <vector> 
#include <cstdio> 
#include <cstring>
 
using namespace std; 

typedef vector<long long> vll;

int n, b;
const long long INF = 1000000000000000000LL;
int value[5100];
int discount[5100];
int p[5100];
vector<int> adj[5100];
 
pair<vll, vll> dfs(int v) {
	vll ans = {0, value[v]};
	vll ans_ok = {INF, value[v] - discount[v]};

	for (int i : adj[v]) {
		pair<vll, vll> pp = dfs(i);

		vll t_ok = pp.first;
		vll t_notok = pp.second;

		int aS = ans.size();
		int tS = t_ok.size();

		ans.resize(aS + tS - 1, INF);
		ans_ok.resize(aS + tS - 1, INF);

		for (int i = aS-1; i >= 0; i--) {
			for (int j = 0; j < tS; j++) {
				ans[i+j] = min(ans[i+j], ans[i]+t_notok[j]);
				ans_ok[i+j] = min(ans_ok[i+j], ans_ok[i]+t_ok[j]);
			}
		}
	}
	
	for (int i = 0; i < ans.size(); i++) ans_ok[i] = min(ans_ok[i], ans[i]);
	return {ans_ok, ans};
}
 
int main() {
	scanf("%d %d", &n, &b);
 	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &value[i], &discount[i]);
		if (i > 0) {
			scanf("%d", &p[i]);
			p[i]--;
			adj[p[i]].push_back(i);
		}
	}
 
 	vll kn = dfs(0).first;

	int ans = 0;
	for (int i = 0; i < kn.size(); i++) {if (kn[i] <= b) ans = i;}
	printf("%d\n", ans);
}