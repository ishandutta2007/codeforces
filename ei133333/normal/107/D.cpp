#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int mod = 12345;


struct Matrix
{
  int a[123][123];

  Matrix operator+(const Matrix &kj)
  {
    Matrix ret;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        ret.a[i][j] = a[i][j] + kj.a[i][j];
        ret.a[i][j] %= mod;
      }
    }
    return (ret);
  }

  Matrix operator*(const Matrix &kj)
  {
    Matrix ret = Matrix::Zero();
    for(int i = 0; i < 123; i++) {
      for(int j = 0; j < 123; j++) {
        for(int k = 0; k < 123; k++) {
          ret.a[i][j] = (ret.a[i][j] + 1LL * a[i][k] * kj.a[k][j]) % mod;
        }
      }
    }
    return (ret);
  }

  Matrix operator^(int64 n)
  {
    Matrix ret = Matrix::I();
    Matrix x = *this;
    while(n > 0) {
      if(n & 1LL) (ret = ret * x);
      x = x * x;
      n >>= 1LL;
    }
    return (ret);
  }

  static Matrix Zero()
  {
    Matrix ret;
    memset(ret.a, 0, sizeof(ret.a));
    return (ret);
  }

  static Matrix I()
  {
    Matrix ret;
    memset(ret.a, 0, sizeof(ret.a));
    for(int i = 0; i < 123; i++) ret.a[i][i] = 1;
    return (ret);
  }
};


int64 N;
int C;
vector< int > beet[26];
int lcm[26], all = 1;
vector< int > nums;

bool LatteMalta(int i)
{
  vector< int > t(26);
  int curr = i;
  for(int j : nums) {
    if(lcm[j] > 0) {
      t[j] = curr % lcm[j];
      curr /= lcm[j];
    }
  }
  for(int j : nums) {
    bool flag = false;
    for(int k : beet[j]) if(t[j] % k == 0) flag = 1;
    if(!flag) return (false);

  }
  return (true);
}


int main()
{
  cin >> N >> C;

  for(int i = 0; i < C; i++) {
    char T;
    int K;
    cin >> T >> K;
    beet[T - 'A'].push_back(K);
  }

  for(int i = 0; i < 26; i++) {
    if(!beet[i].empty()) nums.push_back(i);
  }

  for(int i : nums) {
    lcm[i] = 1;
    for(int j : beet[i]) lcm[i] = lcm[i] / __gcd(lcm[i], j) * j;
    all *= lcm[i];
  }


  Matrix mat = Matrix::Zero();

  for(int i = 0; i < all; i++) {
    vector< int > t(26);
    int curr = i;
    for(int j : nums) {
      t[j] = curr % lcm[j];
      curr /= lcm[j];
    }
    for(int j : nums) {
      t[j] = (t[j] + 1) % lcm[j];
      int val = 0;
      for(int k = 25; k >= 0; k--) {
        if(lcm[k] > 0) val = val * lcm[k] + t[k];
      }
      ++mat.a[i][val];
      t[j] = (t[j] + lcm[j] - 1) % lcm[j];
    }
  }

  mat = mat ^ N;
  int ret = 0;
  for(int i = 0; i < all; i++) {
    if(LatteMalta(i)) ret += mat.a[i][0];
  }
  cout << ret % mod << endl;
}