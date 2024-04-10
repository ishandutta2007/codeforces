#include <bits/stdc++.h>

int n,a[1000005];
std::vector<std::pair<int,int> >v;

int divi(int x,int y) { return (x + y - 1) / y; }

void work(int x,int y) {
	a[x] = divi(a[x],a[y]);
	v.push_back({x,y});
}

void solve() {
	scanf("%d",&n); v.clear();
	for (int i = 1; i <= n; ++ i) a[i] = i;
	for (int i = n - 1; i > 2; i --) {
		while (divi(a[n],a[i]) >= a[i]) work(n,i);
		work(i,n);
	} while (a[n] >= 2) { work(n,2); }
//	for (int i = 1; i <= n; ++ i) printf("%d ",a[i]); puts("");
	printf("%d\n",v.size());
	for (auto x:v) printf("%d %d\n",x.first,x.second);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}