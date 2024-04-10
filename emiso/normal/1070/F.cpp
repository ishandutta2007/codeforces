#include <bits/stdc++.h>

using namespace std;

int tot, n, t, inf;
priority_queue<int> q00, q01, q10, q11, qo;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &t, &inf);
		if(t == 00) q00.push(inf);
		if(t == 10) q10.push(inf);
		if(t == 01) q01.push(inf);
		if(t == 11) q11.push(inf);
	}
	
	while(!q01.empty() && !q10.empty()) {
		tot += q01.top(); q01.pop();
		tot += q10.top(); q10.pop();
	}
	qo = (q01.empty()) ? q10 : q01;
	
	while(!q11.empty()) {
		tot += q11.top(); q11.pop();
		
		if(!q00.empty() && !qo.empty()) {
			if(q00.top() > qo.top()) {
				tot += q00.top(); q00.pop();
			} else {
				tot += qo.top(); qo.pop();
			}
		} else if(!q00.empty()) {
			tot += q00.top(); q00.pop();
		} else if(!qo.empty()) {
			tot += qo.top(); qo.pop();
		}
	}
		
	printf("%d\n", tot);
	return 0;
}