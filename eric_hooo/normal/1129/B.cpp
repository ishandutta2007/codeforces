#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	vector <int> ans;
	ans.push_back(-1);
	k++;
	while (k + 1 >= 1000000){
		ans.push_back(1000000);
		k -= 1000000 - 1;
	}
	ans.push_back(k + 1);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}