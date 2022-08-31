#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename T >
struct LimitInt
{
  T x;
  const T low, high;

  LimitInt() : x(0), low(numeric_limits< T >::min() + 10), high(numeric_limits< T >::max() - 10) {}

  LimitInt(const T &x) : x(x), low(numeric_limits< T >::min() + 10), high(numeric_limits< T >::max() - 10) {}

  LimitInt &operator+=(const LimitInt &y)
  {
    x = (double) x + y.x > high ? high : x + y.x;
    return (*this);
  }

  LimitInt &operator-=(const LimitInt &y)
  {
    x = (double) x - y.x < low ? low : x - y.x;
    return (*this);
  }

  LimitInt &operator*=(const LimitInt &y)
  {
    x = (double) x * y.x > high ? high : x * y.x;
    return (*this);
  }

  LimitInt &operator/=(const LimitInt &y)
  {
    x /= y.x;
    return (*this);
  }

  LimitInt operator-() const
  {
    return -x;
  }

  LimitInt operator+(const LimitInt &y) const
  {
    LimitInt ret(x);
    ret += y;
    return ret;
  }

  LimitInt operator-(const LimitInt &y) const
  {
    LimitInt ret(x);
    ret -= y;
    return ret;
  }

  LimitInt operator*(const LimitInt &y) const
  {
    LimitInt ret(x);
    ret *= y;
    return ret;
  }

  LimitInt operator/(const LimitInt &y) const
  {
    LimitInt ret(*this);
    ret /= y;
    return ret;
  }

  LimitInt operator==(const LimitInt &y) const
  {
    return (x == y.x);
  }

  LimitInt operator!=(const LimitInt &y) const
  {
    return (x != y.x);
  }

  LimitInt operator<(const LimitInt &y) const
  {
    return (x < y.x);
  }

  LimitInt operator>(const LimitInt &y) const
  {
    return (x > y.x);
  }

  LimitInt operator<=(const LimitInt &y) const
  {
    return (x <= y.x);
  }

  LimitInt operator>=(const LimitInt &y) const
  {
    return (x >= y.x);
  }

  T get() const
  {
    return (x);
  }
};


const string F0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string Fn_first = "What are you doing while sending \"";
const string Fn_second = "\"? Are you busy? Will you send \"";
const string Fn_last = "\"?";

int64 dp[100001];

int64 sz(int n)
{
  if(~dp[n]) return (dp[n]);
  if(n == 0) return (dp[0] = F0.size());
  LimitInt< int64 > ret;
  ret += Fn_first.size();
  ret += Fn_second.size();
  ret += Fn_last.size();
  ret += sz(n - 1);
  ret += sz(n - 1);
  return (dp[n] = ret.get());
}

char F(int n, int64 &pos)
{
  if(pos >= dp[n]) {
    pos -= dp[n];
    return ('.');
  }
  if(n == 0) return (F0[pos]);
  if(pos < Fn_first.size()) return (Fn_first[pos]);
  pos -= Fn_first.size();
  char c = F(n - 1, pos);
  if(c != '.') return (c);
  if(pos < Fn_second.size()) return (Fn_second[pos]);
  pos -= Fn_second.size();
  c = F(n - 1, pos);
  if(c != '.') return (c);
  if(pos < Fn_last.size()) return (Fn_last[pos]);
  pos -= Fn_last.size();
  return ('.');
}

int main()
{
  int Q;
  cin >> Q;
  memset(dp, -1, sizeof(dp));
  sz(100000);
  for(int i = 0; i < Q; i++) {
    int64 N, K;
    cin >> N >> K;
    --K;
    cout << F(N, K);
  }
  cout << endl;
}