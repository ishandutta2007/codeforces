#include<iostream>

using namespace std;

int N;
int M, K;
int A[2000];

int main() {
cin >> N >> M >> K;
for(int i = 0; i < N; i++) cin >> A[i];
int c1 = 0, c2 = 0;
for(int i = 0; i < N; i++) {if(A[i] == 1) c1++; else c2++; }


if(c2 < K) K = c2;
int res = (c1 + c2 - M - K);
if(res < 0) res = 0;
cout << res << '\n';
return 0;
}