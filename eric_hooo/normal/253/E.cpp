#include <bits/stdc++.h>
using namespace std;

const long long INF = 1ll * 0x3f3f3f3f * 0x3f3f3f3f;

struct Node{
	int num;
	long long st, s, p;
	bool operator < (const Node &A) const{
		return p < A.p;
	}
}a[50010], b[50010];

long long et[50010];
int pos, n;

bool cmp_t(Node a, Node b){
	return a.st < b.st;
}

priority_queue <Node> q;

long long check(long long mid){
	int p = 0;
	for (int i = 0; i < n; i++){
		if (a[i].p == -1){
			a[i].p = mid;
			p = i;
			break;
		}
	}
	while (!q.empty()) q.pop();
	for (int i = 0; i < n; i++){
//		if (mid == 4) cout << i << endl;
		q.push(a[i]);
		long long t = a[i + 1].st - a[i].st;
		long long now = 0;
		while (!q.empty() && now <= t){
			Node top = q.top();
			now += top.s;
			if (now <= t){
				et[top.num] = a[i].st + now, q.pop();
			}
		}
		if (q.empty()) continue;
		Node top = q.top(); q.pop();
		now -= top.s, top.s -= t - now;
		q.push(top);
	} 
	a[p].p = -1;
	return et[pos];
}

vector <long long> can;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%I64d%I64d%I64d", &a[i].st, &a[i].s, &a[i].p);
		a[i].num = i;
		if (a[i].p == -1) pos = i;
		b[i] = a[i];
	}
	sort(a, a + n, cmp_t);
	a[n].st = INF;
	long long T;
	scanf("%I64d", &T);
	sort(b, b + n);
	if (b[1].p > 1) can.push_back(1);
	for (int i = 1; i < n - 1; i++){
		if (b[i].p + 1 != b[i + 1].p) can.push_back(b[i].p + 1);
	}
	can.push_back(b[n - 1].p + 1);
	int l = 0, r = can.size() - 1;
	while (l + 10 < r){
		int mid = (l + r) >> 1;
		if (check(can[mid]) > T) l = mid + 1;
		else r = mid;
	}
	int i;
	for (i = l; i < r; i++){
		if (check(can[i]) == T) break;
	}
	printf("%d\n", can[i]);
	check(can[i]);
	for (int i = 0; i < n; i++){
		printf("%I64d ", et[i]);
	}
	printf("\n");
	return 0;
}