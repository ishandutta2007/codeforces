#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5;
int N;
int A[MAXN+2];
const int MAXQ = 3e5;
int Q;
int cnt[MAXQ];
int main() {
 ios_base::sync_with_stdio(0);
 cin >> N >> Q;
 A[0] = 1;
 for (int i = 1; i <= N; i++) {
  cin >> A[i];
 }
 A[N+1] = 1;
 for (int i = 0; i <= N+1; i++) cnt[A[i]]++;
 if (!cnt[Q]) {
  if(!cnt[0]) { cout << "NO\n"; return 0; }
  for (int i = 1; i <= N; i++) {
   if (A[i] == 0) {A[i] = Q; cnt[0]--, cnt[Q]++; break;}
  }
 }
 priority_queue<int> s;
 for (int i = 0; i <= N; i++) {
  if (A[i]) {
   s.push(A[i]);
   while (!cnt[s.top()])s.pop();
   if (s.top() != A[i]) { cout << "NO\n"; return 0; }
   --cnt[A[i]];
  } else A[i] = s.top();
 }
 cout << "YES\n";
 for (int i = 1; i <= N; i++) { cout << A[i] << ' '; } cout << '\n';
}