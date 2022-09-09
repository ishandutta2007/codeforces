#include<bits/stdc++.h>
using namespace std;
#define maxn 3000
pair<int, int> nodes[maxn];
int p[maxn];
int main(){
	int n, k, sum = 0;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i += 1){
		scanf("%d", &nodes[i].first);
		nodes[i].second = i;
	}
	sort(nodes, nodes + n, greater<pair<int, int> >());
	for(int i = 0; i < k; i += 1) sum += nodes[i].first, p[i] = nodes[i].second;
	sort(p, p + k);
	printf("%d\n", sum);
	for(int i = 0; i < k; i += 1){
		if(i == 0) printf("%d ", k == 1 ? n : p[i] + 1);
		else if(i == k - 1) printf("%d ", n - p[i - 1] - 1);
		else printf("%d ", p[i] - p[i - 1]);  
	}
}