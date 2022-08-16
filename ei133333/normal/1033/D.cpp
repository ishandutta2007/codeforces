#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

int main() {

  int N;
  int64 A[500];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto check4 = [&](int64 v) {
    int64 ok = 0, ng = 40000;
    while(ng - ok > 1) {
      int64 mid = (ok + ng) / 2;
      if(mid * mid * mid * mid <= v) ok = mid;
      else ng = mid;
    }
    return ok * ok * ok * ok == v ? ok : -1;
  };

  auto check3 = [&](int64 v) {
    int64 ok = 0, ng = 1300000;
    while(ng - ok > 1) {
      int64 mid = (ok + ng) / 2;
      if(mid * mid * mid <= v) ok = mid;
      else ng = mid;
    }
    return ok * ok * ok == v ? ok : -1;
  };

  auto check2 = [&](int64 v) {
    int64 ok = 0, ng = 1500000000;
    while(ng - ok > 1) {
      int64 mid = (ok + ng) / 2;
      if(mid * mid <= v) ok = mid;
      else ng = mid;
    }
    return ok * ok == v ? ok : -1;
  };

  vector< int64 > primes;
  map< int64, int > ask;

  map< int64, int > mp;

  for(int i = 0; i < N; i++) {
    auto ret = check4(A[i]);
    if(~ret) {
      primes.emplace_back(ret);
      mp[ret] += 4;
      continue;
    }
    ret = check3(A[i]);
    if(~ret) {
      primes.emplace_back(ret);
      mp[ret] += 3;
      continue;
    }
    ret = check2(A[i]);
    if(~ret) {
      primes.emplace_back(ret);
      mp[ret] += 2;
      continue;
    }
    ask[A[i]]++;
  }
  for(auto &p : ask) {
    for(auto &q : ask) {
      if(p == q) continue;
      auto it = __gcd(p.first, q.first);
      if(it != 1) primes.emplace_back(it);
    }
  }
  sort(begin(primes), end(primes));
  primes.erase(unique(begin(primes), end(primes)), end(primes));

  int ptr = 4;
  for(auto &p : ask) {
    bool luz = false;
    for(auto &prime : primes) {
      if(p.first % prime == 0) {
        mp[p.first / prime] += p.second;
        mp[prime] += p.second;
        luz = true;
        break;
      }
    }
    if(!luz) {
      mp[ptr] += p.second;
      ptr += 2;
      mp[ptr] += p.second;
      ptr += 2;
    }
  }

  int64 mul = 1;
  for(auto &p : mp) (mul *= (p.second + 1)) %= mod;
  cout << mul << endl;
}