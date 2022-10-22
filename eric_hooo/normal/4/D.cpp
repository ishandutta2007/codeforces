#include <bits/stdc++.h>
using namespace std;

struct Node{
	int w, h, num;
	bool operator < (const Node &A) const{
		return w < A.w;
	}
}a[5010];

int f[5010], p[5010];

int main(){
	int n, W, H;
	scanf("%d%d%d", &n, &W, &H);
	a[0].h = H, a[0].w = W, a[0].num = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &a[i].w, &a[i].h);
		a[i].num = i;
	}
	sort(a + 1, a + n + 1);
	f[0] = 0;
	int ans = 0, pos = 0;
	for (int i = 1; i <= n; i++){
		f[i] = -1;
		if (a[0].w >= a[i].w || a[0].h >= a[i].h) continue;
		for (int j = 0; j < i; j++){
			if (a[j].w >= a[i].w || a[j].h >= a[i].h) continue;
			if (f[i] < f[j] + 1) f[i] = f[j] + 1, p[i] = j;
		}
		if (f[i] == -1) continue;
		if (f[i] > ans) ans = f[i], pos = i;
	}
	printf("%d\n", ans);
	if (ans == 0) return 0;
	vector <int> v;
	while (pos != 0){
		v.push_back(a[pos].num);
		pos = p[pos];
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}