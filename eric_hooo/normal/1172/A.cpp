#include <bits/stdc++.h>
using namespace std;

int a[200010], b[200010];
int T[200010];
int n;
int dist[200010];

void add(int x){
	if (x == 0) return ;
	while (x <= n) T[x]++, x += x & -x;
}

int query(int x){
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

bool check(int x){
	for (int i = 1; i <= n; i++){
		if (dist[i] - x >= i) return 0;
	}
	return 1;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if (a[i]) add(a[i]);
		dist[a[i]] = 0;
	}
	int pos = -1;
	for (int j = 0; j < n; j++){
		scanf("%d", &b[j]);
		dist[b[j]] = j + 1;
		if (b[j] == 1) pos = j;
	}
	if (pos != -1){
		for (int i = pos + 1; i < n; i++){
			if (b[i] != b[i - 1] + 1){
				pos = -1;
				break;
			}
		}
	}
	if (pos != -1){
		int k = n - pos;
		int flag = 1;
		for (int i = k + 1; i <= n; i++){
			if (dist[i] >= i - k){
				flag = 0;
				break;
			}
		}
		if (flag){
			printf("%d\n", n - k);
			return 0;
		}
	}
	int l = 0, r = n;
	while (l < r){
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", n + l);
	return 0;
}