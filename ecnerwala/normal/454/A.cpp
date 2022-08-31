#include<iostream>

using namespace std;

int main() {
int N; cin >> N;
for(int i = 0; i < N; i++) {
for(int j = 0; j < N; j++) {
if(min(i, N - 1 - i) + min(j, N - 1 - j) < N / 2) cout << '*';
else cout << 'D';
}
cout << '\n';
}
return 0;
}