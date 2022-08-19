#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
int P[MAXN];

int main() {
ios_base::sync_with_stdio(0);
cin >> N;
for(int i = 0; i < N; i++) cin >> P[i];
P[N] = N+1;
int best_val = 1;
int best = 1;
while (best <= N && P[best-1] == best) best ++;
if (best == N+1) {
cout << 1 << '\n';
return 0;
}
int cur_val = 0;
int cur_max = P[0];
int cur_2 = 0;
for (int i = 1; i <= N; i++) {
  if (P[i] > cur_max) {
    if (cur_val > best_val || (cur_val == best_val && cur_max < best)) {
      best_val = cur_val; best = cur_max;
    }
    cur_val = 0;
    cur_2 = cur_max;
    cur_max = P[i];
  } else if (P[i] > cur_2) {
    cur_2 = P[i];
    cur_val ++;
  } else {
  }
}
cout << best << '\n';
}