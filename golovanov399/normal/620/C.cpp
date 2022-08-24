#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	vector<itn> a(n);
	for (int i = 0; i < n; i++)
		a[i] = nxt();
	map<int, int> M;
	vector<int> pr(n, -1);
	for (int i = 0; i < n; i++){
		if (M.count(a[i]))
			pr[i] = M[a[i]];
		M[a[i]] = i;
	}

	vector<int> dp(n, -1);
	for (int i = 1; i < n; i++){
		dp[i] = max(dp[i - 1], pr[i]);
	}

	if (dp[n - 1] == -1){
		puts("-1");
	} else {
		vector<pair<int, int>> ans;
		int i = n - 1;
		while (i >= 0){
			ans.push_back({dp[i], i});
			i = dp[i] - 1;
			if (i >= 0 && dp[i] == -1){
				ans.back().first = 0;
				i = -1;
			}
		}
		printf("%d\n", (int)ans.size());
		for (auto p : ans)
			printf("%d %d\n", p.x + 1, p.y + 1);
	}

	return 0;
}