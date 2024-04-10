#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int M[200];
bool A[200][200];

bool ans[200];

//whether i can win before j
bool isGood(int i, int j) {
for(int k = 1; k <= 100; k++) if(A[j][k] && !A[i][k]) return true;
return false;
}

void go() {
for(int i = 0; i < N; i++) {
ans[i] = true;
for(int j = 0; j < N; j++) {
if(j == i) continue;
if(!isGood(i, j)) ans[i] = false;
}
}
}

int main() {
cin >> N;
for(int i = 0; i < N; i++) {
cin >> M[i];

for(int j = 0; j < M[i]; j++) {
int v; cin >> v;
A[i][v] = true;
}
}
go();
for(int i = 0; i < N; i++) cout << (ans[i] ? "YES" : "NO") << '\n';
}