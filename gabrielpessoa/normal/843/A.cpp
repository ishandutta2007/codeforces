#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1E5 + 5;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef vector<int> vi;

ii arr[SIZE];
vi g[SIZE];
bool existe[SIZE];
int ds[SIZE];

int n;

int make_set() {
	for(int i = 1; i <= n; i++) {
		ds[i] = i;
	}
}

int find_set(int a) {
	if(a != ds[a]) {
		ds[a] = find_set(ds[a]);
	}
	return ds[a];
}

int union_set(int a, int b) {
	ds[find_set(a)] = find_set(b);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr[i] = ii(x, i+1);
	}
	sort(arr, arr+n);
	make_set();
	for(int i = 0; i < n; i++) {
		union_set(i+1, arr[i].second);
	}
	for(int i = 1; i <= n; i++) {
		g[i].clear();
		existe[i] = false;
	}
	int count = 0;
	for(int i = 1; i <= n; i++) {
		g[find_set(i)].push_back(i);
		if(!existe[find_set(i)]) {
			existe[find_set(i)] = true;
			count++;
		}
	}
	printf("%d\n", count);
	for(int i = 1; i <= n; i++) {
		if(!existe[i]) continue;
		printf("%d ", g[i].size());
		for(int x : g[i]) {
			printf("%d ", x);
		}
		printf("\n");
	}
}