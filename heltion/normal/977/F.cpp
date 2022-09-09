#include<bits/stdc++.h>
using namespace std;
map<int, int> m;
int F[200010], ans, ansi;
int Q[200010];
int main(){
	int N;
	scanf("%d", &N);
	int *A = new int[N + 1];
	for(int i = 1; i <= N; i += 1) scanf("%d", A + i);
	for(int i = 1; i <= N; i += 1){
		if(m.count(A[i] - 1) == 0) F[i] = 1, Q[i] = 0;
		else F[i] = F[m[A[i] - 1]] + 1, Q[i] = m[A[i] - 1];
		m[A[i]] = i;
		if(ans < F[i]) ansi = i, ans = F[i];
	}
	stack<int> s;
	printf("%d\n", ans);
	while(ansi){
		s.push(ansi);
		ansi = Q[ansi];
	}
	while(s.empty() == false) printf("%d ", s.top()), s.pop();
}