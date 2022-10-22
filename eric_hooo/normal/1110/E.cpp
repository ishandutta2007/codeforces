#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < n; j++){
		scanf("%d", &b[j]);
	}
	vector <int> v1, v2;
	for (int i = 1; i < n; i++){
		v1.push_back(a[i] - a[i - 1]);
		v2.push_back(b[i] - b[i - 1]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	printf(a[0] == b[0] && v1 == v2 ? "Yes\n" : "No\n");
	return 0;
}