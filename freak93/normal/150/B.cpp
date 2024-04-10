#include <iostream>
#include <vector>

using namespace std;

int anc(vector<int> &A, int x) {
	if (A[x] == x)
		return x;
	return (A[x] = anc(A, A[x]));
}

void merge(vector<int> &A, int a, int b) {
	A[a] = b;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		A[i] = i;
	for (int i = 0; i < N - K + 1; ++i)
		for (int j = 0; j < K; ++j)
			if (anc(A, i + j) != anc(A, i + K - j - 1))
				merge(A, anc(A, i + j), anc(A, i + K - j - 1));
	
	vector<int> passed(N, 0);
	int many = 0;
	for (int i = 0; i < N; ++i)
		if (passed[anc(A, i)] == 0) {
			++many;
			passed[anc(A, i)] = 1;
		}
	
	int answer = 1;
	for (int i = 0; i < many; ++i)
		answer = (1LL * answer * M) % 1000000007;
	
	cout << answer;
}