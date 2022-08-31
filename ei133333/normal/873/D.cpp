#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int S[100000], ptr = 1;

void rec(int left, int right, int &k)
{
  if(left + 1 == right) {
    S[left] = ptr++;
  } else if(k >= 2) {
    --k, --k;
    rec((left + right) >> 1, right, k);
    rec(left, (left + right) >> 1, k);
  } else {
    for(int i = left; i < right; i++) S[i] = ptr++;
  }
}

int main()
{
  int N, K;
  cin >> N >> K;
  --K;
  rec(0, N, K);

  if(K != 0) {
    cout << -1 << endl;
  } else {
    for(int i = 0; i < N; i++) {
      cout << S[i] << " ";
    }
    cout << endl;
  }
}