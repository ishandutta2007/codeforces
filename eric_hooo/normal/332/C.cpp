#include <bits/stdc++.h>
using namespace std;

struct Node{
	int a, b, id, id2;
}all[100010];

int cmp1(Node x, Node y){
	if (x.b != y.b) return x.b > y.b;
	return x.a < y.a;
}

int cmp2(Node x, Node y){
	if (x.a != y.a) return x.a > y.a;
	return x.id2 < y.id2;
}

int cmp3(Node x, Node y){
	return x.b < y.b;
}

int main(){
	int n, p, k;
	scanf("%d%d%d", &n, &p, &k);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &all[i].a, &all[i].b);
		all[i].id = i + 1;
	}
	sort(all, all + n, cmp1);
	vector <Node> v;
	for (int i = 0; i < n; i++){
		v.push_back(all[i]);
		v.back().id2 = i;
	}
	sort(v.begin(), v.begin() + n - (p - k), cmp2);
	int maxj = 0;
	for (int i = 0; i < k; i++){
		printf("%d ", v[i].id);
		maxj = max(maxj, v[i].id2);
	}
	for (int i = maxj + 1; i < maxj + 1 + (p - k); i++){
		printf("%d ", all[i].id);
	}
	printf("\n");
	return 0;
}