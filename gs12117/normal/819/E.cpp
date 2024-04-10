#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<vector<int>> ans;
int main() {
	scanf("%d", &n);
	vector<int> v;
	if (n % 2 == 0) {
		v.clear();
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		ans.push_back(v);
		v.clear();
		v.push_back(1);
		v.push_back(2);
		v.push_back(4);
		ans.push_back(v);
		v.clear();
		v.push_back(1);
		v.push_back(3);
		v.push_back(4);
		ans.push_back(v);
		v.clear();
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		ans.push_back(v);
	}
	else {
		v.clear();
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		ans.push_back(v);
		v.clear();
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		ans.push_back(v);
	}
	for (int i = (n + 1) % 2 + 4; i < n; i += 2) {
		v.clear();
		v.push_back(i - 1);
		v.push_back(i);
		v.push_back(i + 1);
		ans.push_back(v);
		v.clear();
		v.push_back(i - 1);
		v.push_back(i);
		v.push_back(i + 1);
		ans.push_back(v);
		for (int j = 0; j < i - 2; j++) {
			int p = (2 * j) % (i - 2) + 1;
			int q = (2 * j + 1) % (i - 2) + 1;
			v.clear();
			v.push_back(p);
			v.push_back(i);
			v.push_back(q);
			v.push_back(i + 1);
			ans.push_back(v);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i].size());
		for (int j = 0; j < ans[i].size(); j++) {
			printf(" %d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}