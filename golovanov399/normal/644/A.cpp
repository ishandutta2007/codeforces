#include <bits/stdc++.h>

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	int a = nxt(), b = nxt();
	if (n <= a * b){
		for (int i = 0; i < a; i++){
			vector<int> ans;
			for (int j = 0; j < b; j++){
				ans.push_back(max(n, 0));
				n--;
			}
			if (i % 2)
				reverse(ans.begin(), ans.end());
			for (auto x : ans)
				printf("%d ", x);
			puts("");
		}
	} else {
		puts("-1");
	}

	return 0;
}