#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

const int nax = 1e5 + 5;
vector<int> divisors[nax];

ll two(ll n) { return n * (n + 1) / 2; }
ll three(ll n) { return n * (n + 1) * (n + 2) / 6; }

void test_case() {
  ll a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);
  ll ab = __gcd(a, b);
  ll bc = __gcd(b, c);
  ll ac = __gcd(a, c);
  ll abc = __gcd(ab, c);
  a = divisors[a].size();
  b = divisors[b].size();
  c = divisors[c].size();
  ab = divisors[ab].size();
  ac = divisors[ac].size();
  bc = divisors[bc].size();
  abc = divisors[abc].size();
  ab -= abc;
  ac -= abc;
  bc -= abc;
  a -= ab + ac + abc;
  b -= ab + bc + abc;
  c -= ac + bc + abc;
  debug() << imie(a) imie(b) imie(c) imie(ab) imie(ac) imie(bc) imie(abc);
  ll answer = 0;
  // a
  answer += a * ((b + ab) * (c + ac + bc + abc) + bc * (c + ac + abc) + abc * (c + ac + 0) +
    two(bc) + two(abc));
  debug() << imie(answer);
  // ab
  answer += ab * ((b + 0) * (c + ac + bc + abc) + bc * (c + ac + abc) + abc * (c + ac + 0) +
    two(bc) + two(abc));
  answer += two(ab) * (c + ac + bc + abc);
  debug() << imie(answer);
  // ac
  answer += ac * ab * c + two(ac) * ab; // b as 'ab' ok
  answer += ac * b * (c + bc); // b as 'b' ok
  answer += ac * bc * (c + abc) + two(ac) * bc + two(bc) * ac; // b as 'bc' ok
  answer += ac * abc * (c + 0 + b) + ac * two(abc) + two(ac) * (abc + b);
  //~ answer += ac * ((b + ab) * (c + 0 + bc + abc) + bc * (c + 0 + abc) + abc * (c + 0 + 0) +
    //~ two(bc) + two(abc));
  //~ answer += two(ac) * (b + ab + bc + abc);
  debug() << imie(answer);
  answer += abc * b * (c + bc) + abc * bc * c + two(abc) * b;
  answer += two(bc) * abc + two(abc) * bc;
  answer += two(abc) * (c);
  answer += three(abc);
  // abc
  //~ ab = ac = 0;
  //~ answer += abc * ((b + ab) * (c + ac + bc + 0) + bc * (c + ac + 0) + abc * (c + ac + 0) +
    //~ two(bc) + two(0));
  //~ answer += two(abc) * (b + ab + bc + c + ac + 0);
  //~ answer += three(abc);
  printf("%lld\n", answer);
}

int main() {
  for(int i = 1; i < nax; ++i)
    for(int j = i; j < nax; j += i)
      divisors[j].push_back(i);
  int T;
  scanf("%d", &T);
  while(T--) test_case();
}