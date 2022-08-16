#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int INF = 1 << 30;

int main()
{
  int N, M, A[100000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  int ptr = 0;

  bool first = false;
  vector< int > nums;

  for(int i = 1; M - i >= 0; i++) {
    if(ptr < N && A[ptr] == i) {
      ++ptr;
      continue;
    }
    M -= i;
    nums.push_back(i);
  }
  cout << nums.size() << endl;
  for(int i = 0; i < nums.size(); i++) {
    if(first++) cout << " ";
    cout << nums[i];
  }
  cout << endl;
}