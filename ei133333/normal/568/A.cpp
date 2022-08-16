#include <bits/stdc++.h>

using namespace std;


const int MAX = 1179858;


bool prime[MAX + 1];

int main()
{
  int P, Q;
  cin >> P >> Q;

  prime[1] = true;
  for(int i = 2; i <= MAX; i++) {
    if(!prime[i]) {
      for(int j = i + i; j <= MAX; j += i) prime[j] = true;
    }
  }

  int latte = 0, malta = 0;
  int beet = 0;
  for(int i = 1; i <= MAX; i++) {
    latte += prime[i] ^ 1;
    string q = to_string(i), p = q;
    reverse(begin(q), end(q));
    malta += p == q;
    if(latte * Q <= malta * P) beet = i;
  }

  if(beet == 0) cout << "Palindromic tree is better than splay tree" << endl;
  else cout << beet << endl;

}