#include<bits/stdc++.h>
using namespace std;

int A[4000];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) {
		int r = 1;
		for(int j = 0; j < N; j++) {
			if(A[j] > A[i]) r++;
		}
		cout << r << (i + 1 == N ? '\n' : ' ');
	}
	return 0;
}