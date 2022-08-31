#include <bits/stdc++.h>

using namespace std;

int main()
{
  int Q;

  scanf("%d", &Q);

  multiset< int > sets;
  sets.insert(0);

  for(int i = 0; i < Q; i++) {
    char c;
    int val;
    scanf(" %c %d", &c, &val);
    if(c == '+') sets.insert(val);
    else if(c == '-') sets.erase(sets.find(val));
    else if(c == '?') {
      int now = 0;
      for(int i = 29; i >= 0; i--) {
        int low = now;
        int mid = now | (1 << i);
        int high = now + (1 << (i + 1));
        if((val >> i) & 1) {
          auto p = sets.lower_bound(low);
          auto q = sets.lower_bound(mid);
          if(p != q) now = low;
          else now = mid;
        } else {
          auto q = sets.lower_bound(mid);
          auto r = sets.lower_bound(high);
          if(q != r) now = mid;
          else now = low;
        }
      }
      printf("%d\n", now ^ val);
    }
  }
}