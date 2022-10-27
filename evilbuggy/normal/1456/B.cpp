#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;
int A[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	A[0] = 0;
	for(int i = 1; i <= N; i++){
		cin >> A[i]; A[i] ^= A[i - 1];
	}
	if(N > 100){
		cout << 1 << '\n';
		return 0;
	}
	int answer = -1;
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j++){
			for(int k = j + 1; k <= N; k++){
				if((A[j]^A[i - 1]) > (A[k]^A[j])){
					if(answer == -1){
						answer = k - i - 1;
					}
					answer = min(answer, k - i - 1);
				}
			}
		}
	}
	cout << answer << '\n';

	return 0;
}