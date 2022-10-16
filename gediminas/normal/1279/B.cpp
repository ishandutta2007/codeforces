// Example program
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t --> 0){
      long long n, s;
      cin >> n >> s;
      long long sum = 0;
      vector<long long> a(n);
      for(auto &&i :a) {
          cin >> i;
          sum += i;
      }
      if(sum <= s){
          cout << "0\n";
          continue;
      }
      int kur = 0;
      sum = 0;
      for(int i = 0; i < n; i++) {
          sum += a[i];
          if(sum - max(a[kur],a[i]) > s)
            break;
          if(a[kur] < a[i]) {
              kur = i;
          }
      }
      cout << kur + 1 << "\n";
  }
}