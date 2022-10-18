#include <bits/stdc++.h>
#define maxn 1000005
int n,tl,a[maxn],x[maxn];
std::stack<int>stk;
char opt[maxn][5];
void NO() { puts("NO"); exit(0); }
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= 2*n; ++ i) {
		scanf("%s",opt[i] + 1);
		if (opt[i][1] == '+') 
			stk.push(++tl);
		else {
			scanf("%d",&x[i]);
			if (stk.empty()) NO();
			a[stk.top()] = x[i];
			stk.pop();
		}
	} 
	std::set<int>S;
	tl = 0;
	for (int i = 1; i <= 2*n; ++ i) {
		if (opt[i][1] == '+') S.insert(a[++tl]);
		else {
			int p = *S.begin();
			if (p != x[i]) NO();
			S.erase(S.begin());
		}
	} puts("YES");
	for (int i = 1; i <= n; ++ i) printf("%d ",a[i]);
	return 0;
}