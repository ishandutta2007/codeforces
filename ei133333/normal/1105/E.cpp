#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;


int N, M, T[100000], X[100000];
char t[45];
int64 NG[45];
int sum[45];
int beet;
bool G[40][40];

void dfs(int64 idx, int64 bit, int fake) {
  beet = max(beet, fake);
  if(idx == M) return;
  if(fake + sum[idx] <= beet) return;
  dfs(idx + 1, bit, fake);
  if((NG[idx] & bit) == 0) dfs(idx + 1, bit | (1LL << idx), fake + 1);
}

int main() {

  scanf("%d %d", &N, &M);
  map< string, int > st;
  for(int i = 0; i < N; i++) {
    scanf("%d", &T[i]);
    if(T[i] == 2) {
      scanf(" %s", t);
      string v(t);
      if(!st.count(v)) {
        int sz = (int) st.size();
        st[v] = sz;
      }
      X[i] = st[v];
    }
  }

  bitset< 100000 > add[40];
  int ptr = -1;
  for(int i = 0; i < N; i++) {
    if(T[i] == 1) {
      ptr++;
    } else {
      add[X[i]][ptr] = true;
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      G[i][j] = (add[i] & add[j]).none();
    }
  }

  for(int i = M - 1; i >= 0; i--) {
    sum[i] = sum[i + 1] + 1;
  }

  for(int i = 0; i < M; i++) {
    NG[i] = 0;
    for(int j = 0; j < M; j++) {
      if(!G[i][j]) NG[i] |= 1LL << j;
    }
  }

  dfs(0, 0, 0);
  cout << beet << endl;

}