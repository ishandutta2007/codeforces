#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e6;

int N;
int P[MAXN];
int v[MAXN];
int m1[MAXN];

int main() {
	scanf("%d", &N);
	P[0] = -1;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &P[i]);
		P[i] --;
		m1[i] = 0;
		v[i] = 1;
		int val = 1;
		for(int cur = i; P[cur] >= 0; cur = P[cur]) {
			int par = P[cur];
			if(val > m1[par]) {
				m1[par] = val;
			} else if(val == m1[par]) {
				val++;
			}
			if(val > v[par]) {
				v[par] = val;
			} else {
				break;
			}
		}
		//for(int j = 0; j <= i; j++) {
			//cerr << j << ' ' << P[j] << ' ' << v[j] << ' ' << m1[j] << ' ' << m2[j] << '\n';
		//}
		printf("%d ", m1[0]);
	}
	printf("\n");
	return 0;
}