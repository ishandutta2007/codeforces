#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int A[MAXN];
int V[MAXN];
int N;
int main() {
cin >> N;
for(int i = 0; i < N; i++) cin >> A[i], A[i] --;
vector<int> v;
for(int i = 0; i <  N; i++) V[i] = -1;
for(int i = 0; i < N; i++) {
if(V[A[i]] == -1) V[A[i]] = i;
else v.push_back(i);
}
for(int i = 0; i < N; i++) {
if(V[i] == -1) V[i] = v.back(), v.pop_back();
}
for(int i = 0; i < N; i++) {
A[V[i]] = i + 1;
}
for(int i = 0; i < N; i++) cout << A[i] << ' '; cout << '\n';
}