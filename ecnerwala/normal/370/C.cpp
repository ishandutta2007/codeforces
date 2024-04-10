#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int C[10000];
int cnt[200];

int num;
int L[10000], R[10000];

void go() {
sort(C, C + N);
int m = 0;
for(int i = 1; i <= M; i++) if(cnt[i] > m) m = cnt[i];
if(m + m > N) num = (N - m) * 2;
else num = N;
for(int i = 0; i < N; i++) L[i] = C[i], R[i] = C[(i + m) % N];
}

int main(){
cin >> N >> M;
for(int i = 0; i < N; i++) {cin  >> C[i]; cnt[C[i]]++;}

go();

cout << num << '\n';
for(int i = 0; i < N; i++) cout << L[i] << ' ' << R[i] << '\n';
}