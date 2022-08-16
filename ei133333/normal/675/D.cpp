#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 N, A[100000];
  pair< int, int > tree[100001];
  vector< int > nums;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    nums.push_back(A[i]);
  }
  sort(nums.begin(), nums.end());
  for(int i = 0; i < N; i++) {
    A[i] = lower_bound(nums.begin(), nums.end(), A[i]) - nums.begin();
  }

  set< int > val;
  fill_n(tree, N, make_pair(-1, -1));
  val.insert(A[0]);
  for(int i = 1; i < N; i++) {
    auto p = val.lower_bound(A[i]);
    if(p != val.end() && tree[*p].first == -1) {
      tree[*p].first = A[i];
      cout << nums[*p] << " ";
    } else {
      --p;
      tree[*p].second = A[i];
      cout << nums[*p] << " ";
    }
    val.insert(A[i]); 
  }
}