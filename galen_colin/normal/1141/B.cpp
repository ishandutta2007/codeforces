#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void end(int i) {
  cout << i << endl;
  exit(0);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int best = 0, cur = 0;
    for (int i = 0; i < 2*n; i++) {
      if (arr[i%n]) cur++;
      else cur = 0;
      best = max(best, cur);
    }
    end(best);
}