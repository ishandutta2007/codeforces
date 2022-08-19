#include <bits/stdc++.h>
using namespace std;

int main() {
int T; cin >> T;
while (T--) {
int A, B; cin >> A >> B;
if (A > B) {
for (int i = 0; i < A-B; i++) cout << '0';
for (int i = 0; i < B; i++) cout << "10";
} else {
for (int i = 0; i < B-A; i++) cout << '1';
for (int i = 0; i < A; i++) cout << "01";
}
cout << '\n';
}
}