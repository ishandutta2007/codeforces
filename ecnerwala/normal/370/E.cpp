#include<iostream>
#include<algorithm>

using namespace std;

int N;
int A[400000];
int mi[400000];
int ma[400000];

bool go() {
mi[0] = 1 * 6 + 1;
ma[0] = 1 * 6 + 1;
if(A[0] && A[0] != 1) return false;
for(int i = 1; i < N; i++) {

if(mi[i - 1] % 6 == 5) mi[i] = (mi[i - 1] / 6 + 1) * 6 + 1;
else mi[i] = mi[i - 1] + 1;

if(ma[i - 1] % 6 >= 2) ma[i] = (ma[i - 1] / 6 + 1) * 6 + 1;
else ma[i] = ma[i - 1] + 1;

if(A[i]) {
if(mi[i] / 6 > A[i] || ma[i] / 6 < A[i]) return false;
mi[i] = max(mi[i], A[i] * 6 + 1);
ma[i] = min(ma[i], A[i] * 6 + 5);
}

}

if(ma[N - 1] % 6 == 1) {
ma[N - 1] -= 2;
if(ma[N - 1] < mi[N - 1]) return false;
}

A[N - 1] = ma[N - 1] / 6;
for(int i = N - 2; i >= 0; i--) {
ma[i] = min(ma[i], (ma[i + 1] % 6 == 1) ? (ma[i + 1] - 2) : (ma[i + 1] - 1));
A[i] = ma[i] / 6;
}
return true;
}

int main() {
cin >> N;
for(int i = 0; i < N; i++) cin >> A[i];

if(go()) {
cout << A[N - 2] << '\n';
for(int i = 0; i < N; i++) cout << A[i] << ' '; cout << '\n';
} else {
cout << -1 << '\n';
}
return 0;
}