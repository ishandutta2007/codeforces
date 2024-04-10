#include<iostream>

using namespace std;

int N, K;
int A[2000];

int main() {
cin >> N >> K;
for(int i =0 ; i < N; i++ )cin >> A[i];
int res = 0;
for(int i = 0; i < K; i++) {
int s = 0;
for(int j = 0; j < N / K; j++) {
s += A[j * K + i] - 1;
}
res += min(s, N / K - s);
}
cout << res << '\n';
return 0;
}