#include <bits/stdc++.h>

int qs,opt,m,id=0,vis[1000005];

int main() {
	scanf("%d",&qs);
	std::priority_queue<std::pair<int,int> >q;
	std::priority_queue<int>q2;
	while (qs-->0) {
		scanf("%d",&opt);
		if (opt == 1) {
			scanf("%d",&m);
			++id;
			q.push(std::make_pair(m,-id));
			q2.push(-id);
		} else if (opt == 2) {
			int u;
			while (1) {
				u = -q2.top(); q2.pop();
				if (!vis[u]) break;
			}
			vis[u] = 1;
			printf("%d ",u);
		}
		else if (opt == 3) {
			int u;
			while (1) {
				auto P = q.top(); q.pop();
				u = -P.second;
			//	printf("(%d %d)\n",P.first,u);
				if (!vis[u]) break;
			} vis[u] = 1;
			printf("%d ",u);
		}
	}
	return 0;
}