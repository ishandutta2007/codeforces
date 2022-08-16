#include<bits/stdc++.h>
using namespace std;
typedef long long int64;


int main()
{
  int N, M, A[200005];
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  //  sort 
  int Reach = 0, T[200005], L[200005] = {};
  for(int i = 1; i <= M; i++) {
    int R;
    cin >> T[i] >> R;
    Reach = max(Reach, R);
    L[R - 1] = i;
  }
  for(int i = N - 2; i >= 0; i--) {
    L[i] = max(L[i], L[i + 1]);
  }

  int ptr = 0;
  int Array[200005];

  multiset< int > used;
  for(int i = N - 1; i >= Reach; i--) {
    Array[i] = A[i];
  }
  for(int i = 0; i < Reach; i++) {
    used.insert(A[i]);
  }
  for(int i = Reach - 1; i >= 0; i--) {
    if(T[L[i]] == 2) {
      Array[i] = *used.begin();
      used.erase(used.begin());
    } else {
      Array[i] = *--used.end();
      used.erase(--used.end());
    }
  }

  for(int i = 0; i < N; i++) {
    if(i > 0) cout << " ";
    cout << Array[i];
  }
  cout << endl;
}