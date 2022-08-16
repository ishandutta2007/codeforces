#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 N, A[200000], M, B[200000], C[200000];
map< int, int > people;

int main()
{
 
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    people[A[i]]++;
  }
  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> B[i];
  }
  for(int i = 0; i < M; i++) {
    cin >> C[i];
  }
  
  pair< pair< int, int >, int > ret = {{0, 0}, 1};
  for(int i = 0; i < M; i++) {
    ret = max(ret, {{people[B[i]], people[C[i]]}, i + 1});
  }
  cout << ret.second << endl;
}