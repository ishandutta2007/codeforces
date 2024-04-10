#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int a[N], A[N][N], B[N][N], C[N][N];

void power(int T){
	if(T == 1){
		memcpy(B, A, sizeof(B));
		return;
	}
	if(T%2 == 0){
		power(T >> 1);
		memset(C, 0, sizeof(C));
		for(int st = 0; st < N; st++){
			for(int mi = st; mi < N; mi++){
				for(int en = mi; en < N; en++){
					C[st][en] = max(C[st][en], B[st][mi] + B[mi][en]);
				}
			}
		}
		memcpy(B, C, sizeof(B));
		return;
	}
	power(T - 1);
	memset(C, 0, sizeof(C));
	for(int st = 0; st < N; st++){
		for(int mi = st; mi < N; mi++){
			for(int en = mi; en < N; en++){
				C[st][en] = max(C[st][en], B[st][mi] + A[mi][en]);
			}
		}
	}
	memcpy(B, C, sizeof(B));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, T;
	cin >> n >> T;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(A, 0, sizeof(A));
	for(int i = 0; i < n; i++){
		for(int st = 0; st <= a[i]; st++){
			int tmp = 0;
			for(int en = st; en <= a[i]; en++){
				tmp = max(tmp, A[st][en] + 1);
			}
			A[st][a[i]] = max(A[st][a[i]], tmp);
		}
		A[a[i]][a[i]] = max(A[a[i]][a[i]], 1);
	}
	for(int st = 0; st < N; st++){
		for(int en = st; en + 1 < N; en++){
			A[st][en + 1] = max(A[st][en + 1], A[st][en]);
		}
	}
	power(T);
	int answer = 0;
	for(int st = 0; st < N; st++){
		for(int en = st; en < N; en++){
			answer = max(answer, B[st][en]);
		}
	}
	cout << answer << '\n';

	return 0;
}