#include <bits/stdc++.h>
using namespace std;

const int maxN = 500005;
long long A[maxN], sum[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	K++;
	sum[N + 1] = 0;
	sort(A + 1, A + N + 1);
	for(int i = N; i >= 1; i--){
		sum[i] = sum[i + 1] + A[i];
	}
	long long answer = 0;
	for(int cur = 0, i = 1; i <= N; i++){
		if(sum[i] < 0){
			answer += cur*A[i];
			if(i%K == 0 || sum[i + 1] >= 0)cur++;
		}else{
			answer += cur*A[i];
			cur++;
		}
	}
	cout << answer << '\n';

	return 0;
}