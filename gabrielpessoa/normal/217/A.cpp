#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 105;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int arr[SIZE];
ii arrP[SIZE];

int setFind(int p) {
	if(p != arr[p]) {
		arr[p] = setFind(arr[p]);
	}
	return arr[p];
}

void setUnion(int a, int b) {
	arr[setFind(a)] = setFind(b);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		arr[i] = i;
	}
	
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arrP[i] = make_pair(a, b);
		for(int j = 0; j < i; j++) {
			if(arrP[i].first == arrP[j].first || arrP[i].second == arrP[j].second) {
				setUnion(i, j);
			}
		}
	}
	int numero = -1;
	set<int> ds;
	for(int i = 0; i < n; i++) {
		if(!ds.count(setFind(i))) {
			numero++;
			ds.insert(setFind(i));
		}
	}
	printf("%d\n", numero);
	return 0;
}