#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 4000, MAXM = 4000;

int N, M;
int A[MAXN], B[MAXM];

int main() {
	cin >> M >> N;
	for(int i = 0; i < M; i++) cin >> B[i];
	for(int i = 0; i < N; i++) cin >> A[i];
	int res = 0;
	sort(A, A + N);
	sort(B, B + M);
	reverse(B, B + M);
	reverse(A, A + N);
	int cur = 0;
	for(int i = 0; i < M; i++) {
		if(cur < N && A[cur] >= B[i]) {
			cur++;
		} else {
			res ++;
		}
	}
	cout << res << '\n';
	return 0;
}