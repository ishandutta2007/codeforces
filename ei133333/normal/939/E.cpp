#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main()
{
  int Q;
  scanf("%d", &Q);
  vector< int > ret;
  int64 sum = 0, ptr = 0;
  int64 ans = 0, anssz = 0, lastX = 0;

  while(Q--) {
    int T;
    scanf("%d", &T);
    if(T == 1) {
      int X;
      scanf("%d", &X);
      lastX = X;
      ans = (sum + X);
      anssz = ptr + 1;
      while(ptr < ret.size() && (sum + ret[ptr] + X) * anssz <= ans * (ptr + 2)) {
        sum += ret[ptr++];
        ans = sum + X;
        anssz = ptr + 1;
      }

      ret.push_back(X);
    } else {
      printf("%.12lf\n", lastX - 1.0*ans/anssz);
    }
  }
}