#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, K, M, A, sum[100] = {}, last[100];
  for(int i = 0; i < 100; i++) last[i] = -1;

  cin >> N >> K >> M >> A;
  for(int i = 0; i < A; i++) {
    int x;
    cin >> x;
    --x;
    ++sum[x];
    last[x] = max(last[x], i);
  }

  // mazi ?
  if(N == 1) {
    cout << 1 << endl;
    return (0);
  }


  const int rest = M - A;

  auto check1 = [&](int idx) // sum[idx] != 0
  {
    if(sum[idx] == 0) return (false);
    if(N == K) return (true);

    // e-nn
    vector< int > a, b, c;
    for(int i = 0; i < N; i++) {
      if(i != idx) {
        a.push_back(sum[i]);
        b.push_back(last[i]);
        c.push_back(0);
      }
    }
    int curr = 114514;

    auto dame = [&](int s)
    {
      if(sum[idx] != a[s]) return(sum[idx] > a[s]);
      assert(sum[idx] != -1);
      return(last[idx] < b[s]);
    };

    for(int i = 0; i < N - 1; i++) {
      while(dame(i)) {
        a[i]++;
        b[i] = curr++;
        c[i]++;
      }
    }
    sort(begin(c), end(c));
    int cost = 0;
    for(int i = 0; i < K; i++) {
      cost += c[i];
    }
    return (cost > rest);
  };

  auto check3 = [&](int idx)
  {
    if(last[idx] == -1 && rest == 0) return (true);
    vector< pair< int, int > > st;
    for(int i = 0; i < N; i++) {
      if(idx != i) {
        if(last[i] == -1) continue;
        st.emplace_back(sum[i], last[i]);
      }
    }
    int rank = 1;
    for(auto &p : st) {
      rank += make_pair(sum[idx] + rest, -M) < make_pair(p.first, -p.second);
    }
    return (rank > K);
  };

  vector< int > decide(N, 0);
  for(int i = 0; i < N; i++) {
    if(sum[i] == -1) continue;
    if(check1(i)) decide[i] = 1;
  }

  for(int i = 0; i < N; i++) {
    if(decide[i] == 1) continue;
    if(check3(i)) decide[i] = 3;
  }

  for(int i = 0; i < N; i++) {
    if(decide[i] == 0) decide[i] = 2;
    cout << decide[i] << " ";
  }
  cout << endl;

}