#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

struct BinaryIndexedTree
{
  vector< int64 > bit;
  BinaryIndexedTree(int sz)
  {
    bit.assign(++sz, 0);
  }
  int64 RangeMaximumQuery(int k)
  {
    int64 ret = 0;
    for(++k; k > 0; k -= k & -k) ret = max(ret, bit[k]);
    return(ret);
  }
  void Update(int k, int64 x)
  {
    for(++k; k < bit.size(); k += k & -k) bit[k] = max(bit[k], x);
  }
};


int main()
{
  // dp[i]: dp[j] + v[i] (v[j]<v[i])

  int N, R[100000], H[100000];

  cin >> N;
  vector< int64 > area;
  for(int i = 0; i < N; i++) {
    cin >> R[i] >> H[i];
    area.push_back(1LL * R[i] * R[i] * H[i]);
  }
  sort(area.begin(), area.end());
  area.erase(unique(area.begin(), area.end()), area.end());
  BinaryIndexedTree tree(area.size());
  for(int i = 0; i < N; i++) {
    int pos = lower_bound(area.begin(), area.end(), 1LL * R[i] * R[i] * H[i]) - area.begin();
    tree.Update(pos, tree.RangeMaximumQuery(pos - 1) + 1LL * R[i] * R[i] * H[i]);
  }
  cout << fixed << setprecision(10) << tree.RangeMaximumQuery(area.size() - 1) * acos(-1.0) << endl;
}