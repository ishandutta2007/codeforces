#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
int A[MAXN];
pair<int, int> V[MAXN];
bool wins[MAXN]; // first player win

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		V[i].first = A[i];
		V[i].second = i;
	}
	sort(V, V + N);
	reverse(V, V + N);

	for (int z = 0; z < N; z++) {
		int i = V[z].second;
		int a = V[z].first;
		assert(a == A[i]);
		wins[i] = false;
		for (int j = i % a; j < N; j += a) {
			if (A[j] > A[i]) {
				if (!wins[j]) {
					wins[i] = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << (wins[i] ? 'A' : 'B');
	}
	cout << '\n';

	return 0;
}