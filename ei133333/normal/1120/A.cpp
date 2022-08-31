#include<bits/stdc++.h>

using namespace std;

int main() {
  int M, K, N, S, A[500000];
  scanf("%d %d %d %d", &M, &K, &N, &S);
  for(int i = 0; i < M; i++) {
    scanf("%d", &A[i]);
    --A[i];
  }

  int mp[500001] = {};
  for(int i = 0; i < S; i++) {
    int x;
    scanf("%d", &x);
    --x;
    mp[x]++;
  }

  int ok = 0;
  for(int i = 0; i < 500000; i++) ok += mp[i] == 0;


  int ptr = 0;
  vector< int > pos(M, -1);
  for(int i = 0; i < M; i++) {
    while(ptr < M && ok < 500000) {
      mp[A[ptr]]--;
      ok += mp[A[ptr]] == 0;
      ++ptr;
    }
    if(ok == 500000) pos[i] = ptr;
    ok -= mp[A[i]] == 0;
    mp[A[i]]++;
  }

  // N
  for(int i = 0; i < M; i++) {
    if(pos[i] == -1) continue;
    int times = i / K + (M - pos[i]) / K + 1;
    if(times >= N) {
      vector< int > rem;
      for(int k = 0; k < i % K; k++) rem.emplace_back(k);
      bool need[500000] = {};
      for(int k = i; k < pos[i]; k++) {
        if(mp[A[k]] >= 1) need[k] = true;
        mp[A[k]]--;
      }
      int most = (pos[i] - i) - K;
      for(int k = i; k < pos[i]; k++) {
        if(!need[k]) {
          if(most > 0) {
            --most;
            rem.emplace_back(k);
          }
        }
      }
      printf("%d\n", (int) rem.size());
      for(auto &p : rem) printf("%d ", p + 1);
      puts("");
      return 0;
    }
  }
  cout << -1 << endl;
}