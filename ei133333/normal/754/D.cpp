#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

struct BinaryIndexedTree
{
  vector< int > data;

  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }

  int sum(int k)
  {
    int ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, int x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int64 N, K, L[300000], R[300000];
vector< int64 > nums;
vector< int64 > curr;

vector< int > rr; // 


void output(int64 length)
{
  int eix = 0, lbx = -1;
  BinaryIndexedTree bit1(nums.size() + 1);

  for(int i = 0; i < N; i++) bit1.add(L[i], +1);

  for(int64 start : curr) {
    int64 sub = start - length + 1;
    while(eix < rr.size() && R[rr[eix]] < start) {
      bit1.add(L[rr[eix++]], -1);
    }
    while(lbx + 1 < nums.size() && nums[lbx + 1] <= sub)
      lbx++;

    if(bit1.sum(lbx) >= K) {
      for(int i = 0; i < N; i++) {
        if(K > 0 && nums[L[i]] <= sub && start <= R[i]) {
          --K;
          cout << i + 1 << " ";
        }
      }
      cout << endl;
      return;
    }
  }
}

bool calc(int64 length)
{
  int eix = 0, lbx = -1;
  BinaryIndexedTree bit1(nums.size() + 1);
  for(int i = 0; i < N; i++) bit1.add(L[i], +1);
  for(int64 start : curr) {
    int64 sub = start - length + 1;
    while(eix < rr.size() && R[rr[eix]] < start) {
      bit1.add(L[rr[eix++]], -1);
    }
    while(lbx + 1 < nums.size() && nums[lbx + 1] <= sub)
      lbx++;
    if(bit1.sum(lbx) >= K) return(true);
  }
  return (false);
}


int main()
{
  scanf("%lld %lld", &N, &K);
  for(int i = 0; i < N; i++) {
    scanf("%lld %lld", &L[i], &R[i]);
    nums.push_back(L[i]);
    curr.push_back(R[i]);
  }

  sort(begin(nums), end(nums));
  nums.erase(unique(begin(nums), end(nums)), end(nums));

  rr.resize(N);
  iota(begin(rr), end(rr), 0);
  sort(begin(rr), end(rr), [&](int &x, int &y)
  {
    return (R[x] < R[y]);
  });
  for(int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(nums), end(nums), L[i]) - begin(nums);
  }
  
  sort(begin(curr), end(curr));
  curr.erase(unique(begin(curr), end(curr)), end(curr));


  if(!calc(1)) {
    cout << 0 << endl;
    for(int i = 0; i < K; i++) {
      cout << i + 1 << " ";
    }
    cout << endl;
    return(0);
  }


  int64 low = 0, high = 1LL << 33;
  while(high - low > 0) {
    int64 mid = (low + high + 1) >> 1;
    if(calc(mid)) low = mid;
    else high = mid - 1;
  }

  printf("%lld\n", low);
  output(low);

}