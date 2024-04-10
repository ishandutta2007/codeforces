#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
vector<pair<int, int> > ans;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	if(m < n - 1){
		printf("Impossible");
		return 0;
	}
	for(int i = 1; i < n; i += 1) ans.push_back({i, i + 1});
	for(int i = 1; i < n && ans.size() < m; i += 1)
		for(int j = i + 2; j <= n && ans.size() < m; j += 1)
			if(gcd(i, j) == 1) ans.push_back({i, j});
	if(ans.size() < m){
		printf("Impossible");
		return 0;
	}
	printf("Possible\n");
	for(auto p : ans)
		printf("%d %d\n", p.first, p.second);
}