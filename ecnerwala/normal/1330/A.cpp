#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N, X; cin >> N >> X; set<int> A;
for (int i = 0; i < N; i++) { int a; cin >> a; A.insert(a); }
int v = 1;
for (;; v++) {
if (A.count(v)) continue;
if (X) {X--; continue;}
break;
}
cout << v-1 << '\n';
}}