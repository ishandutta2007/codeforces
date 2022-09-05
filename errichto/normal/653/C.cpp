#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 5;
int t[nax], count_bad, n;
bool bad[nax], important[nax];
void consider(int i) {
	if(i < 0) return;
	if(i == n - 1) return;
	bool should = false;
	if(i % 2 == 0 && t[i] >= t[i+1])
		should = true;
	if(i % 2 == 1 && t[i] <= t[i+1])
		should = true;
	if(bad[i] != should) {
		if(should) ++count_bad;
		else --count_bad;
		bad[i] = should;
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &t[i]);
	for(int i = 0; i < n - 1; ++i)
		consider(i);
	int answer = 0;
	int x = -1;
	for(int i = 0; i < n - 1; ++i)
		if(bad[i]) {
			x = i;
			break;
		}
	assert(x != -1);
	for(int i = x; i <= x+1; ++i)
		for(int j = 0; j < n; ++j) if(i != j) {
			if(i == x + 1 && j == x) continue; // because we counted it when i==x, j==x+1
			swap(t[i], t[j]);
			consider(i); consider(i-1); consider(j); consider(j-1);
			if(count_bad == 0) ++answer;
			swap(t[i], t[j]);
			consider(i); consider(i-1); consider(j); consider(j-1);
		}
	printf("%d\n", answer);
	return 0;
}