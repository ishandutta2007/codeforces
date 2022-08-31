#include<bits/stdc++.h>

using namespace std;
int N;
int A[200000];

int main() {
cin >> N;
for(int i = 0; i < N; i++) cin >> A[i];
bool isConst = true;
for(int i = 0; i < N; i++) if(A[i] != A[0]) isConst = false;
if(isConst) {
cout << 0 << '\n';
return 0;
}
int cur = N - 1;
while(cur > 0 && A[cur - 1] <= A[cur]) cur--;
for(int i = cur; true ; i ++, i %= N) {
if((i + 1) % N == cur) break;
if(A[i] > A[(i + 1) % N]) {
cout << -1;
return 0;
}

}
if(cur == 0) cout << 0 << '\n';
else cout << N - cur << '\n';
return 0;
}