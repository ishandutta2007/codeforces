#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100000], B[100000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];
  sort(A, A + N);
  sort(B, B + N);

  // 
  int64 ret = 0, latte = N - 1, malta = N - 1;
  for(int i = 0; i < N; i++) {
    if(latte >= 0 && malta >= 0) {
      if(A[latte] > B[malta]) ret += A[latte--];
      else malta--;
    } else if(latte >= 0) {
      ret += A[latte--];
    } else {
      malta--;
    }


    if(latte >= 0 && malta >= 0) {
      if(A[latte] < B[malta]) ret -= B[malta--];
      else latte--;
    } else if(malta >= 0) {
      ret -= B[malta--];
    } else {
      latte--;
    }
  }

  cout << ret << endl;
}