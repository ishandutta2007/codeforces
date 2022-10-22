#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


int inf = pow(10, 9);
long long big_inf = pow(10, 18);
int n, m, k, p, ans;
bool lul[1000000 + 228];


int main(){
	ios_base::sync_with_stdio(false);	
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i){
		cin >> p;
		lul[p] = true;
	}

	ans = 1;
	int u, v;
	for (int i = 0; i < k; ++i){
		cin >> u >> v;

		if (ans == u && (!lul[u])){
			ans = v;
		}
		else if (ans == v && (!lul[v])){
			ans = u;
		}
	}

	cout << ans;
	return 0;
}