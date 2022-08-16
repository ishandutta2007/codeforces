#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int Q;

  cin >> Q;
  map< int, int > memo;memo[1]=0;
  memo[3]=1;
  memo[7]=1;
  memo[15]=5;
  memo[31]=1;
  memo[63]=21;
  memo[127]=1;
  memo[255]=85;
  memo[511]=73;
  memo[1023]=341;
  memo[2047]=89;
  memo[4095]=1365;
  memo[8191]=1;
  memo[16383]=5461;
  memo[32767]=4681;
  memo[65535]=21845;
  memo[131071]=1;
  memo[262143]=87381;
  memo[524287]=1;
  memo[1048575]=349525;
  memo[2097151]=299593;
  memo[4194303]=1398101;
  memo[8388607]=178481;
  memo[16777215]=5592405;
  memo[33554431]=1082401;
  memo[67108863]=22369621;

  while(Q--) {

    int a;
    cin >> a;


    int high = 0;
    for(int k = 0; k < 30; k++) {
      if((a >> k) & 1) high = k;
    }
    if(__builtin_popcount(a) == high + 1) {
      if(!memo.count(a)) {
        int large = 0;
        for(int b = 1; b < a; b++) {
          large = max(large, __gcd(a ^ b, a & b));
        }
        memo[a] = large;
      }
      cout << memo[a] << endl;
    } else {
      cout << (1 << (high + 1)) - 1 << endl;
    }
  }
}