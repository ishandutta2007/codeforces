#include<bits/stdc++.h>

using namespace std;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return(false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return(true);
  }

  int find(int k)
  {
    if(data[k] < 0) return(k);
    return(data[k] = find(data[k]));
  }

  int size(int k)
  {
    return(-data[find(k)]);
  }
};

int main()
{
  bool not_prime[1001] = {};
  not_prime[0] = not_prime[1] = true;
  vector< int > primes;
  for(int i = 2; i <= 1000; i++) {
    if(not_prime[i]) continue;
    for(int j = i + i; j <= 1000; j += i) {
      not_prime[j] = true;
    }
    primes.push_back(i);
  }

  string S;
  cin >> S;

  if(S.size() == 1) {
    cout << "YES" << endl;
    cout << S << endl;
    return(0);
  }

  UnionFind uf(S.size());
  for(auto& p : primes) {
    for(int i = p + p; i <= S.size(); i += p) {

      uf.unite(i - p - 1, i - 1);
    }
  }


  int sum[26] = {};
  for(auto& c : S) sum[c - 'a']++;

  int large = 0;
  for(int i = 0; i < 26; i++) {
    if(sum[large] < sum[i]) {
      large = i;
    }
  }


  if(sum[large] < uf.size(1)) {
    cout << "NO" << endl;
    return(0);
  }

  cout << "YES" << endl;
  for(int i = 0; i < S.size(); i++) {
    if(uf.find(i) == uf.find(1)) {
      S[i] = (char)(large + 'a');
      --sum[large];
    }
  }

  for(int i = 0; i < S.size(); i++) {
    if(uf.find(i) != uf.find(1)) {
      for(int j = 0; j < 26; j++) {
        if(sum[j] > 0) {
          S[i] = (char)(j + 'a');
          --sum[j];
          break;
        }
      }
    }
  }

  cout << S << endl;

}