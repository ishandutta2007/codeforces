#include<bits/stdc++.h>
using namespace std;

const int MAXN = int(3e5);
int N;
int P[MAXN];
void pr(int i) {
  if (P[i]) pr(P[i]);
  cout << i << " \n"[i==N];
}
int main() {
ios_base::sync_with_stdio(0);
cin >> N;
for (int i = 2; i <= N; i++) cin >> P[i];
pr(N);
}