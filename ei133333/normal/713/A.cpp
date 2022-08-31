#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int sz[1 << 20];

int main()
{
  int T;

  cin >> T;
  while(T--) {
    char t;
    int64 S;

    cin >> t >> S;

    int bit = 0;
    for(int i = 0; i < 20; i++) {
      bit |= (S % 2) << i;
      S /= 10;
    }

    if(t == '+') ++sz[bit];
    else if(t == '-') --sz[bit];
    else cout << sz[bit] << endl;
  }
}