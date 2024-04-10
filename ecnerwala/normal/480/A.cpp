#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 1e4;

int N;
pii V[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> V[i].A >> V[i].B;
	}
	sort(V, V + N);

	int cur = 0;
	for(int i = 0; i < N; i++) {
		//cerr << V[i].A << ' ' << V[i].B << '\n';
		if(V[i].B >= cur) cur = V[i].B;
		else if(V[i].A >= cur) cur = V[i].A;
		else assert(false);
	}
	cout << cur << '\n';
	return 0;
}