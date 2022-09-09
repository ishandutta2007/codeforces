#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q[2];
int main(){
	int n, s = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		int a;
		scanf("%d", &a);
		q[a & 1].push(a);
		s += a;
	}
	while(not q[0].empty() and not q[1].empty()){
		s -= q[0].top() + q[1].top();
		q[0].pop();
		q[1].pop();
	}
	if(not q[0].empty()) s -= q[0].top();
	if(not q[1].empty()) s -= q[1].top();
	printf("%d", s);
}