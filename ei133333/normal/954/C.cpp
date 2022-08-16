#include<bits/stdc++.h>

using namespace std;

const int LIM = 1000000000;

const int vy[] = {1, 0, -1, 0};
const int vx[] = {0, 1, 0, -1};

int main() {
  int N, A[200000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  bool iscontinue = true;
  for(int i = 1; i < N; i++) {
    if(A[i - 1] == A[i]) {
      cout << "NO" << endl;
      return (0);
    }
    iscontinue &= abs(A[i - 1] - A[i]) <= 1;
  }

  if(iscontinue) {
    cout << "YES" << endl;
    cout << LIM << " " << LIM << endl;
    return (0);
  }

  int w = 0;
  for(int i = 1; i < N; i++) {
    if(abs(A[i - 1] - A[i]) <= 1) continue;
    w = abs(A[i - 1] - A[i]);
  }

  for(int i = 1; i < N; i++) {
    int y1 = (A[i] - 1) / w, x1 = (A[i] - 1) % w;
    int y2 = (A[i - 1] - 1) / w, x2 = (A[i - 1] - 1) % w;

    bool match = false;
    for(int j = 0; j < 4; j++) {
      int ny = y1 + vy[j], nx = x1 + vx[j];
      if(ny == y2 && nx == x2) match = true;
    }
    if(!match) {
      cout << "NO" << endl;
      return (0);
    }
  }

  cout << "YES" << endl;
  cout << LIM << " " << w << endl;
}