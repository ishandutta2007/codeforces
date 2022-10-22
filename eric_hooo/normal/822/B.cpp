#include <bits/stdc++.h>
using namespace std;

char s[1010], t[1010];

int main(){
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s%s", s, t);
	vector <int> ans;
	ans.resize(10000);
	for (int i = 0; i <= m - n; i++){
		vector <int> now;
		for (int j = 0; j < n; j++){
			if (t[i + j] != s[j]) now.push_back(j + 1);
		}
		if (ans.size() > now.size()) ans = now;
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}